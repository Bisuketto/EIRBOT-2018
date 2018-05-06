#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include "Encoders.hpp"
#include "Motors.hpp"
#include "Telemetry.hpp"
#include <vector>

class Motors;

class Navigator
{
	public:
		/*
			Creates an instance of Navigator unit
		*/
		Navigator();
		/*
			Creates an instance of Navigator unit
		*/
		Navigator(Serial * _debug);
		/*
			Creates an instance of Navigator unit with initials positions
		*/
		Navigator(float _x0, float _y0, float _theta_i);
		/*
			Creates an instance of Navigator unit with initials positions and Telemetry enabled
		*/
		Navigator(Telemetry *_telem, float _x0 = 0, float _y0 = 0, float _theta_i = 0);
		/*
			Creates an instance of Navigator Debug Mode
		*/
		Navigator(float _x0, float _y0, float _theta_i, Serial* _debug);
		/*
			Navigate among the path specified
		*/
		void navigate(std::vector<vector<float> >* _route, float _theta_end);
		/*
			Used by motor instance to signal finished process;
		*/
		void finished();

		void test(float _pwm_low, float _pwm_high, int _t1, float _period);
		void motorDebug();
		~Navigator();
	private:
		bool debug;
		Serial* serialOut;
		Telemetry *instTelem;
		volatile bool status;
		void go_to_i();
		float theta_end;
		int i;
		std::vector<vector<float> >* route;
		Encoders* instEncoders;
		Motors* instMotors;
};

#endif