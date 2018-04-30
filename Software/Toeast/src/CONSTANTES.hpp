#pragma once

#define PI 3.14159265358979224

//Steppers Parameters
#define DEFAUT_PERIODE_STEPPER 0.002

//Motors Global Parameters
#define PERIODE_PWM 25 //µs
#define ACCELERATION_POS 100.
#define VITESSEMAX_POS 200.
#define ACCELERATION_ANG 70000.
#define VITESSEMAX_ANG 150000.
#define V_ALIM_POWER 18
#define TOLERANCE_POS 100 //mm
#define TOLERANCE_ANG 1
#define TIMEOUT 5000 //ms
#define DIR_LENGTH 3
#define DIM_PT 2
#define N_PTS 500

//Encoders Parameters
#define PERIODE_ENCODER 0.0005 //Intervalle de recupÈration Å2kHz
#define RESOLUTION 4096 // Mecanical parameters
#define PERIMETER 94.24
#define RADIUS_ENC 142.5 //Disance Encodeur-Centre en mm