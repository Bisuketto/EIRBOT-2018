#ifndef TELEMETRY_H
#define TELEMETRY_H

#include "mbed.h"
#include "crc32.h"
#include "TELEM_CODE.hpp"

class Telemetry {
	public:
		Telemetry();
		Telemetry(Serial *_debug);
		~Telemetry();
		/*
			Write a converted float in 4 chars (big-endian) to a char array beginning on the specified character
		*/
		static void float_to_hex(float _fin, char *_str, int _start = 0);
		/*
			Write a converted short in 2 chars (big-endian) to a char array beginning on the specified character
		*/
		static void short_to_hex(short int _iin, unsigned char *_str, int _start = 0);
		/*
			Write a converted int in 4 chars (big-endian) to a char array beginning on the specified character
		*/
		static void int_to_hex(int _iin, unsigned char *_str, int _start = 0);
		/*
			Return a converted float from 4 chars (big-endian) beginning on the specified character
		*/
		static float hex_to_float(char *_str, int _start = 0);
		/*
			Return a converted short from 2 chars (big-endian) beginning on the specified character
		*/
		static short int hex_to_short(char *_str, int _start);
		/*
			Return a converted int from 4 chars (big-endian) beginning on the specified character
		*/
		static int hex_to_int(char *_str, int _start = 0);
		/*
			Sends PONG signal
		*/
		void send_PONG();
		/*
			Sends PWM Left and Right
		*/
		void send_PWM(float _pwmL, float _pwmR);
		/*
			Sends robot Coordonates (x,y)
		*/
		void send_COORD(float _x, float _y);
		/*
			Sends batteries voltages
		*/
		void send_VOLT(float _v18, float _v9);
		/*
			Sends batteries currents
		*/
		void send_CURR();
		/*
			Sends text
		*/
		void send_TXT(char *_txt);
		/*
			Sends acknowledge signal
		*/
		void send_ACK(char _ackCode);
		/*
			Sends robot's angular position
		*/
		void send_ANG(float _ang);
		/*
			Sends angular and position errors
		*/
		void send_ERR(float _epsPos, float _epsAng);
		/*
			Sends encoders ticks
		*/
		void send_ENC(int _encL, int _encR);
		/*
			Sends current robot Time
		*/
		void send_TIME(float _t);
		/*
			Sends robot status
		*/
		void send_STAT();
	private:
		bool debug;
		void send(char *_str, int _length);
		void receive();

		Serial *out;
};

#endif