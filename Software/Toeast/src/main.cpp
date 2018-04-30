#include "mbed.h"
#include "Stepper.hpp"
#include "Motors.hpp"
#include "PINOUT.hpp"
#include "Navigator.hpp"
#include "CONSTANTES.hpp"
#include "Telemetry.hpp"

int main() {

	Telemetry test;
	while (1) {
		test.send_PWM(42.42f, 273.42f);
		test.send_PWM(273.15f, 42.42f);
		wait(0.5);
	}


	/*
	Serial debug(USBTX, USBRX, 115200);

	debug.printf("\n\nTesutou Puroguramu !\n");

	float a = 0.424200f;
	char tst[4];
	Telemetry::float_to_hex(a, tst);
	debug.printf("Telemetry conversion of %f : %x %x %x %x\n", a, tst[0], tst[1], tst[2], tst[3]);
	debug.printf("Telemetry conversion of %x %x %x %x : %f\n", tst[0], tst[1], tst[2], tst[3], Telemetry::hex_to_float(tst));

	DigitalOut blue(LED2);
	blue.write(1);
	Navigator nav(&debug);	
	DigitalOut red(LED3);	
	red.write(1);

	std::vector<vector<float> > route1;
	std::vector<float> p11(2, 0);
	p11[0] = -1000;
	p11[1] = 0;
	route1.push_back(p11);

	DigitalIn btn(USER_BUTTON);
	debug.printf("Waiting for start\n\n");
	char buff[256];
	while (btn.read() == 0) {
		if (debug.readable()) {
			//wait(0.5);			
			debug.gets(buff, 256);
			debug.printf("%s\n", buff);
			if (strcmp(buff, "Start\n")) {
				debug.printf("Go !\n");
				break;
			}
		}
	}

	nav.navigate(&route1, 0);
	//nav.test(0.15, 0.30, 0.5, 0.005);

	while (1);
	*/
	return 0;
}