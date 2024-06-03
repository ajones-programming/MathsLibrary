#include "MathsLibrary.h"
#include <iostream>

float MathsLibrary::PowerInt(float value, int power) {
	if (Approx(power, 0.f) || Approx(value,0.f)) {
		return 1.f;
	}
	bool isPos = power > 0;
	int absolutePower;
	float multiplyIteration;
	if (isPos) {
		absolutePower = power;
		multiplyIteration = value;
	}
	else {
		absolutePower = -power;
		multiplyIteration = 1.f / value;
	}

	float beginningPoint = 1.f;
	for (int Count = 0; Count < absolutePower; Count++) {
		beginningPoint *= multiplyIteration;
	}
	return beginningPoint;
}

float MathsLibrary::DecimalPower(float value, float decimalPower) {

	return Exp(decimalPower * Log(value));
}

//ASSUMING VALUE IS BETWEEN 0 AND 1
constexpr int ACCURACY{ 6 };
constexpr float e{ 2.71828182845f };
float MathsLibrary::ExpCore(float value)
{
	//simd?
	float total = 0.f;
	int totalDivider = 1;
	float iteratorMultiply = 1.f;
	float valueToMultiplyBy = value > 0.55 ? value - 1 : value;
	for (int Count = 0; Count < ACCURACY; Count++) {
		if (Count > 0) {
			totalDivider *= Count;
		}
		float thisTotal = iteratorMultiply / (float)(totalDivider);
		iteratorMultiply *= valueToMultiplyBy;
		total += thisTotal;
	}
	return value > 0.55 ? total * e : total;
}

float MathsLibrary::totalTaylorSeries__DivisionPrecalculated(float value, float taylor_values[ACCURACY])
{
	float startingMultiplicationVal = 1.f;
	float total = 0.f;
	for (int Count = 0; Count < ACCURACY; Count++) {
		total += taylor_values[Count] * startingMultiplicationVal;
		startingMultiplicationVal *= value;
	}
	return total;
}

float MathsLibrary::totalTaylorSeries__DivisionPrecalculated(float value, float* taylor_values, int size)
{
	float startingMultiplicationVal = 1.f;
	float total = 0.f;
	for (int Count = 0; Count < size; Count++) {
		total += taylor_values[Count] * startingMultiplicationVal;
		startingMultiplicationVal *= value;
	}
	return total;
}

int MathsLibrary::ClosestTwoPowerN(float value)
{
	float_cast currentFloat = float_cast();
	currentFloat.f = value;
	return (int)currentFloat.parts.exponent - 127;
}

float MathsLibrary::DividedByClosestPowerOfTwo(float value)
{
	float_cast currentFloat = float_cast();
	currentFloat.f = value;
	if (currentFloat.parts.mantisa == 0) {
		return 0.f;
	}
	currentFloat.parts.exponent = 127;
	return currentFloat.f;
}


#define LOG_ACCURACY_SERIES 5
float MathsLibrary::FindLnValueBetween1And2(float value)
{

	if (value < 1.5f) {
		float excess = value - 1.f;
		float total = 0.f;
		float powerResult = 1.f;
		for (int Count = 1; Count < LOG_ACCURACY_SERIES + 1; Count++) {
			//if count is even
			int multiplyBy = Count % 2 == 1 ? 1 : -1;
			powerResult *= excess;
			float thisIterationValue = powerResult * (float)multiplyBy / (float)Count;
			total += thisIterationValue;
		}
		return total;
	}

	else {
		float newVal = value - 2.f;
		float VALUES_LIST[7] = {0.6931471806f,0.5f,-0.125f,0.0416416416f,-0.015625f, 6.25e-3,-2.6041667e-3 };
		return totalTaylorSeries__DivisionPrecalculated(newVal, VALUES_LIST,7);
	}

}