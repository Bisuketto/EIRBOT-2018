#include "Telemetry.hpp"

Telemetry::Telemetry(){
	debug = false;
	out = new Serial(USBTX, USBRX, 115200);
}

Telemetry::Telemetry(Serial *_debug) {
	debug = true;
	out = _debug;
}

Telemetry::~Telemetry(){
}

void Telemetry::float_to_hex(float _fin, char *_str, int _start) {
	union { float f_val; unsigned int b_val; };
	f_val = _fin;
	unsigned int mask = 0x000000FF;
	for (int i = 0; i < 4; i++) {
		_str[3 - i + _start] = (b_val >> (8 * i)) & mask;
	}
}

void Telemetry::short_to_hex(short int _iin, unsigned char *_str, int _start) {
	short int mask = 0x00FF;
	for (int i = 0; i < 2; i++) {
		_str[3 - i + _start] = (_iin >> (8 * i)) & mask;
	}
}

void Telemetry::int_to_hex(int _iin, unsigned char *_str, int _start) {
	int mask = 0x000000FF;
	for (int i = 0; i < 4; i++) {
		_str[3 - i + _start] = (_iin >> (8 * i)) & mask;
	}
}

float Telemetry::hex_to_float(char *_str, int _start) {
	union {unsigned int b_val; float f_val; };
	b_val = 0;
	for (int i = 0; i < 4; i++) {
		b_val |= ((int) _str[3 - i + _start]) << (8 * i);
	}
	return f_val;
}

short int Telemetry::hex_to_short(char *_str, int _start) {
	short int i_val = 0;
	for (int i = 0; i < 2; i++) {
		i_val |= ((short int)_str[1 - i + _start]) << (8 * i);
	}
	return i_val;
}

int Telemetry::hex_to_int(char *_str, int _start) {
	int i_val = 0;
	for (int i = 0; i < 4; i++) {
		i_val |= ((int)_str[3 - i + _start]) << (8 * i);
	}
	return i_val;
}

void Telemetry::send_PONG(){
	char str[] = { TELEM_CODE_PONG };
}

void Telemetry::send_PWM(float _pwmL, float _pwmR){
	/*unsigned char datagram[3];
	datagram[0] = TELEM_CODE_PWM;
	short_to_hex(8, datagram, 1);
	int crc_datagram = crc32c(0x00000000, datagram, 3);
	unsigned char data[8];
	int_to_hex(_pwmL, data, 0);
	int_to_hex(_pwmR, data, 4);
	int crc_data = crc32c(0x00000000, data, 8);

	unsigned char frame[19] = { datagram[0], datagram[1], datagram[2], 0, 0, 0, 0, data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], 0, 0, 0, 0 };
	int_to_hex(crc_datagram, frame, 3);
	int_to_hex(crc_data, frame, 16);*/

	char str[9];
	str[0] = TELEM_CODE_PWM;
	float_to_hex(_pwmL, str, 1);
	float_to_hex(_pwmR, str, 5);
	send(str, 9);
}

void Telemetry::send_COORD(float _x, float _y){
	char str[9];
	str[0] = TELEM_CODE_COORD;
	float_to_hex(_x, str, 1);
	float_to_hex(_y, str, 5);
	send(str, 9);
}

void Telemetry::send_VOLT(float _v18, float _v9){
	char str[9];
	str[0] = TELEM_CODE_VOLT;
	float_to_hex(_v18, str, 1);
	float_to_hex(_v9, str, 5);
	send(str, 9);
}

void Telemetry::send_CURR(){
	char str[9];
	str[0] = TELEM_CODE_CURR;
	float_to_hex(42.42, str, 1);
	float_to_hex(42.42, str, 5);
	send(str, 9);
}

void Telemetry::send_TXT(char * _txt){
}

void Telemetry::send_ACK(char _ackCode){
	char str[2];
	str[0] = TELEM_CODE_ACK;
	str[1] = _ackCode;
	send(str, 2);
}

void Telemetry::send_ANG(float _ang){
	char str[5];
	str[0] = TELEM_CODE_ANG;
	float_to_hex(_ang, str, 1);
	send(str, 5);
}

void Telemetry::send_ERR(float _epsPos, float _epsAng){
	char str[9];
	str[0] = TELEM_CODE_ERR;
	float_to_hex(_epsPos, str, 1);
	float_to_hex(_epsAng, str, 5);
	send(str, 9);
}

void Telemetry::send_ENC(int _encL, int _encR){
	unsigned char str[9];
	str[0] = TELEM_CODE_ENC;
	int_to_hex(_encL, str, 1);
	int_to_hex(_encR, str, 5);
	send((char*) str, 9);
}

void Telemetry::send_TIME(float _t){
	char str[5];
	str[0] = TELEM_CODE_TIME;
	float_to_hex(_t, str, 1);
	send(str, 5);
}

void Telemetry::send_STAT(){
}

void Telemetry::send(char *_str, int _length) {
	//out->printf("%c%c%c%c%c%c%c%c%c", _str[0], _str[1], _str[2], _str[3], _str[4], _str[5], _str[6], _str[7], _str[8]);
	for (int i = 0; i < _length; i++) {
		out->putc(_str[i]);
	}
}

void Telemetry::receive() {
}