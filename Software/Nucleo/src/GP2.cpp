#include "GP2.hpp"

GP2::GP2(PinName _A, PinName _B, PinName _C, PinName _D, PinName _E, PinName _F, Serial* _debug) {
	debug = _debug;
	dbg = (debug != NULL) ? true : false;
	a = new AnalogIn(_A);
	b = new AnalogIn(_B);
	c = new AnalogIn(_C);
	d = new AnalogIn(_D);
	e = new AnalogIn(_E);
	f = new AnalogIn(_F);
	enabled = true;
	count = 0;
	front = true;
}

GP2::~GP2() {

}

bool GP2::too_close() {
	if (front) {
		if (a->read() < THRESHOLD_GP2 && b->read() < THRESHOLD_GP2 && c->read() < THRESHOLD_GP2_SIDE && d->read() < THRESHOLD_GP2_SIDE) {
			count = 0;
		}
		else {
			count++;
		}

		//if (dbg)
		//	debug->printf("FL : %d, FR : %d, SL : %d, SR : %d\n", a->read() < THRESHOLD_GP2, b->read() < THRESHOLD_GP2, c->read() < THRESHOLD_GP2_SIDE, d->read() < THRESHOLD_GP2_SIDE);
		return (count > ECH_CONFIRM) & enabled;
	}
	else {
		if (e->read() < THRESHOLD_GP2 && f->read() < THRESHOLD_GP2) {
			count = 0;
		}
		else {
			count++;
		}
		return (count > ECH_CONFIRM) & enabled;
	}
}

void GP2::set_enabled(bool _enable) {
	enabled = _enable;
}

void GP2::set_front(bool _enable) {
	front = _enable;
}