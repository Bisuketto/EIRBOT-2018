#include "GP2.hpp"

GP2::GP2(PinName _A, PinName _B, PinName _C, PinName _D) {
	a = new AnalogIn(_A);
	b = new AnalogIn(_B);
	c = new AnalogIn(_C);
	d = new AnalogIn(_D);
	enabled = true;
}

GP2::~GP2() {

}

bool GP2::too_close() {
	if (a->read() < THRESHOLD_GP2 && b->read() < THRESHOLD_GP2 && c->read() < THRESHOLD_GP2_SIDE && d->read() < THRESHOLD_GP2_SIDE)
		return false;
	return true & enabled;
}

void GP2::set_enabled(bool _enable) {
	enabled = _enable;
}