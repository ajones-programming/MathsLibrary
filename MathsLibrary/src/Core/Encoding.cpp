#include "MathsLibrary.h"
#include <bitset>
#include <cstddef>

//for two byte encoding of float
unsigned short MathsLibrary::FloatToHalf(float value)
{
	//1 for sign, 23 for mantissa, 8 for exponent
	const char* asCharArray = (char*)&value;
	unsigned short output = 0;
	char* outputCharArray = (char*)&output;

	*(outputCharArray + 1) = *(asCharArray + 3) & 0xc0;
	*(outputCharArray + 1) |= (*(asCharArray + 3) & 0x07 )<< 3;
	*(outputCharArray + 1) |= (*(asCharArray + 2) & 0xe0 ) >> 5;
	*(outputCharArray) |= (*(asCharArray + 2) & 0x1f ) << 3;
	*(outputCharArray) |= (*(asCharArray + 1) & 0xe0 ) >> 5;

	return output;
}

float MathsLibrary::HalfToFloat(unsigned short value)
{

	const char* asCharArray = (char*)&value;
	float output = 0.f;
	char* outputCharArray = (char*)&output;
	
	*(outputCharArray + 3) = *(asCharArray + 1) & 0xc0;
	*(outputCharArray + 3) |= (*(asCharArray + 1) & 0x38) >> 3;
	*(outputCharArray + 2) |= (*(asCharArray + 1) & 0x07) << 5;
	*(outputCharArray + 2) |= (*(asCharArray) & 0xf8) >> 3;
	*(outputCharArray + 1) |= (*(asCharArray) & 0x07) << 5;

	return output;
}

