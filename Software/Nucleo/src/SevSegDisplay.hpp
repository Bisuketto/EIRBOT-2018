#ifndef SEVSEGDISPLAY_H
#define SEVSEGDISPLAY_H

#include "mbed.h"
#include "CONSTANTES.hpp"

enum disp_status { STOP, DISP1, DISP2, DISP3 };

class SevSegDisplay {
public:
	SevSegDisplay(PinName _A, PinName _B, PinName _C, PinName _D, PinName _Disp1, PinName _Disp2, PinName _Disp3);
	~SevSegDisplay();
	void display(int _value);
	void stop();

private:
	void routine();
	void set_bits(char digit);

	disp_status current_status;
	Ticker* disp_scheduler;
	DigitalInOut* bits[4];
	DigitalOut* displays[3];
	char digit1;
	char digit2;
	char digit3;
};

#endif