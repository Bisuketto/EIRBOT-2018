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


int main() {
	bool debugging = true;

	DigitalIn btn(USER_BUTTON);
	Serial debug(USBTX, USBRX, 115200);


	Telemetry instTelem(&debug);

	if (debugging)
		debug.printf("\n\nTesutou Puroguramu !\n");

	if (debugging)
		debug.printf("7Seg Display Test\n");
	SevSegDisplay sseg(SSEG_PIN_A, SSEG_PIN_B, SSEG_PIN_C, SSEG_PIN_D, SSEG_PIN_EN1, SSEG_PIN_EN2, SSEG_PIN_EN3);
	sseg.display(586);
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


	nav->motorDebug();
	//nav->navigate(&route1, -PI / 2);
	//lox.rangingTest(&measure, false);
	//if (debugging)
	//	debug.printf("MESURE : %d\n", measure.RangeMilliMeter);
	//nav->navigate(&route2, PI/2);
	//nav->navigate(&route3, PI);
	//nav->navigate(&route4, 0);
	//nav->test(0, 0.3, 1., 0.005);

	while (1);
	
	return 0;
}