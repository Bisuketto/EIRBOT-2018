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

Navigator::Navigator(float _x0, float _y0, float _theta_i, Serial* _debug)
{
	status = false;
	debug = true;
	serialOut = _debug;
	i = 0;	
	instMotors = new Motors(PIN_PWMG, PIN_PWMD, PIN_SENSMG, PIN_SENSMD, _debug);
	instEncoders = new Encoders(_x0, _y0, _theta_i);
	instMotors->set_Enc_ptr(instEncoders);
	instMotors->set_Nav_ptr(this);
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
}

void Navigator::finished() {
	if (debug) {
		serialOut->printf("Arrived to %d point\n", i);
	}
	i++;
	go_to_i();
}

void Navigator::go_to_i() {
	if (debug) {
		serialOut->printf("Going to (%f, %f)\n", (*route)[i][0], (*route)[i][1]);
	}

	if (i < route->size()) {
		instMotors->go_to_RSQR((*route)[i][0], (*route)[i][1]);
	}
	else if(i == route->size()){
		//instMotors->rotate(theta_end);
	}
	else {
		status = false; 
	}
}

void Navigator::test(float _pwm_low, float _pwm_high, int _t1, float _period) {
	instMotors->identify(_pwm_low, _pwm_high, _t1, _period);
}