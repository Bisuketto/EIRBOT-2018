#pragma once

#include "mbed.h"
#include "CONSTANTES.h"

enum status {stop, phase1, phase2, phase3, phase4};

/*
	Basic control of a stepper motor in full-step drive
*/
class Stepper {
	public:
		/*
			Create an instance of a stepper. A, B, C, D pins to control phases. EN are enable coils pins.
		*/
		Stepper(PinName _A, PinName _B, PinName _C, PinName _D, PinName _en1, PinName _en2);
		~Stepper();
		/*
			Drives motor with the chosen direction
		*/
		void on(bool _sens);
		/*
			Lock motor in position
		*/
		void lock_mot(bool _locked);
		/*
			Stop the motor (no couple)
		*/
		void stop_mot();
		/*
			Set the rotate speed given the phase period
		*/
		void vitesse(float _period);

	private:
		void routine();

		Ticker *schedule;
		float period;
		DigitalOut *A;
		DigitalOut *B;
		DigitalOut *C;
		DigitalOut *D;
		DigitalOut *en1;
		DigitalOut *en2;
		status current_state;
		bool lock;
		bool sens;
};