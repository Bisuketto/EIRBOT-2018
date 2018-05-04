#include "SevSegDisplay.hpp"

SevSegDisplay::SevSegDisplay(PinName _A, PinName _B, PinName _C, PinName _D, PinName _Disp1, PinName _Disp2, PinName _Disp3) {
	bits[0] = new DigitalOut(_A);
	bits[1] = new DigitalOut(_B);
	bits[2] = new DigitalOut(_C);
	bits[3] = new DigitalOut(_D);
	displays[0] = new DigitalOut(_Disp1);
	displays[1] = new DigitalOut(_Disp2);
	displays[2] = new DigitalOut(_Disp3);
	current_status = STOP;
	disp_scheduler = new Ticker;
	disp_scheduler->attach(callback(this, &SevSegDisplay::routine), DISP_PERIODE);
}

SevSegDisplay::~SevSegDisplay() {

}

void SevSegDisplay::display(int _value) {
	if (_value < 999 && _value > 0) {
		digit1 = _value / 100;
		digit2 = (_value - digit1 * 100) / 10;
		digit3 = (_value - digit1 * 100 - digit2 * 10);
	}
	else {
		digit1 = 0xE;
		digit2 = 0xE;
		digit3 = 0xE;
	}
	current_status = DISP1;
}

void SevSegDisplay::stop() {
	current_status = STOP;
}

void SevSegDisplay::routine() {
	switch (current_status) {
		case STOP:
			displays[0]->write(0);
			displays[1]->write(0);
			displays[2]->write(0);
			break;
		case DISP1:
			displays[0]->write(1);
			displays[2]->write(0);
			set_bits(digit1);
			current_status = DISP2;
			break;
		case DISP2:
			displays[0]->write(0);
			displays[1]->write(1);
			set_bits(digit2);
			current_status = DISP3;
			break;
		case DISP3:
			displays[1]->write(0);
			displays[2]->write(1);
			set_bits(digit3);
			current_status = DISP1;
			break;
		default:
			current_status = STOP;
	}
}

void SevSegDisplay::set_bits(char digit) {
	bits[0]->write((digit & (1 << 0)) >> 0);
	bits[1]->write((digit & (1 << 1)) >> 1);
	bits[2]->write((digit & (1 << 2)) >> 2);
	bits[3]->write((digit & (1 << 3)) >> 3);
}