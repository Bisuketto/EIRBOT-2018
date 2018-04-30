#include "mbed.h"
#include "Stepper.hpp"
#include "Motors.hpp"
#include "PINOUT.hpp"
#include "Navigator.hpp"
#include "CONSTANTES.hpp"
#include "Telemetry.hpp"
#include "Launcher.hpp"
#include "rtos.h" //Maybe used in the future


int main() {
	bool debugging = true;

	DigitalIn btn(USER_BUTTON);
	Serial debug(USBTX, USBRX, 115200);

	Telemetry instTelem(&debug);

	if (debugging)
		debug.printf("\n\nTesutou Puroguramu !\n");

	DigitalOut green(LED1);
	if (debugging)
		debug.printf("Launcher initialization\n");
	Launcher launcherTest(LAUNCHER_RX, LAUNCHER_TX);
	if (debugging) {
		debug.printf("Launcher : [Ok]\n");
		debug.printf("Enabling launcher for 10s\n");
	}
	launcherTest.on();
	wait(1);
	if (debugging)
		debug.printf("Disabling launcher\n");
	launcherTest.off();
	green.write(1);

	if (debugging) {
		float a = 0.424200f;
		char tst[4];
		Telemetry::float_to_hex(a, tst);
		debug.printf("Telemetry conversion of %f : %x %x %x %x\n", a, tst[0], tst[1], tst[2], tst[3]);
		debug.printf("Telemetry conversion of %x %x %x %x : %f\n", tst[0], tst[1], tst[2], tst[3], Telemetry::hex_to_float(tst));
	}

	DigitalOut blue(LED2);
	blue.write(1);

	Navigator* nav;

	if (debugging)
		nav = new Navigator(&debug);
	else
		nav = new Navigator(&instTelem);
	DigitalOut red(LED3);	
	red.write(1);

	std::vector<vector<float> > route1;
	std::vector<float> p11(2, 0);
	p11[0] = 500;
	p11[1] = 0;
	route1.push_back(p11);

	std::vector<vector<float> > route2;
	std::vector<float> p21(2, 0);
	p21[0] = 500;
	p21[1] = -500;
	route2.push_back(p21);

	std::vector<vector<float> > route3;
	std::vector<float> p31(2, 0);
	p31[0] = 500;
	p31[1] = 0;
	route3.push_back(p31);

	std::vector<vector<float> > route4;
	std::vector<float> p41(2, 0);
	p41[0] = 0;
	p41[1] = 0;
	route4.push_back(p41);

	if (debugging)
		debug.printf("Waiting for start\n\n");

	char buff[256];
	while (btn.read() == 0) {
		if (debugging) {
			if (debug.readable()) {
				debug.gets(buff, 256);
				debug.printf("%s\n", buff);
				if (strcmp(buff, "Start\n")) {
					debug.printf("Go !\n");
					break;
				}
			}
		}
	}

	nav->navigate(&route1, -PI / 2);
	nav->navigate(&route2, PI/2);
	nav->navigate(&route3, PI);
	//nav->navigate(&route4, 0);
	//nav->test(0, 0.3, 1., 0.005);

	while (1);
	
	return 0;
}