#pragma once

#include "mbed.h"

// Steppers

#define STEPPER_COIL_1A PF_12 //
#define STEPPER_COIL_1B PD_15
#define STEPPER_COIL_2C PE_9
#define STEPPER_COIL_2D PF_13 //
#define STEPPER_EN1 PE_11
#define STEPPER_EN2 PD_14

//Encoders

#define PIN_TIM3_CH1 PA_7
#define PIN_TIM3_CH2 PA_6
#define PIN_TIM4_CH1 PD_12
#define PIN_TIM4_CH2 PD_13

// Motors

#define PIN_PWMD PB_11
#define PIN_PWMG PB_10
#define PIN_SENSMD PF_13
#define PIN_SENSMG PF_12