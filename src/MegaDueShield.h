/**
* MegaDueShield.h: 
*
* (C) 2018 by David Holtz
* Version 1.1 (March 2018)
* version 1.2 (April 2020)
*
*/

// I/O definition

#ifndef _MegaDueShield_H_
#define _MegaDueShield_H_

#define I1 A2
#define I2 A5
#define I3 A4
#define I4 A7
#define I5 A10
#define I6 A11
#define I7 A12
#define I8 A13

#define D1 17
#define D2 16
#define D3 15
#define D4 23

#define C1 3
#define C2 2
#define C3 18
#define C4 19
#define SDA_PIN 20
#define SCL_PIN 21

#define RGB_RED 14
#define RGB_GREEN 13
#define RGB_BLUE 12

// Extension (generic)
#define a10P_1 45
#define a10P_3 47
#define a10P_5 49
#define a10P_6 48
#define a10P_7 51
#define a10P_8 50
#define a10P_9 53
#define a10P_10 52

#define STBY_78 30

#include "Arduino.h"
#include "StepperMotor.h"
#include "DC_Motor.h"
#include "L293D.h"
#include "DCOutput.h"

class MegaDueShield
{
private:
	// {chipEnable, input1, input2}
	const uint8_t dcMotorPins[8][3] = {
		{9, A0, A1},
		{8, A3, 40},
		{7, A9, A8},
		{10, 31, 33},
		{11, 27, 22},
		{6, 46, 44},
		{5, 32, 34},
		{4, 28, 26}};

	// {stepPin, directionPin, msPin, stbyPin}
	const uint8_t stepperPins[2][4] = {
		{a10P_10, a10P_8, a10P_7, a10P_9},
		{a10P_3, a10P_1, a10P_5, a10P_9}};

	DC_Motor *dcMotors[8]{nullptr};
	DCOutput *dcOutputs[16]{nullptr};
	StepperMotor steppers[2];

public:
	MegaDueShield();
	~MegaDueShield();

	void rgb(uint8_t r, uint8_t g, uint8_t b);
	void rgbOff();

	DC_Motor *getDCMotor(uint8_t motor_id);
	DCOutput *getDCOutput(uint8_t outputID);
	StepperMotor *getStepper(uint8_t stepperID);
};

#endif
