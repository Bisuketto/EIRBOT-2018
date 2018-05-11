#ifndef GP2_H
#define GP2_H

#include "mbed.h"
#include "CONSTANTES.hpp"

class GP2 {
	public:
		GP2(PinName _A, PinName _B, PinName _C, PinName _D, PinName _E, PinName _F, Serial* _debug = NULL);
		~GP2();
		bool too_close();
		void set_front(bool _enable);
		void set_enabled(bool _enable);
	private:
		bool front;
		int count;
		bool dbg;
		Serial* debug;
		bool enabled;
		AnalogIn* a;
		AnalogIn* b;
		AnalogIn* c;
		AnalogIn* d;
		AnalogIn* e;
		AnalogIn* f;
};

#endif