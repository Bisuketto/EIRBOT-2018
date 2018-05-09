#ifndef LAUNCHER_H
#define LAUNCHER_H

#include "mbed.h"
#include "AX12\AX12.h"
#include "Navigator.hpp"

class Launcher
{
	public:
		Launcher(PinName _RX, PinName _TX);
		~Launcher();
		void set_nav_ptr(Navigator* _instNav);

		void on();
		void off();
	private:
		Navigator* instNav;
		Timer* timerwait;
		void my_wait(int ms);
		Comm_AX12 *comm;
		AX12 *rightAX;
		AX12 *leftAX;
};

#endif
