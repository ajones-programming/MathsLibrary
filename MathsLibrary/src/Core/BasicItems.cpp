#include "MathsLibrary.h"
#include <iostream>

constexpr float  APPROX_VALUE = 0.0001f;

float MathsLibrary::Abs(const float value)
{
	return value > 0.f ? value : -value;
}



bool MathsLibrary::Approx(const float value, const float toCompareTo)
{
	return Abs(value - toCompareTo) < APPROX_VALUE;
}

float MathsLibrary::Ceil(const float value)
{
	float flooredValue = ((int)value);
	if (value < 0.f) {
		return flooredValue;
	}
	return flooredValue + (value - flooredValue > APPROX_VALUE ? 1.f : 0.f);
}

int MathsLibrary::CeilToInt(const float value)
{
	return Ceil(value);
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

//change to saturate??
float MathsLibrary::Clamp01(const float value)
{
	return Clamp(value,0.f,1.f);
}

float MathsLibrary::Floor(const float value)
{
	if (value >= 0.f) {
		return ((int)value);
	}
	float flooredValue = ((int)value);
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
		return value;
	}
	if (value < 0.f) {
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

float MathsLibrary::Pow(const float value, const int toPowerOf)
{
	return PowerInt(value, toPowerOf);
}

int MathsLibrary::Pow(const int value, const int toPowerOf)
{
	return PowerInt(value, toPowerOf);
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


//QUAKE 3 FUN!! MAGIC NUMBER????
# include <bit>
# include <limits>
# include <cstdint>

constexpr float Q_rsqrt(float number) noexcept
{
	static_assert(std::numeric_limits<float>::is_iec559); // (enable only on IEEE 754)

	float const y = std::bit_cast<float>(
		0x5f3759df - (std::bit_cast<std::uint32_t>(number) >> 1));
	return y * (1.5f - (number * 0.5f * y * y));
}

//QUAKE 3 FAST INVERSE SQUARE ROOT
//IMPLEMENTATION CREDIT TO https://en.wikipedia.org/wiki/Fast_inverse_square_root
float MathsLibrary::Sqrt(const float value)
{
	return 1.f / Q_rsqrt(value);
}