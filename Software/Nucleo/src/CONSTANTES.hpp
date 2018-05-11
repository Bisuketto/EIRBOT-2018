#pragma once

#define PI 3.14159265358979224

//Telemetry Parameters
#define PERIOD_INFO 0.250

//Steppers Parameters
#define DEFAUT_PERIODE_STEPPER 0.002

//Motors Global Parameters
#define PERIODE_PWM 25 //µs
#define ACCELERATION_POS 300.//750.
#define VITESSEMAX_POS 1000.
#define ACCELERATION_ANG PI
#define VITESSEMAX_ANG PI/2
#define V_ALIM_POWER 18
#define TOLERANCE_POS 20 //mm
#define TOLERANCE_ANG 3
#define TIMEOUT 2500 //ms
#define TIME_MARGIN 2500//s
#define DIR_LENGTH 3
#define DIM_PT 2
#define N_PTS 500
#define ANTI_DEAD_ZONE 0.05f

//Encoders Parameters
#define PERIODE_ENCODER 0.0001 //Intervalle de recupÈration ÅEkHz
#define RESOLUTION 4096 // Mecanical parameters
#define PERIMETER 90.14 //94.24
#define RADIUS_ENC 181.25//176.5 //Disance Encodeur-Centre en mm

//7segDisplay Parameters

#define DISP_PERIODE 0.005

//GP2 Parameters

#define THRESHOLD_GP2 0.45
#define THRESHOLD_GP2_SIDE 0.75
#define THRESHOLD_GP2_BACK 0.45
#define ECH_CONFIRM 25

//Global Parameters

#define GAME_TIME 100//secs
#define GAME_MODE true