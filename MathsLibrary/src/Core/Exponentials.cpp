#include "MathsLibrary.h"
#include <iostream>

#define ACCURACY 5
constexpr float e = 2.71828182845f;

float MathsLibrary::Exp(float value) {
//if value is not between 0 and 1
	int numTimesToMultiplyBy = 0;
	float valueBetween0and1 = value;
	if (value < 0.f || value > 1.f) {
		numTimesToMultiplyBy = FloorToInt(value);
		valueBetween0and1 -= (float)numTimesToMultiplyBy;
	}


	return ExpCore(valueBetween0and1) * PowerInt(e,numTimesToMultiplyBy);
}

#define Ln2 0.69314718056f
float MathsLibrary::Log(float value)
{
	//if negative, return 0 - as it is impossible
	if (value < 0.f) {
		return 0.f;
	}
	if (Approx(value, 0.f)) {
		//return infinity
		return NegativeInfinity;
	}
	//use floating point to find the power of two required
	int nearest2toN = ClosestTwoPowerN(value);
	float dividedByNearestPowerOfTwo = DividedByClosestPowerOfTwo(value);
	
	float intApprox = (float)nearest2toN * Ln2;
	float lnRemainder = dividedByNearestPowerOfTwo != 0.f ? FindLnValueBetween1And2(dividedByNearestPowerOfTwo) : 0.f;

	//find nearest power and log that
	return intApprox + lnRemainder;
}

#define LOG10CONVERSION 0.4342944819f
float MathsLibrary::Log10(float value)
{
	return Log(value)*LOG10CONVERSION;
}
