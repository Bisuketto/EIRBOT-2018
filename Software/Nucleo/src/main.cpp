#include "mbed.h"
#include "Stepper.hpp"
#include "Motors.hpp"
#include "PINOUT.hpp"
#include "Navigator.hpp"
#include "CONSTANTES.hpp"
#include "Telemetry.hpp"
#include "Launcher.hpp"
#include "rtos.h" //Maybe used in the future
//#include "Adafruit_VL53L0X_Nucleo.h"
#include "SevSegDisplay.hpp"
#include "GP2.hpp"


int main() {
	bool debugging = true;

	DigitalIn btn(USER_BUTTON);
	DigitalIn tirette(STARTING_CORD);
	Serial debug(USBTX, USBRX, 115200);

	/*while (1) {
		debug.printf("Tirette : %s\n", (tirette.read() == true) ? "Mise" : "Retiree");
		wait(0.25);
	}*/

	Telemetry instTelem(&debug);

	if (debugging)
		debug.printf("\n\nTesutou Puroguramu !\n");

	/*GP2* instGp2 = new GP2(PIN_GP2_FL, PIN_GP2_FR, PIN_GP2_SL, PIN_GP2_SR, &debug);
	bool tooclose;
	while (1) {
		tooclose = instGp2->too_close();
		debug.printf("Too close : %s\n", (tooclose) ? "yes" : "no");
		wait(0.25);
	}*/

	if (debugging)
		debug.printf("7Seg Display Test\n");
	SevSegDisplay sseg(SSEG_PIN_A, SSEG_PIN_B, SSEG_PIN_C, SSEG_PIN_D, SSEG_PIN_EN1, SSEG_PIN_EN2, SSEG_PIN_EN3);
	/*for (int i = 0; i <= 999; i++) {
		sseg.display(i);
		wait(0.5);
	}*/
	sseg.display(10);
	//wait(5);
	//sseg.stop();
	if (debugging)
		debug.printf("7Seg Display : [Ok]\n");

	if (debugging)
		debug.printf("VL53L0X Test\n");
	//I2C* i2ctest = new I2C(I2C_SDA, I2C_SCL);
	/*i2ctest->start();
	i2ctest->write(0x29);
	i2ctest->write(0xC0);
	i2ctest->stop();*/
	/*i2ctest->start();
	i2ctest->write(0x29 + 1);
	char res = i2ctest->read(1);
	i2ctest->stop();*/
	/*char index[1];
	index[0] = 0x61;
	char res[2];
	i2ctest->write(0x29 << 1, index, 1);
	i2ctest->read(0x29 << 1, res, 2);

	debug.printf("Value of 0x61 : %X, %X\n", res[0], res[1]);

	index[0] = 0xC1;
	i2ctest->write(0x29 << 1, index, 1);
	i2ctest->read(0x29 << 1, res, 1);

	debug.printf("Value of 0xC1 : %X\n", res[0]);

	index[0] = 0x51;
	i2ctest->write(0x29 << 1, index, 1);
	i2ctest->read(0x29 << 1, res, 2);

	debug.printf("Value of 0x51 : %X, %X\n", res[0], res[1]);

	while (1);
	/*VL53L0X_i2c_init(&debug);
	char data[4];
	VL53L0X_read_byte(0x29, 0xC1, (uint8_t*) data);
	debug.printf("Value of 0xC1 %X\n", data[0]);
	while (1);*/
	//VL53L0X_RangingMeasurementData_t measure;
	//Adafruit_VL53L0X lox = Adafruit_VL53L0X();
	//bool initok = lox.begin(VL53L0X_I2C_ADDR);
	//debug.printf("Ok : %s\n", (initok == true) ? "True" : "False");
	//debug.printf("AdrrChange : %s\n", (lox.setAddress(0x42) == true) ? "True" : "False");
	//while (1);
	/*if (initok) {
		for (int i = 0; i < 5; i++) {
			lox.rangingTest(&measure, false);
			if (debugging)
				debug.printf("MESURE : %d\n", measure.RangeMilliMeter);
			wait(2);
		}
	}*/
	if (debugging)
		debug.printf("VL53L0X [Ok]\n");

	DigitalOut green(LED1);
	if (debugging)
		debug.printf("Launcher initialization\n");

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

	if (debugging)
		debug.printf("Waiting for start\n\n");

	while (tirette.read() == false);

	char buff[256];
	while (btn.read() == 0 && (tirette.read() == true)) {
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

	Navigator* nav;

	if (debugging)
		//nav = new Navigator(125, 650-175, 0, &debug); 
		//nav = new Navigator(0,0,0, &debug);
		//nav = new Navigator(225, 500, PI / 2, &debug);
		nav = new Navigator(125, 350, 0, &debug);
	else
		nav = new Navigator(&instTelem);
	DigitalOut red(LED3);
	red.write(1);

	Launcher launcherTest(LAUNCHER_RX, LAUNCHER_TX);
	launcherTest.set_nav_ptr(nav);
	if (debugging) {
		debug.printf("Launcher : [Ok]\n");
		debug.printf("Enabling launcher for 10s\n");
	}
	launcherTest.on();
	//wait(1);
	if (debugging)
		debug.printf("Disabling launcher\n");
	launcherTest.off();

	/*std::vector<vector<float> > route1;
	std::vector<float> p11(2, 0);
	p11[0] = 1000;
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
	route4.push_back(p41);*/

	/*std::vector<vector<float> > omologation;
	std::vector<float> pom1(2, 0);
	pom1[0] = 250;
	pom1[1] = 650 - 175;
	omologation.push_back(pom1);
	std::vector<float> pom2(2, 0);
	pom2[0] = 825;
	pom2[1] = 1190;
	omologation.push_back(pom2);
	std::vector<float> pom3(2, 0);
	pom3[0] = 825;
	pom3[1] = 275;//400
	omologation.push_back(pom3);*/

	/*std::vector<vector<float> > firstmatch1;
	std::vector<float> sq1(2, 0);
	sq1[0] = 225;
	sq1[1] = 1500;
	firstmatch1.push_back(sq1);

	std::vector<vector<float> > firstmatch10;
	std::vector<float> sq2(2, 0);
	sq2[0] = 800;
	sq2[1] = 1500;
	firstmatch10.push_back(sq2);
	std::vector<float> sq3(2, 0);
	sq3[0] = 1400;
	sq3[1] = 900;
	firstmatch10.push_back(sq3);
	std::vector<float> sq4(2, 0);
	sq4[0] = 1130;
	sq4[1] = 400;
	firstmatch10.push_back(sq4);

	std::vector<vector<float> > firstmatch11;
	std::vector<float> sq111(2, 0);
	sq111[0] = 1130;
	sq111[1] = 125;
	firstmatch11.push_back(sq111);

	std::vector<vector<float> > firstmatch2;
	std::vector<float> sq21(2, 0);
	sq21[0] = 850;
	sq21[1] = 1190;
	firstmatch2.push_back(sq21);
	std::vector<float> sq22(2, 0);
	sq22[0] = 850;
	sq22[1] = 250;
	firstmatch2.push_back(sq22);*/

	std::vector<vector<float> > daytwo1;
	std::vector<float> p1(2, 0);
	p1[0] = 1110;
	p1[1] = 350;
	daytwo1.push_back(p1);
	std::vector<float> p12(2, 0);
	p12[0] = 1110;
	p12[1] = 130;
	daytwo1.push_back(p12);
	std::vector<vector<float> > daytwo2;
	std::vector<float> p3(2, 0);
	p3[0] = 1400;
	p3[1] = 1000;
	daytwo2.push_back(p3);
	std::vector<float> p4(2, 0);
	p4[0] = 850;
	p4[1] = 1100;
	daytwo2.push_back(p4);
	std::vector<vector<float> > daytwo22;
	std::vector<float> p5(2, 0);
	p5[0] = 850;
	p5[1] = 241;
	daytwo22.push_back(p5);
	std::vector<vector<float> > daytwo3;
	std::vector<float> p7(2, 0);
	p7[0] = 500;
	p7[1] = 1700;
	daytwo3.push_back(p7);
	std::vector<float> p8(2, 0);
	p8[0] = 180;
	p8[1] = 1500;
	daytwo3.push_back(p8);
	std::vector<vector<float> > daytwo4;
	std::vector<float> p9(2, 0);
	p9[0] = 180;
	p9[1] = 241;
	daytwo4.push_back(p9);



	//nav->motorDebug();
	//nav->navigate(&route1, PI);
	//lox.rangingTest(&measure, false);
	//if (debugging)
	//	debug.printf("MESURE : %d\n", measure.RangeMilliMeter);
	//nav->navigate(&route2, PI/2);
	//nav->navigate(&route3, PI);
	//nav->navigate(&route4, 0);
	//nav->test(0, 0.3, 1., 0.005);
	//nav->navigate(&omologation, -PI / 2);
	//nav->move_backward(500);
	//nav->rotate(PI);

	/*nav->set_detection(false);
	nav->navigate(&firstmatch1, PI/2);
	sseg.display(20);
	nav->set_detection(true);
	nav->navigate(&firstmatch10, -PI/2);
	nav->set_detection(false);
	nav->navigate(&firstmatch11, -PI/2);
	sseg.display(45);
	nav->set_detection(true);
	nav->move_backward(375);
	nav->navigate(&firstmatch2, -PI/2);
	sseg.display(48);*/

	sseg.display(10);
	nav->set_detection(false);
	nav->navigate(&daytwo1, -PI / 2);
	sseg.display(35);
	nav->move_backward(220);
	nav->rotate(PI / 2);
	nav->set_detection(true);
	nav->navigate(&daytwo2, -PI/2);
	nav->set_detection(false);
	nav->navigate(&daytwo22, -PI/2);
	sseg.display(38);
	nav->move_backward(359);
	nav->set_detection(true);
	nav->navigate(&daytwo3, -PI / 2);
	nav->set_detection(false);
	nav->navigate(&daytwo4, -PI/2);
	sseg.display(50);
	nav->set_detection(true);

	while (1);
	
	return 0;
}