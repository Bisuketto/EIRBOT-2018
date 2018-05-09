#include "Navigator.hpp"


Navigator::Navigator()
{
	status = false;

	DigitalIn side_sw(PIN_SIDE);
	DigitalOut g_led(LED_GREEN);
	DigitalOut r_led(LED_RED);
	side = side_sw.read();
	g_led.write(!side);
	r_led.write(side);

	i = 0;
	instGp2 = new GP2(PIN_GP2_FL, PIN_GP2_FR, PIN_GP2_SL, PIN_GP2_SR);
	instMotors = new Motors(PIN_PWMG, PIN_PWMD, PIN_SENSMG, PIN_SENSMD);
	instEncoders = new Encoders();
	instMotors->set_GP2_ptr(instGp2);
	instMotors->set_Enc_ptr(instEncoders);
	instMotors->set_Nav_ptr(this);
	current_game_time = new Timer;
	current_game_time->start();
}

Navigator::Navigator(Serial* _debug)
{	
	status = false;
	debug = true;
	serialOut = _debug;
	serialOut->printf("Navigator Initialisation\n");

	DigitalIn side_sw(PIN_SIDE);
	DigitalOut g_led(LED_GREEN);
	DigitalOut r_led(LED_RED);
	side = side_sw.read();
	serialOut->printf("\tBool side : %d\n", side);
	serialOut->printf("\tSide : %s\n", (side) ? "green" : "orange");
	g_led.write(!side);
	r_led.write(side);

	i = 0;
	instGp2 = new GP2(PIN_GP2_FL, PIN_GP2_FR, PIN_GP2_SL, PIN_GP2_SR);
	instMotors = new Motors(PIN_PWMG, PIN_PWMD, PIN_SENSMG, PIN_SENSMD, _debug);
	instEncoders = new Encoders(_debug);
	instMotors->set_GP2_ptr(instGp2);
	instMotors->set_Enc_ptr(instEncoders);
	instMotors->set_Nav_ptr(this);
	serialOut->printf("Navigator : [Ok]\n");
	current_game_time = new Timer;
	current_game_time->start();
}

Navigator::Navigator(float _x0, float _y0, float _theta_i)
{
	status = false;

	DigitalIn side_sw(PIN_SIDE);
	DigitalOut g_led(LED_GREEN);
	DigitalOut r_led(LED_RED);
	side = side_sw.read();
	g_led.write(!side);
	r_led.write(side);

	i = 0;
	instGp2 = new GP2(PIN_GP2_FL, PIN_GP2_FR, PIN_GP2_SL, PIN_GP2_SR);
	instMotors = new Motors(PIN_PWMG, PIN_PWMD, PIN_SENSMG, PIN_SENSMD);
	instEncoders = new Encoders(_x0, _y0, _theta_i);
	instMotors->set_GP2_ptr(instGp2);
	instMotors->set_Enc_ptr(instEncoders);
	instMotors->set_Nav_ptr(this);
	current_game_time = new Timer;
	current_game_time->start();
}

Navigator::Navigator(Telemetry *_telem, float _x0, float _y0, float _theta_i)
{
	instTelem = _telem;
	status = false;

	DigitalIn side_sw(PIN_SIDE);
	DigitalOut g_led(LED_GREEN);
	DigitalOut r_led(LED_RED);
	side = side_sw.read();
	g_led.write(!side);
	r_led.write(side);

	i = 0;
	instGp2 = new GP2(PIN_GP2_FL, PIN_GP2_FR, PIN_GP2_SL, PIN_GP2_SR);
	instMotors = new Motors(PIN_PWMG, PIN_PWMD, PIN_SENSMG, PIN_SENSMD, instTelem);
	instEncoders = new Encoders(_x0, _y0, _theta_i);
	instMotors->set_GP2_ptr(instGp2);
	instMotors->set_Enc_ptr(instEncoders);
	instMotors->set_Nav_ptr(this);
	current_game_time = new Timer;
	current_game_time->start();
}

Navigator::Navigator(float _x0, float _y0, float _theta_i, Serial* _debug)
{
	status = false;
	debug = true;
	serialOut = _debug;
	serialOut->printf("Navigator Initialisation\n");

	DigitalIn side_sw(PIN_SIDE);
	DigitalOut g_led(LED_GREEN);
	DigitalOut r_led(LED_RED);
	side = side_sw.read();
	serialOut->printf("\tBool side : %d\n", side);
	serialOut->printf("\tSide : %s\n", (side == true) ? "green" : "orange");
	g_led.write(!side);
	r_led.write(side);

	i = 0;
	instGp2 = new GP2(PIN_GP2_FL, PIN_GP2_FR, PIN_GP2_SL, PIN_GP2_SR);
	instMotors = new Motors(PIN_PWMG, PIN_PWMD, PIN_SENSMG, PIN_SENSMD, _debug);
	instEncoders = new Encoders(_x0, _y0, _theta_i);
	instMotors->set_GP2_ptr(instGp2);
	instMotors->set_Enc_ptr(instEncoders);
	instMotors->set_Nav_ptr(this);
	serialOut->printf("Navigator : [Ok]\n");
	current_game_time = new Timer;
	current_game_time->start();
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

void Navigator::aborted() {
	if (debug) {
		serialOut->printf("Path to %d point obstructed\n", i);
	}
	Timer twait;
	twait.start();
	while (twait.read_ms() < 1000);
	go_to_i();
}

void Navigator::go_to_i() {
	if (debug && i < route->size()) {
		serialOut->printf("Going to (%f, %f)\n", (*route)[i][0], (*route)[i][1]);
	}

	if ((i%2 == 0) && (i < route->size()*2)) {
		float x_togo = (*route)[i / 2][0];
		float y_togo = (*route)[i / 2][1];
		float theta_togo;
		if (side == true) {
			float x_togo = 3000 - x_togo;
		}
		if(debug)
			serialOut->printf("ROTATE\n");
		//instMotors->go_to_RSQR((*route)[i][0], (*route)[i][1]);
		float Dx = x_togo - instEncoders->getX();
		float Dy = y_togo - instEncoders->getY();
		float Ddist = sqrt(Dx*Dx + Dy*Dy);
		if (Dy == 0  && Dx == -Ddist) {
			instMotors->rotate(PI);
		}
		else {
			instMotors->rotate((2 * atan(Dy / (Dx + Ddist))));
		}
	}
	else if ((i % 2 == 1) && (i < (route->size() * 2))) {
		float x_togo = (*route)[(i - 1) / 2][0];
		float y_togo = (*route)[(i - 1) / 2][1];
		float theta_togo;
		if (side == true) {
			float x_togo = 3000 - x_togo;
		}
		if(debug)
			serialOut->printf("NULLE\n");
		//instMotors->go_to_RSQR((*route)[i][0], (*route)[i][1]);
		float Dx = x_togo - instEncoders->getX();
		float Dy = y_togo - instEncoders->getY();
		float Ddist = sqrt(Dx*Dx + Dy*Dy);
		instMotors->go_to_Nul(Ddist, (*route)[(i-1)/2][0], (*route)[(i-1)/2][1]);
	}
	else if(i == route->size()*2){
		if(debug)
			serialOut->printf("END\n");
		if(theta_end >= 0)
			instMotors->rotate((side == true) ? PI - theta_end : theta_end);
		else
			instMotors->rotate((side == true) ? -PI - theta_end : theta_end);
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

void Navigator::motorDebug() {
	instMotors->go_to_Nul(1000, 1000, 0);
	instMotors->rotate(PI);
}

void Navigator::set_detection(bool _enable) {
	instGp2->set_enabled(_enable);
}

bool Navigator::free_to_move() {
	return (current_game_time->read() < GAME_TIME) || !GAME_MODE;
}