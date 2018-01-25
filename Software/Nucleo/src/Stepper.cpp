#include "Stepper.hpp"

Stepper::Stepper(PinName _A, PinName _B, PinName _C, PinName _D, PinName _en1, PinName _en2) {
	period = DEFAUT_PERIODE_STEPPER;
	A = new DigitalOut(_A);
	B = new DigitalOut(_B);
	C = new DigitalOut(_C);
	D = new DigitalOut(_D);
	en1 = new DigitalOut(_en1);
	en2 = new DigitalOut(_en2);
	current_state = phase1;
	schedule = new Ticker;
	lock = false;
	schedule->attach(callback(this, &Stepper::routine), period);
	debug_serial = new Serial(USBTX, USBRX, 115200);
}

Stepper::~Stepper() {

}

void Stepper::routine() {
	switch (current_state) {
		case phase1:
			en1->write(1);
			en2->write(1);
				
			A->write(1);
			B->write(0);
			C->write(1);
			D->write(0);
			if(!lock)
				current_state = (sens) ? phase2 : phase4;
			break;
		case phase2:
			en1->write(1);
			en2->write(1);
				
			A->write(1);
			B->write(0);
			C->write(0);
			D->write(1);
			if (!lock)
				current_state = (sens) ? phase3 : phase1;
			break;
		case phase3:
			en1->write(1);
			en2->write(1);

			A->write(0);
			B->write(1);
			C->write(0);
			D->write(1);
			if (!lock)
				current_state = (sens) ? phase4 : phase2;
			break;
		case phase4:
			en1->write(1);
			en2->write(1);
				
			A->write(0);
			B->write(1);
			C->write(1);
			D->write(0);
			if (!lock)
				current_state = (sens) ? phase1 : phase3;
			break;

		default:
			current_state = phase1;
			break;
	}
}

void Stepper::on(bool _sens) {
	sens = _sens;
	stop = false;
	lock = false;
}

void Stepper::lock_mot() {
	lock = true;
}

void Stepper::stop_mot() {
	stop = true;
}

void Stepper::vitesse(float _period) {
	period = _period;
	schedule->detach();
	schedule->attach(callback(this, &Stepper::routine), period);
}

void Stepper::routine_test(int _n) {
	this->vitesse(0.015);
	bool sens = true;
	for(int i = 0; i < _n; i++) {
		this->on(sens);
		wait_ms(2000);
		this->lock_mot();
		this->stop_mot();
		sens = !sens;
	}
}