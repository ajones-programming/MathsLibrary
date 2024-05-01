#include "MathsLibrary.h"

float MathsLibrary::ClosestPowerOfTwo(float value)
{
	if (value <= 0.f) {
		return 0.f;
	}
	float_cast currentFloat = float_cast();
	currentFloat.f = value;
	currentFloat.parts.mantisa = 0;
	return currentFloat.f;

}

bool MathsLibrary::IsPowerOfTwo(float value)
{
	float_cast currentFloat = float_cast();
	currentFloat.f = value;
	return currentFloat.parts.mantisa == 0 && value > 0.f;
}

float MathsLibrary::NextPowerOfTwo(float value)
{
	if (value <= 0.f) {
		return 0.f;
	}
	float_cast currentFloat = float_cast();
	currentFloat.f = value;
	currentFloat.parts.mantisa = 0;
	currentFloat.parts.exponent = currentFloat.parts.exponent + 1;
	return currentFloat.f;
}
