#pragma once

#include "mbed.h"
#include "REGU_CST.hpp"
#include "CONSTANTES.hpp"
#include "PINOUT.hpp"
#include "Encoders.hpp"
#include "Navigator.hpp"
#include <math.h>
#include <vector>

class Navigator;

class Motors {
	public:
		/*
			Creates an instance of Motor Controller unit
		*/
		Motors(PinName _pwmL, PinName _pwmR, PinName _dirL, PinName _dirR);
		/*
			Motor controller debug mode
		*/
		Motors(PinName _pwmL, PinName _pwmR, PinName _dirL, PinName _dirR, Serial* _debug);
		/*
			Go to Point (x,y) Rectilinear Speed QuadRamp mode
		*/
		void go_to_RSQR(float _x, float _y);
		/*
			Rotation of _ang rads
		*/
		void rotate(float _ang);
		/*
			Set pointer to Encoders instance
		*/
		void set_Enc_ptr(Encoders* _enc);
		/*
			Set pointer to Navigator instance
		*/
		void set_Nav_ptr(Navigator* _instNav);
		/*
			Stops immediately current job
		*/
		void hard_stop();

		void identify(float _pwm_low, float _pwm_high, int _t1, float _period);
		~Motors();

	private:
		void routine();
		void send_i();
		void tab_push(float _x, float* _tab, int _l);
		void tab_push(float *_p, float** _tab, int _l);
		void tab_init(float* _tab, int _l);
		void tab_init(float** _tab, int _l);
		void reset_data();
		float pos_reference_calculation_RSQR();
		float ang_reference_calculation();
		void calc_pos_inter();
		void to_H_bridgeable(float* _right_cmd, float* _left_cmd);
		void dead_zone();
		void stop();
		void comStop();
		int location();

		void identifier_routine();
		float mes[N_PTS];
		float periode;
		int index;

		bool debug;
		bool status;
		bool RSQR;
		bool ROT;
		float x_reference;
		float y_reference;
		float x_init;
		float y_init;
		float xi;
		float yi;
		float theta_i;
		float pos_reference;
		float ang_reference;
		float pos_cmd[TAILLE_TABLEAUX_POS];
		float ang_cmd[TAILLE_TABLEAUX_ANG];
		float pos_err[TAILLE_TABLEAUX_POS];
		float ang_err[TAILLE_TABLEAUX_ANG];
		float* director[DIR_LENGTH];
		Serial* serialOut;
		Ticker* schedule_routine;
		Ticker* schedule_infos;
		Timer* t_cmd;
		Encoders* instEncoders;
		PwmOut* right_motor;
		PwmOut* left_motor;		
		DigitalOut* dir_right;
		DigitalOut* dir_left;
		Navigator* instNav;
		int dr;
		int dl;
		float pwr;
		float pwl;
		float p_tmp[DIM_PT];
};