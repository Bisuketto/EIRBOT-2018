#include "Navigator.hpp"


Navigator::Navigator()
{
	status = false;
	i = 0;
	instMotors = new Motors(PIN_PWMG, PIN_PWMD, PIN_SENSMG, PIN_SENSMD);
	instEncoders = new Encoders();
	instMotors->set_Enc_ptr(instEncoders);
	instMotors->set_Nav_ptr(this);
}

Navigator::Navigator(Serial* _debug)
{	
	status = false;
	debug = true;
	serialOut = _debug;
	serialOut->printf("Navigator Initialisation\n");
	i = 0;
	instMotors = new Motors(PIN_PWMG, PIN_PWMD, PIN_SENSMG, PIN_SENSMD, _debug);
	instEncoders = new Encoders(_debug);	
	instMotors->set_Enc_ptr(instEncoders);
	instMotors->set_Nav_ptr(this);
	serialOut->printf("Navigator : [Ok]\n");
}

Navigator::Navigator(float _x0, float _y0, float _theta_i)
{
	status = false;
	i = 0;	
	instMotors = new Motors(PIN_PWMG, PIN_PWMD, PIN_SENSMG, PIN_SENSMD);	
	instEncoders = new Encoders(_x0, _y0, _theta_i);
	instMotors->set_Enc_ptr(instEncoders);
	instMotors->set_Nav_ptr(this);
}

Navigator::Navigator(Telemetry *_telem, float _x0, float _y0, float _theta_i)
{
	instTelem = _telem;
	status = false;
	i = 0;
	instMotors = new Motors(PIN_PWMG, PIN_PWMD, PIN_SENSMG, PIN_SENSMD, instTelem);
	instEncoders = new Encoders(_x0, _y0, _theta_i);
	instMotors->set_Enc_ptr(instEncoders);
	instMotors->set_Nav_ptr(this);
}

Navigator::Navigator(float _x0, float _y0, float _theta_i, Serial* _debug)
{
	status = false;
	debug = true;
	serialOut = _debug;
	serialOut->printf("Navigator Initialisation\n");
	i = 0;	
	instMotors = new Motors(PIN_PWMG, PIN_PWMD, PIN_SENSMG, PIN_SENSMD, _debug);
	instEncoders = new Encoders(_x0, _y0, _theta_i);
	instMotors->set_Enc_ptr(instEncoders);
	instMotors->set_Nav_ptr(this);
	serialOut->printf("Navigator : [Ok]\n");
}


Navigator::~Navigator()
{
}


void Navigator::navigate(std::vector<vector<float> >* _route, float _theta_end) {
	status = true;
	if (debug) {
		serialOut->printf("Starting navigation\n");
	}
	route = _route;
	theta_end = _theta_end;
	i = 0;
	go_to_i();
	while (status == true);
	if (debug) {
		serialOut->printf("Navigation ended\n");
	}
}

void Navigator::finished() {
	if (debug) {
		serialOut->printf("Arrived to %d point\n", i);
	}
	i++;
	go_to_i();
}

void Navigator::go_to_i() {
	if (debug && i < route->size()) {
		serialOut->printf("Going to (%f, %f)\n", (*route)[i][0], (*route)[i][1]);
	}

	if ((i%2 == 0) && (i < route->size()*2)) {
		if(debug)
			serialOut->printf("ROTATE\n");
		//instMotors->go_to_RSQR((*route)[i][0], (*route)[i][1]);
		float Dx = (*route)[i/ 2][0] - instEncoders->getX();
		float Dy = (*route)[i/2][1] - instEncoders->getY();
		float Ddist = sqrt(Dx*Dx + Dy*Dy);
		if (Dy == 0) {
			instMotors->rotate(PI);
		}
		else {
			instMotors->rotate((2 * atan(Dy / (Dx + Ddist))));
		}
	}
	else if ((i % 2 == 1) && (i < (route->size() * 2))) {
		if(debug)
			serialOut->printf("NULLE\n");
		//instMotors->go_to_RSQR((*route)[i][0], (*route)[i][1]);
		float Dx = (*route)[(i - 1) / 2][0] - instEncoders->getX();
		float Dy = (*route)[(i - 1) / 2][1] - instEncoders->getY();
		float Ddist = sqrt(Dx*Dx + Dy*Dy);
		instMotors->go_to_Nul(Ddist, (*route)[(i-1)/2][0], (*route)[(i-1)/2][1]);
	}
	else if(i == route->size()*2){
		if(debug)
			serialOut->printf("END\n");
		instMotors->rotate(theta_end);
	}
	else {
		if (debug)
			serialOut->printf("Status = false\n");
		status = false; 
	}
}

void Navigator::test(float _pwm_low, float _pwm_high, int _t1, float _period) {
	if (debug)
		serialOut->printf("Begining translation identification measurement...\n");
	instMotors->identify(_pwm_low, _pwm_high, _t1, _period);
	if (debug)
		serialOut->printf("Measurement ended.\nBegining rotation identification measurement...\n");
	instMotors->identify_rotate(_pwm_low, _pwm_high, _t1, _period);
	if (debug)
		serialOut->printf("Measurement ended.\n");
}