#include "Launcher.hpp"

Launcher::Launcher(PinName _RX, PinName _TX){
	comm = new Comm_AX12(_RX, _TX);
	rightAX = new AX12(0x04, comm);
	leftAX = new AX12(0x01, comm);
	
	leftAX->Init();
	rightAX->Init();
	timerwait = new Timer;
	timerwait->start();
}

Launcher::~Launcher(){
}

void Launcher::on() {
	if (instNav->free_to_move()) {
		rightAX->EndlessTurn(1, 50);
		leftAX->EndlessTurn(0, 50);
	}
}

void Launcher::off() {
	leftAX->EndlessTurn(1, 0);
	rightAX->EndlessTurn(0, 0);
}

void Launcher::my_wait(int ms) {
	timerwait->reset();
	while ((timerwait->read_ms() < ms) && instNav->free_to_move()) {

	}
}

void Launcher::set_nav_ptr(Navigator* _instNav) {
	instNav = _instNav;
}