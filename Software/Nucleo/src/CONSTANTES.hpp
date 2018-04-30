#pragma once

#define PI 3.14159265358979224

//Telemetry Parameters
#define PERIOD_INFO 0.250

//Steppers Parameters
#define DEFAUT_PERIODE_STEPPER 0.002

//Motors Global Parameters
#define PERIODE_PWM 25 //µs
#define ACCELERATION_POS 750.
#define VITESSEMAX_POS 500.
#define ACCELERATION_ANG PI/2
#define VITESSEMAX_ANG PI/2
#define V_ALIM_POWER 18
#define TOLERANCE_POS 20 //mm
#define TOLERANCE_ANG 1
#define TIMEOUT 1000 //ms
#define DIR_LENGTH 3
#define DIM_PT 2
#define N_PTS 500

//Encoders Parameters
#define PERIODE_ENCODER 0.0001 //Intervalle de recupÈration ÅEkHz
#define RESOLUTION 4096 // Mecanical parameters
#define PERIMETER 90.14 //94.24
#define RADIUS_ENC 181.25//176.5 //Disance Encodeur-Centre en mm