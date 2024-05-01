#include "MathsLibrary.h"
#include <iostream>

float MathsLibrary::Abs(const float value)
{
	return value > 0.f ? value : -value;
}

#define APPROX_VALUE 0.0001f

bool MathsLibrary::Approx(const float value, const float toCompareTo)
{
	return Abs(value - toCompareTo) < APPROX_VALUE;
}

float MathsLibrary::Ciel(const float value)
{
	if (value < 0.f) {
		return (float)((int)value);
	}
	float flooredValue = (float)((int)value);
	return flooredValue + (value - flooredValue > APPROX_VALUE ? 1.f : 0.f);
}

int MathsLibrary::CielToInt(const float value)
{
	return (int)Ciel(value);
}

float MathsLibrary::Clamp(const float value, const float minimum, const float maximum)
{
	if (value < minimum) {
		return minimum;
	}
	if (value > maximum) {
		return maximum;
	}
	return value;
}

float MathsLibrary::Clamp01(const float value)
{
	return Clamp(value,0.f,1.f);
}

float MathsLibrary::Floor(const float value)
{
	if (value >= 0.f) {
		return (float)((int)value);
	}
	float flooredValue = (float)((int)value);
	return flooredValue - (value - flooredValue < APPROX_VALUE ? 1.f : 0.f);
}

int MathsLibrary::FloorToInt(const float value)
{
	return (int)Floor(value);
}

float MathsLibrary::Max(const float value1, const float value2)
{
	return value1 > value2 ? value1 : value2;
}

float MathsLibrary::Max(const float values[], const int arraySize)
{
	if (arraySize == 0) {
		return 0.f;
	}
	float maxValue = values[0];
	for (int Count = 1; Count < arraySize; Count++) {
		maxValue = Max(maxValue, values[Count]);
	}
	return maxValue;
}

float MathsLibrary::Min(const float value1, const float value2)
{
	return value1 < value2 ? value1 : value2;
}

float MathsLibrary::Min(const float values[], const int arraySize)
{
	if (arraySize == 0) {
		return 0.f;
	}
	float minValue = values[0];
	for (int Count = 1; Count < arraySize; Count++) {
		minValue = Min(minValue, values[Count]);
	}
	return minValue;
}

#define NUM_REPETITIONS 5
float MathsLibrary::Pow(const float value, const float power)
{
	if (Approx(power, 0.f)) {
		return 1.f;
	}
	if (Approx(value, 0.f)) {
		return 0.f;
	}
	if (Approx(value, 1.f)) {
		return 1.f;
	}
	if (value < 0.f && !Approx(power, (int)power)) {
		//ERROR!
		return 0.f;
	}
	//if integer, do simple multiplication
	if (Approx(power, (float)((int)power)))
	{
		return PowerInt(value, power);
	}

	return Exp(power * Log(value));

}



float MathsLibrary::Round(const float value)
{
	float intValue = Floor(value);
	if (Approx(value, intValue)) {
		return value;
	}

	float difference = value - intValue;
	if (difference > 0.5f) {
		return intValue + 1.f;
	}
	return intValue;
}

float MathsLibrary::RoundToInt(const float value)
{
	float intValue = Floor(value);
	if (Approx(value, intValue)) {
		return value;
	}

	float difference = value - intValue;
	if (difference > 0.5f) {
		return intValue + 1.f;
	}
	return intValue;
}

float MathsLibrary::Sign(const float value)
{
	if (value > 0.f) {
		return 1.f;
	}
	if (value < 0.f) {
		return -1.f;
	}
	return 0.0f;
}

float MathsLibrary::Sqrt(const float value)
{
	return Pow(value,0.5f);
}


