#ifndef PINOUT_H
#define PINOUT_H

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

//Launcher

#define LAUNCHER_RX PD_6
#define LAUNCHER_TX PD_5

// VL530X I2C

#define I2C_SDA PB_9
#define I2C_SCL PB_8

// Navigator

#define PIN_SIDE PE_15
#define LED_GREEN PB_1
#define LED_RED PC_2

// Comm

#define RF_TX PE_8
#define RF_RX PE_9

// 7segDisplay

#define SSEG_PIN_A PC_8
#define SSEG_PIN_B PC_9
#define SSEG_PIN_C PC_10
#define SSEG_PIN_D PC_11
#define SSEG_PIN_EN1 PC_12
#define SSEG_PIN_EN2 PD_2
#define SSEG_PIN_EN3 PG_2

// GP2

#define PIN_GP2_FL PA_3
#define PIN_GP2_FR PC_0
#define PIN_GP2_SL PC_3
#define PIN_GP2_SR PF_3
#define PIN_GP2_BL PF_5
#define PIN_GP2_BR PF_10

// Others

#define STARTING_CORD PE_0


#endif