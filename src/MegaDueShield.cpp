#include "MegaDueShield.h"

MegaDueShield::MegaDueShield()
{
	// activate motor driver m7/8
	pinMode(STBY_78, OUTPUT);
	digitalWrite(STBY_78, HIGH);

	// Extension 5V logic power supply
	pinMode(a10P_6, OUTPUT);
	digitalWrite(a10P_6, HIGH);

	pinMode(RGB_RED, OUTPUT);
	pinMode(RGB_GREEN, OUTPUT);
	pinMode(RGB_BLUE, OUTPUT);
}

MegaDueShield::~MegaDueShield()
{
	for(DC_Motor* mot : dcMotors)
	{
		delete mot;
	}
}

void MegaDueShield::rgb(uint8_t r, uint8_t g, uint8_t b)
{
	analogWrite(RGB_RED, r);
	analogWrite(RGB_GREEN, g);
	analogWrite(RGB_BLUE, b);
}

void MegaDueShield::rgbOff()
{
	analogWrite(RGB_RED, LOW);
	analogWrite(RGB_GREEN, LOW);
	analogWrite(RGB_BLUE, LOW);
}

/* Returns a pointer to a DC_Motor object. If the motor has not been initialized yet,
* 	allocate memory for a new DC_Motor instance and initialize it.
*
*/
DC_Motor *MegaDueShield::getDCMotor(uint8_t motor_id)
{
	if (motor_id < 1 || motor_id > 8)
	{
		return nullptr;
	}
	motor_id--;

	// initialize a new motor, if the requested motor does not exist yet
	if (dcMotors[motor_id] == nullptr)
	{
		dcMotors[motor_id] = new L293D(dcMotorPins[motor_id][0], dcMotorPins[motor_id][1], dcMotorPins[motor_id][2]);
	}
	return dcMotors[motor_id];
}

DCOutput *MegaDueShield::getDCOutput(uint8_t outputID)
{
	if (outputID < 1 || outputID > 16)
		return NULL;
	outputID--;
	uint8_t param;
	if (outputID % 2 == 0)
	{
		outputID /= 2;
		param = 1;
	}
	else
	{
		outputID -= 1;
		outputID /= 2;
		outputID += 1;
		param = 2;
	}
	dcOutputs[outputID]->setL293D(dcMotorPins[outputID][0], dcMotorPins[outputID][param]);
	return dcOutputs[outputID];
}

StepperMotor *MegaDueShield::getStepper(uint8_t stepperID)
{
	if (stepperID < 1 || stepperID > 2)
		return NULL;
	stepperID--;
	steppers[stepperID].setMotor(stepperPins[stepperID][0], stepperPins[stepperID][1], stepperPins[stepperID][2], stepperPins[stepperID][3]);
	return &steppers[stepperID];
}
