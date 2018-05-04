#ifndef GP2_H
#define GP2_H

#include "mbed.h"
#include "CONSTANTES.hpp"

class GP2 {
	public:
		GP2(PinName _A, PinName _B, PinName _C, PinName _D);
		~GP2();
		bool too_close();
	private:
		AnalogIn* a;
		AnalogIn* b;
		AnalogIn* c;
		AnalogIn* d;
};

#endif