#include "Stepper.h"

Stepper::Stepper(PinName _A, PinName _B, PinName _C, PinName _D, PinName _en1, PinName _en2) {
	period = PERIODE_STEPPER;
	A = new DigitalOut(_A);
	B = new DigitalOut(_B);
	C = new DigitalOut(_C);
	D = new DigitalOut(_D);
	en1 = new DigitalOut(_en1);
	en2 = new DigitalOut(_en2);
	current_state = stop;
	schedule = new Ticker;
	schedule->attach(callback(this, &Stepper::routine), period);
	lock = false;
}

Stepper::~Stepper() {

}

void Stepper::routine() {
	if (lock) {
		switch (current_state) {
			case stop:
				en1->write(0);
				en2->write(0);
				break;
			case phase1:
				en1->write(1);
				en2->write(1);

				A->write(1);
				B->write(0);
				C->write(0);
				D->write(1);
				current_state = (sens) ? phase2 : phase4;
				break;
			case phase2:
				en1->write(1);
				en2->write(1);

				A->write(1);
				B->write(1);
				C->write(0);
				D->write(0);
				current_state = (sens) ? phase3 : phase1;
				break;
			case phase3:
				en1->write(1);
				en2->write(1);

				A->write(0);
				B->write(1);
				C->write(1);
				D->write(0);
				current_state = (sens) ? phase4 : phase2;
				break;
			case phase4:
				en1->write(1);
				en2->write(1);

				A->write(0);
				B->write(0);
				C->write(1);
				D->write(1);
				current_state = (sens) ? phase1 : phase3;
				break;
			default:
				current_state = stop;
				break;
		}
	}
}

void Stepper::on(bool _sens) {
	sens = _sens;
}

void Stepper::lock_mot(bool _locked) {
	lock = true;
}

void Stepper::stop_mot() {
	current_state = stop;
}

void Stepper::vitesse(float _period) {
	period = _period;
	schedule->detach();
	schedule->attach(callback(this, &Stepper::routine), period);
}