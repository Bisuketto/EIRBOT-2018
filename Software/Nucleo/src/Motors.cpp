#include "Motors.hpp"

Motors::Motors(PinName _pwmL, PinName _pwmR, PinName _dirL, PinName _dirR) {
	RSQR = false;
	ROT = false;

	debug = false;
	schedule_routine = new Ticker();
	schedule_infos = new Ticker();
	t_cmd = new Timer();
	t_cmd->start();
	right_motor = new PwmOut(_pwmR);
	left_motor = new PwmOut(_pwmL);
	dir_left = new DigitalOut(_dirL);
	dir_right = new DigitalOut(_dirR);

	p0[0] = 0.;
	p0[1] = 0.;
}

Motors::Motors(PinName _pwmL, PinName _pwmR, PinName _dirL, PinName _dirR, Serial* _debug) {
	RSQR = false;
	ROT = false;

	debug = true;
	serialOut = _debug;
	schedule_routine = new Ticker();
	schedule_infos = new Ticker();
	t_cmd = new Timer();
	t_cmd->start();

	/*wait(1);
	Timer* test = new Timer();
	RSQR = true;
	test->start();

	for (int i = 0; i < 10000; i++) {
		routine();
	}

	float temps = test->read_us();
	serialOut->printf("Routine speed : %f µs\n", temps/10000);
	RSQR = false;
	hard_stop();*/
	

	right_motor = new PwmOut(_pwmR);
	right_motor->period_us(25);
	left_motor = new PwmOut(_pwmL);
	left_motor->period_us(25);
	dir_left = new DigitalOut(_dirL);
	dir_right = new DigitalOut(_dirR);

	serialOut->printf("Motor test\n");
	dir_right->write(1);
	right_motor->write(0.25);
	wait(0.5);
	right_motor->write(0);
	dir_left->write(0);
	left_motor->write(0.25);
	wait(0.5);
	left_motor->write(0);
	wait(0.5);
	dir_right->write(0);
	right_motor->write(0.25);
	wait(0.5);
	right_motor->write(0);
	dir_left->write(1);
	left_motor->write(0.25);
	wait(0.5);
	left_motor->write(0);
	wait(1);

	p0[0] = 0.;
	p0[1] = 0.;
}

Motors::~Motors() {

}

void Motors::routine() {
	static float XCoeffs_pos[TAILLE_TABLEAUX_POS] = XCOEFFS_POS;
	static float YCoeffs_pos[TAILLE_TABLEAUX_POS] = YCOEFFS_POS;
	static float XCoeffs_ang[TAILLE_TABLEAUX_ANG] = XCOEFFS_ANG;
	static float YCoeffs_ang[TAILLE_TABLEAUX_ANG] = YCOEFFS_ANG;

	calc_pos_inter();
	
	float epsilon_pos;
	float epsilon_ang;

	if (RSQR) {
		float Dx = xi - instEncoders->getX();
		float Dy = yi - instEncoders->getY();
		float theta_act = instEncoders->getTheta();
		epsilon_pos = sqrt(Dx*Dx + Dy*Dy); // mm
		int A = (Dx > 0) ? -1 : 1;
		epsilon_ang = (Dy > 0) ? (A*atan(fabs(Dx) / fabs(Dy)) - theta_act) : (A*PI - A*atan(fabs(Dx) / fabs(Dy)) - theta_act); //rad
	}
	else if (ROT) {
		float Dx = x_init - instEncoders->getX();
		float Dy = y_init - instEncoders->getY();
		float theta_act = instEncoders->getTheta();
		epsilon_pos = sqrt(Dx*Dx + Dy*Dy);
		epsilon_ang = theta_i - theta_act;
	}

	float vitesse = 0;
	tab_push(epsilon_pos, pos_err, TAILLE_TABLEAUX_POS);
	for (int i = 1; i < TAILLE_TABLEAUX_POS; i++) {
		vitesse += XCoeffs_pos[i] * pos_err[i-1];
		vitesse -= YCoeffs_pos[i] * pos_cmd[i-1];
	}
	tab_push(vitesse, pos_cmd, TAILLE_TABLEAUX_POS);

	float vitesse_ang = 0;
	tab_push(epsilon_ang, ang_err, TAILLE_TABLEAUX_ANG);
	for (int i = 1; i < TAILLE_TABLEAUX_ANG; i++) {
		vitesse_ang += XCoeffs_ang[i] * ang_err[i-1];
		vitesse_ang -= YCoeffs_ang[i] * ang_cmd[i-1];
	}
	tab_push(vitesse_ang, ang_cmd, TAILLE_TABLEAUX_ANG);

	float right_cmd = vitesse + vitesse_ang;
	float left_cmd = vitesse - vitesse_ang;

	to_H_bridgeable(&right_cmd, &left_cmd);

	right_motor->write(right_cmd);
	left_motor->write(left_cmd);

	dead_zone();
}

void Motors::go_to_RSQR(float _x, float _y) {
	RSQR = true;
	x_init = instEncoders->getX();
	y_init = instEncoders->getY();

	if (debug)
		serialOut->printf("Going to (%f;%f) from (%f;%f)\n", _x, _y, x_init, y_init);

	schedule_routine->detach();
	reset_data();

	x_reference = _x;
	y_reference = _y;

	float Dx = x_reference - x_init;
	float Dy = y_reference - y_init;
	pos_reference = sqrt(Dx*Dx + Dy*Dy);

	t_cmd->reset();
	if (debug)
		serialOut->printf("Starting control routine\n");
	schedule_routine->attach(callback(this, &Motors::routine), TECH);
	if (debug)
		serialOut->printf("Starting info routine\n");
	schedule_infos->attach(callback(this, &Motors::send_i), 1.000);
	serialOut->attach(callback(this, &Motors::comStop));
	status = true;
}

void Motors::rotate(float _ang) {
	ROT = true;

	if (debug)
		serialOut->printf("Rotating to %f rads\n", _ang);

	schedule_routine->detach();
	reset_data();

	x_init = instEncoders->getX();
	y_init = instEncoders->getY();
	ang_reference = _ang - instEncoders->getTheta();

	t_cmd->reset();
	schedule_routine->attach(callback(this, &Motors::routine), TECH);
	status = true;
}

void Motors::tab_push(float _x, float* _tab, int _l) {
	for (int i = 0; i < _l - 1; i++) {
		_tab[_l - i - 1] = _tab[_l - i - 2];
	}
	_tab[0] = _x;
}

void Motors::tab_push(float* _p, float** _tab, int _l) {
	//delete [] _tab[_l - 1];
	float temp[DIM_PT] = {_p[0], _p[1]};
	for (int i = 0; i < _l - 1; i++) {
		_tab[_l - i - 1] = _tab[_l - i - 2];
	}
	_tab[0] = temp;
}

void Motors::tab_init(float* _tab, int _l) {
	for (int i = 0; i < _l; i++) {
		tab_push(0., _tab, _l);
	}
}

void Motors::tab_init(float** _tab, int _l) {
	for (int i = 0; i < _l; i++) {
		tab_push(p0, _tab, _l);
	}
}

void Motors::reset_data() {
	tab_init(pos_cmd, TAILLE_TABLEAUX_POS);
	tab_init(pos_err, TAILLE_TABLEAUX_POS);
	tab_init(ang_cmd, TAILLE_TABLEAUX_ANG);
	tab_init(ang_err, TAILLE_TABLEAUX_ANG);
	tab_init(director, DIR_LENGTH);
}

float Motors::pos_reference_calculation_RSQR() {
	float t = t_cmd->read_us()*0.000001;
	float acceleration = ACCELERATION_POS;
	float vmax = VITESSEMAX_POS;

	if (pos_reference < 0) {
		acceleration *= -1;
		vmax *= -1;
	}

	float omega = pos_reference / vmax + vmax / acceleration;
	float alpha = vmax / acceleration;
	float beta = omega - vmax / acceleration;
	float gamma;

	if (alpha < beta) {
		if (t < alpha) {
			return 0.5*acceleration*t*t;
		}
		else if (t < beta) {
			return 0.5*acceleration*alpha*alpha + vmax*(t - alpha);
		}
		else if (t < omega) {
			return 0.5*acceleration*alpha*alpha + vmax*(beta - alpha) + vmax*(t - beta) - 0.5*acceleration*(t - beta)*(t - beta);
		}
		else {
			return pos_reference;
		}
	}
	else {
		omega = 2 * sqrt(pos_reference / acceleration);
		gamma = omega / 2;
		if (t < gamma) {
			return 0.5*acceleration*t*t;
		}
		else if (t < omega) {
			return 0.5*acceleration*gamma*gamma + (acceleration*gamma)*(t - gamma) - 0.5*acceleration*(t - gamma)*(t - gamma);
		}
		else {
			return pos_reference;
		}
	}
	return 0;
}

float Motors::ang_reference_calculation() {
	float t = t_cmd->read_us()*0.000001;
	float acceleration = ACCELERATION_ANG;
	float vmax = VITESSEMAX_ANG;

	if (ang_reference < 0) {
		acceleration *= -1;
		vmax *= -1;
	}

	float omega = ang_reference / vmax + vmax / acceleration;
	float alpha = vmax / acceleration;
	float beta = omega - vmax / acceleration;
	float gamma;

	if (alpha < beta) {
		if (t < alpha) {
			return 0.5*acceleration*t*t;
		}
		else if (t < beta) {
			return 0.5*acceleration*alpha*alpha + vmax*(t - alpha);
		}
		else if (t < omega) {
			return 0.5*acceleration*alpha*alpha + vmax*(beta - alpha) + vmax*(t - beta) - 0.5*acceleration*(t - beta)*(t - beta);
		}
		else {
			return ang_reference;
		}
	}
	else {
		omega = 2 * sqrt(ang_reference / acceleration);
		gamma = omega / 2;
		if (t < gamma) {
			return 0.5*acceleration*t*t;
		}
		else if (t < omega) {
			return 0.5*acceleration*gamma*gamma + (acceleration*gamma)*(t - gamma) - 0.5*acceleration*(t - gamma)*(t - gamma);
		}
		else {
			return ang_reference;
		}
	}
	return 0;
}

void Motors::calc_pos_inter() {
	if (RSQR) {
		float factor = pos_reference_calculation_RSQR() / pos_reference;
		xi = (x_reference - x_init) * factor;
		yi = (y_reference - y_init) * factor;
		p_tmp[0] = xi;
		p_tmp[1] = yi;
		tab_push(p_tmp, director, DIR_LENGTH);
	}
	else if (ROT) {
		theta_i = ang_reference_calculation();
	}
}

void Motors::to_H_bridgeable(float* _right_cmd, float* _left_cmd) {

	//Directions
	if (*_right_cmd < 0) {
		dir_right->write(0);
		dr = 0;
		*_right_cmd = -1 * *_right_cmd;
	}
	else {
		dir_right->write(1);
		dr = 1;
	}
	if (*_left_cmd < 0) {
		dir_left->write(0);
		dl = 0;
		*_left_cmd = -1 * *_left_cmd;
	}
	else {
		dir_left->write(1);
		dl = 1;
	}

	//Normalization
	*_right_cmd = *_right_cmd / V_ALIM_POWER;
	*_left_cmd = *_left_cmd / V_ALIM_POWER;

	//Saturations
	*_right_cmd = (*_right_cmd > 1) ? 1 : *_right_cmd;
	*_right_cmd = (*_right_cmd < 0) ? 0 : *_right_cmd;
	*_left_cmd = (*_left_cmd > 1) ? 1 : *_left_cmd;
	*_left_cmd = (*_left_cmd < 0) ? 0 : *_left_cmd;
	pwr = *_right_cmd;
	pwl = *_left_cmd;
}

void Motors::set_Enc_ptr(Encoders* _enc) {
	instEncoders = _enc;
}

void Motors::set_Nav_ptr(Navigator* _instNav) {
	instNav = _instNav;
}

void Motors::hard_stop() {
	if (debug)
		serialOut->printf("Regulator process has been killed\n");
	stop();
}

void Motors::dead_zone() {
	if (instEncoders->last_changed() > TIMEOUT) {
		if (debug)
			serialOut->printf("Regulator process ended by Timeout\n");
		stop();
	}
	else if (sqrt((x_reference - instEncoders->getX())*(x_reference - instEncoders->getX()) + (y_reference - instEncoders->getY())*(y_reference - instEncoders->getY())) < TOLERANCE_POS && RSQR) {
		if (debug)
			serialOut->printf("Regulator process ended by Goal Hit\n");
		stop();
	}
	else if (instEncoders->getTheta() - ang_reference < TOLERANCE_ANG && ROT) {
		if (debug)
			serialOut->printf("Regulator process ended by Goal Hit\n");
		stop();
	}
}

void Motors::stop() {
	RSQR = false;
	ROT = false;

	schedule_routine->detach();
	schedule_infos->detach();
	right_motor->write(0);
	left_motor->write(0);
	status = false;
}

void Motors::send_i() {
	if (debug) {
		serialOut->printf("\n(xi:%f ; yi:%f)\n", xi, yi);
		//serialOut->printf("LastChange : %f\n", instEncoders->last_changed());
		serialOut->printf("(x:%f ; y:%f) ang:%f\n", instEncoders->getX(), instEncoders->getY(), instEncoders->getTheta());
		//serialOut->printf("Pos reference %f\n", pos_reference);
		//float t = t_cmd->read_us();
		//serialOut->printf("Reference_calc %f at t=%f\n", pos_reference_calculation_RSQR(), t*0.000001);
		serialOut->printf("PWMD:%c%f PWMG:%c%f\n", (dr == 0) ? '-' : ' ', pwr, (dl == 0) ? '-' : ' ', pwl);
		serialOut->printf("Pos err :%f Ang err : %f\n", pos_err[0], ang_err[0]);
		serialOut->printf("%fx+%fy+%f=0\n", (director[0][0] - director[2][0]), (director[0][1] - director[2][1]), -(director[0][0] - director[2][0])*director[0][0] - (director[0][1] - director[2][1])*director[0][1]);
		serialOut->printf("%s le demi plan\n", (location() == 1) ? "Dans" : "Dehors");
	}
}

void Motors::comStop() {
	char buff[256];
	serialOut->gets(buff, 256);
	hard_stop();
}

int Motors::location() {
	float a = (director[0][0] - director[2][0]);
	float b = (director[0][1] - director[2][1]);
	float c = -a*director[0][0] - b*director[0][1];
	if ( a*instEncoders->getX() + b*instEncoders->getY() + c <= 0) {
		return 1;
	}
	else {
		return 0;
	}
}