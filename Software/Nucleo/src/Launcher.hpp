#ifndef LAUNCHER_H
#define LAUNCHER_H

#include "mbed.h"
#include "AX12\AX12.h"

class Launcher
{
	public:
		Launcher(PinName _RX, PinName _TX);
		~Launcher();

		void on();
		void off();
	private:
		Comm_AX12 *comm;
		AX12 *rightAX;
		AX12 *leftAX;
};

#endif
