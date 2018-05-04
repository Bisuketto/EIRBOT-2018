#include "Motors.hpp"

Motors::Motors(PinName _pwmL, PinName _pwmR, PinName _dirL, PinName _dirR) {
	RSQR = false;
	ROT = false;
	NUL = false;

	debug = false;
	telemetry_en = false;
	schedule_routine = new Ticker();
	schedule_infos = new Ticker();
	t_cmd = new Timer();
	t_cmd->start();
	right_motor = new PwmOut(_pwmR);
	left_motor = new PwmOut(_pwmL);
	dir_left = new DigitalOut(_dirL);
	dir_right = new DigitalOut(_dirR);
}

Motors::Motors(PinName _pwmL, PinName _pwmR, PinName _dirL, PinName _dirR, Serial* _debug) {
	RSQR = false;
	ROT = false;
	NUL = false;

	debug = true;
	telemetry_en = false;
	serialOut = _debug;
	serialOut->printf("\tMotors Initilisation\n");
	float regu_x[TAILLE_TABLEAUX_POS] = XCOEFFS_POS;
	float regu_y[TAILLE_TABLEAUX_POS] = YCOEFFS_POS;
	serialOut->printf("\tReguX : ");
	for(int i = 0; i < TAILLE_TABLEAUX_POS; i++) {
		serialOut->printf("%e ", regu_x[i]);
	}
	serialOut->printf("\n\tReguY : ");
	for (int i = 0; i < TAILLE_TABLEAUX_POS; i++) {
		serialOut->printf("%e ", regu_y[i]);
	}
	serialOut->printf("\n");
	schedule_routine = new Ticker();
	schedule_infos = new Ticker();
	t_cmd = new Timer();
	t_cmd->start();

	//reset_data();

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

	/*serialOut->printf("\tMotor test\n");
	dir_right->write(1);
	right_motor->write(0.25);
	wait(1);
	right_motor->write(0);
	dir_left->write(0);
	left_motor->write(0.25);
	wait(1);
	left_motor->write(0);
	wait(0.2);
	dir_right->write(0);
	right_motor->write(0.25);
	wait(1);
	right_motor->write(0);
	dir_left->write(1);
	left_motor->write(0.25);
	wait(1);
	left_motor->write(0);
	serialOut->printf("\tTest finished\n");
	wait(0.5);*/
	serialOut->printf("\tMotors : [Ok]\n");
}

Motors::Motors(PinName _pwmL, PinName _pwmR, PinName _dirL, PinName _dirR, Telemetry* _telem) {
	RSQR = false;
	ROT = false;
	NUL = false;

	debug = false;
	telemetry_en = false;
	instTelem = _telem;
	instEncoders = NULL;

	schedule_routine = new Ticker();
	schedule_infos = new Ticker();

	t_cmd = new Timer();
	t_cmd->start();

	right_motor = new PwmOut(_pwmR);
	right_motor->period_us(25);
	left_motor = new PwmOut(_pwmL);
	left_motor->period_us(25);
	dir_left = new DigitalOut(_dirL);
	dir_right = new DigitalOut(_dirR);

	schedule_infos->attach(callback(this, &Motors::send_i), PERIOD_INFO);
}

Motors::~Motors() {

}

void Motors::routine() {
	static float XCoeffs_pos[TAILLE_TABLEAUX_POS] = XCOEFFS_POS;
	static float YCoeffs_pos[TAILLE_TABLEAUX_POS] = YCOEFFS_POS;
	static float XCoeffs_ang[TAILLE_TABLEAUX_ANG] = XCOEFFS_ANG;
	static float YCoeffs_ang[TAILLE_TABLEAUX_ANG] = YCOEFFS_ANG;

	calc_pos_inter();
	
	float x_act = instEncoders->getX();
	float y_act = instEncoders->getY();
	float theta_act = instEncoders->getTheta();

	float epsilon_pos;
	float epsilon_ang;

	if (RSQR) {
		float Dx_target = x_reference - x_act;
		float Dy_target = y_reference - y_act;
		float Dx_inter = xi - x_act;
		float Dy_inter = yi - y_act;

		float Ddist_target = sqrt(Dx_target*Dx_target + Dy_target*Dy_target);
		float Ddist_inter = sqrt(Dx_inter*Dx_inter + Dy_inter*Dy_inter);

		epsilon_pos = (Ddist_target - (pos_reference - pos_reference_calculation_RSQR()));// location()*Ddist_inter; // mm
		float ang_t = (2*atan(Dy_target / (Dx_target + Ddist_target)) - theta_act)*180/PI;
		epsilon_ang = (ang_t > 180 || ang_t < -180) ? 2 * 180 - ang_t : ang_t;
	}
	else if (ROT) {
		//float Dx = x_init - x_act;
		//float Dy = y_init - y_act;
		float dist_from_start = (instEncoders->getDr() - dist_r_init + instEncoders->getDl() - dist_l_init)*PERIMETER / RESOLUTION / 2.;
		epsilon_pos = -dist_from_start;
		float ang_t = (theta_i + ang_init - theta_act)*180/PI;
		epsilon_ang = (ang_t >= 180 || ang_t < -180) ? 2 * 180 - ang_t : ang_t;
	}
	else if (NUL) {
		float Dx_act = x_init - x_act;
		float Dy_act = y_init - y_act;
		float Ddist_act = sqrt(Dx_act*Dx_act + Dy_act*Dy_act);
		epsilon_pos = pos_reference_calculation_RSQR()  - Ddist_act;
		epsilon_ang = ang_reference - instEncoders->getTheta();
	}
	else {
		epsilon_pos = 0;
		epsilon_ang = 0;
	}

	float vitesse = XCoeffs_pos[0]*epsilon_pos;	
	for (int i = 1; i < TAILLE_TABLEAUX_POS; i++) {
		vitesse += XCoeffs_pos[i] * pos_err[i-1];
		vitesse -= YCoeffs_pos[i] * pos_cmd[i-1];
	}
	tab_push(epsilon_pos, pos_err, TAILLE_TABLEAUX_POS);
	tab_push(vitesse, pos_cmd, TAILLE_TABLEAUX_POS);

	float vitesse_ang = XCoeffs_ang[0]*epsilon_ang;	
	for (int i = 1; i < TAILLE_TABLEAUX_ANG; i++) {
		vitesse_ang += XCoeffs_ang[i] * ang_err[i-1];
		vitesse_ang -= YCoeffs_ang[i] * ang_cmd[i-1];
	}
	tab_push(epsilon_ang, ang_err, TAILLE_TABLEAUX_ANG);
	tab_push(vitesse_ang, ang_cmd, TAILLE_TABLEAUX_ANG);

	saturation(&vitesse, &vitesse_ang, 0.7f, 0.5f);

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
	if (debug)
		schedule_infos->attach(callback(this, &Motors::send_i), 2.);
	serialOut->attach(callback(this, &Motors::comStop));
	status = true;
}

void Motors::rotate(float _ang) {
	ROT = true;

	if (debug)
		serialOut->printf("Rotating to %f rads\n", _ang);

	schedule_routine->detach();
	reset_data();

	dist_r_init = instEncoders->getDr();
	dist_l_init = instEncoders->getDl();
	x_init = instEncoders->getX();
	y_init = instEncoders->getY();
	ang_init = instEncoders->getTheta();
	ang_reference = _ang - instEncoders->getTheta();

	t_cmd->reset();
	if (debug)
		serialOut->printf("Starting control routine\n");
	schedule_routine->attach(callback(this, &Motors::routine), TECH);
	if (debug)
		serialOut->printf("Starting info routine\n");
	if (debug)
		schedule_infos->attach(callback(this, &Motors::send_i), 2.);
	serialOut->attach(callback(this, &Motors::comStop));
	serialOut->printf("RSQR : %d ROT : %d\n", RSQR, ROT);
	status = true;
}

void Motors::go_to_Nul(float _dist, float _x, float _y) {
	NUL = true;
	if (debug)
		serialOut->printf("Forward for %f mm\n", _dist);
	
	schedule_routine->detach();
	reset_data();

	x_reference = _x;
	y_reference = _y;
	x_init = instEncoders->getX();
	y_init = instEncoders->getY();
	pos_reference = _dist;
	ang_reference = instEncoders->getTheta();

	t_cmd->reset();
	if (debug)
		serialOut->printf("Starting control routine\n");
	schedule_routine->attach(callback(this, &Motors::routine), TECH);
	if (debug)
		serialOut->printf("Starting info routine\n");
	if (debug)
		schedule_infos->attach(callback(this, &Motors::send_i), 2.);
	serialOut->attach(callback(this, &Motors::comStop));
	serialOut->printf("RSQR : %d ROT : %d NUL : %d\n", RSQR, ROT, NUL);
	status = true;
}

void Motors::tab_push(float _x, float* _tab, int _l) {
	for (int i = 0; i < _l - 1; i++) {
		_tab[_l - i - 1] = _tab[_l - i - 2];
	}
	_tab[0] = _x;
}

void Motors::tab_push(float* _p, float** _tab, int _l) {
	float* temp = new float [2];
	temp[0] = _p[0];
	temp[1] = _p[1];
	delete _tab[_l - 1];
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
		float* temp = new float [2];
		temp[0] = 0.;
		temp[0] = 0.;
		_tab[i] = temp;
	}
}

void Motors::reset_data() {
	tab_init(pos_cmd, TAILLE_TABLEAUX_POS);
	tab_init(pos_err, TAILLE_TABLEAUX_POS);
	tab_init(ang_cmd, TAILLE_TABLEAUX_ANG);
	tab_init(ang_err, TAILLE_TABLEAUX_ANG);
	tab_init(director, DIR_LENGTH);
	instEncoders->reset_changed();
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

void Motors::saturation(float* _lin_spd, float* _ang_spd, float _sat_pos, float _sat_ang) {
	*_lin_spd = (*_lin_spd > V_ALIM_POWER/ _sat_pos) ? V_ALIM_POWER / _sat_pos : *_lin_spd;
	*_lin_spd = (*_lin_spd < -V_ALIM_POWER / _sat_pos) ? -V_ALIM_POWER / _sat_pos : *_lin_spd;
	*_ang_spd = (*_ang_spd > V_ALIM_POWER / _sat_ang) ? V_ALIM_POWER / _sat_ang : *_ang_spd;
	*_ang_spd = (*_ang_spd < -V_ALIM_POWER / _sat_ang) ? V_ALIM_POWER / _sat_ang : *_ang_spd;
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
		instNav->finished();
	}
	else if ((sqrt((x_reference - instEncoders->getX())*(x_reference - instEncoders->getX()) + (y_reference - instEncoders->getY())*(y_reference - instEncoders->getY())) < TOLERANCE_POS) && (RSQR || NUL)) {
		if (debug)
			serialOut->printf("Regulator process ended by Goal Hit\n");
		stop();
		instNav->finished();
	}
	else if ((fabs(instEncoders->getTheta() - ang_reference) < TOLERANCE_ANG*PI/180) && ROT) {
		if (debug)
			serialOut->printf("Regulator process ended by Goal Hit\n");
		stop();
		instNav->finished();
	}
	else if (instGP2->too_close()) {
		if (debug)
			serialOut->printf("Regulator process ended by GP2 detection\n");
		stop();
		instNav->finished();
	}
}

void Motors::stop() {
	RSQR = false;
	ROT = false;
	NUL = false;

	schedule_routine->detach();
	if (debug)
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
		serialOut->printf("Director N: %f,%f N-1: %f,%f\n", director[0][0], director[0][1], director[1][0], director[1][1]);
		//serialOut->printf("P_tmp : %f,%f\n", p_tmp[0], p_tmp[1]);
	}
	if (telemetry_en && instEncoders != NULL) {
		instTelem->send_COORD(instEncoders->getX(), instEncoders->getY());
		instTelem->send_ENC(instEncoders->getDl(), instEncoders->getDr());
		instTelem->send_PWM((dr == 0) ? -pwl : pwl, (dl == 0) ? -pwr : pwr);
		instTelem->send_TIME(t_cmd->read());
		instTelem->send_ERR(pos_err[0], ang_err[0]);
		instTelem->send_ANG(instEncoders->getTheta());
		//instTelem->send_STAT();
	}
}

void Motors::comStop() {
	char buff[256];
	serialOut->gets(buff, 256);
	hard_stop();
}

int Motors::location() {
	/*
	float a = (director[0][0] - director[2][0]);
	float b = (director[0][1] - director[2][1]);
	float c = -a*director[0][0] - b*director[0][1];
	if ( a*instEncoders->getX() + b*instEncoders->getY() + c <= 0) {
		return 1;
	}
	else {
		return -1;
	}
	*/
	float x_act = instEncoders->getX();
	float y_act = instEncoders->getY();
	if (sqrt((x_act - x_reference)*(x_act - x_reference) + (y_act - y_reference)*(y_act - y_reference)) > (pos_reference - pos_reference_calculation_RSQR())) {
		return -1;
	}
	else {
		return 1;
	}
}

void Motors::identify(float _pwm_low, float _pwm_high, int _t1, float _period) {
	periode = _period;
	stop();
	dir_right->write(1);
	dir_left->write(1);
	right_motor->write(_pwm_high);
	left_motor->write(_pwm_high);
	index = 0;
	schedule_routine->attach(callback(this, &Motors::identifier_routine), _period);
}

void Motors::identify_rotate(float _pwm_low, float _pwm_high, int _t1, float _period) {
	periode = _period;
	stop();
	dir_right->write(1);
	dir_left->write(0);
	right_motor->write(_pwm_high);
	left_motor->write(_pwm_high);
	index = 0;
	schedule_routine->attach(callback(this, &Motors::identifier_routine), _period);
}

void Motors::identifier_routine() {
	if (index < N_PTS) {
		mes[index] = instEncoders->getImpEncR()*PERIMETER / (4096.0 *  0.005);
		index++;
	}
	else {
		stop();
		for (int i = 0; i < N_PTS; i++) {
			serialOut->printf("%f\n", mes[i]);
		}
	}
}

void Motors::set_GP2_ptr(GP2* _instGP2) {
	instGP2 = _instGP2;
}