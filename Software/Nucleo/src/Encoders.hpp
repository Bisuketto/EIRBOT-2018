#ifndef ENCODERS_H
#define ENCODERS_H

#include "CONSTANTES.hpp"
#include "PINOUT.hpp"
#include <math.h>
#include "mbed.h"

class Encoders
{
	public:
		/*
			Creates an Encoder management unit (no initial position set)
		*/
		Encoders();
		/*
			Encoder debug mode
		*/
		Encoders(Serial *pcOut);
		/*
			Creates an Encoder management with initial conditions
		*/
		Encoders(float x0, float y0, float theta_i);
		/*
			Returns right ticks
		*/
		int getImpEncR();
		/*
			Returns left ticks
		*/
		int getImpEncL();
		/*
			Returns X odometry value
		*/
		float getX();
		/*
			Returns Y odometry value
		*/
		float getY();
		/*
			Returns Theta odometry value
		*/
		float getTheta();
		/*
			Returns left encoder travel value
		*/
		int getDl();
		/*
			Returns right encoder travel value
		*/
		int getDr();
		/*
			Resets left and right encoder travel value to start a new dist move
		*/
		void restart_dists();
		/*
			Returns time since the last change
		*/
		float last_changed();
		/*
			Reset the change timer
		*/
		void reset_changed();
		~Encoders();
	private:
		void routine_Encoders();
		void odometrie();
		bool debug;
		Serial *pc;
		int impEncD;
		int impEncG;
		void TIM3_EncoderInit();
		void TIM4_EncoderInit();
		Ticker *scheduler_Encoders;
		Timer* t_changed;
		//Odometer (units in ticks)
		float theta0;
		int dtot_d;
		int dtot_g;
		float dlg;
		float dld;
		float dist_r;
		float dist_l;
		float x;
		float y;
		float theta; //Direction in rads
		float dl;
};

#endif