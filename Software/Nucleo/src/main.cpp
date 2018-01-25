#include "mbed.h"
#include "Stepper.hpp"
#include "Motors.hpp"
#include "PINOUT.hpp"
#include "Navigator.hpp"
#include "CONSTANTES.hpp"

int main() {

	Serial debug(USBTX, USBRX, 115200);
	debug.printf("\n\nProgramme de tesuto !\n");
	Navigator nav(&debug);

	std::vector<vector<float> > route1;
	std::vector<float> p11(2, 0);
	p11[0] = 0;
	p11[1] = 1500;
	route1.push_back(p11);

	DigitalIn btn(USER_BUTTON);
	debug.printf("Waiting for start\n");
	while (btn.read() == 0) {
		if (debug.readable()) {
			wait(0.5);
			char buff[256];
			debug.gets(buff, 256);
			debug.printf("%s", buff);
			if (strcmp(buff, "Start")) {
				debug.printf("Go !\n");
				break;
			}
		}
	}

	nav.navigate(&route1, PI);

	while (1);

	return 0;
}