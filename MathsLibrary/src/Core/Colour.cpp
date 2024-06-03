#include "MathsLibrary.h"

//float MathsLibrary::CorrolatedColourTemperatureToRPG(float)
//{
//	return 0.0f;
//}


//these two functions may be wrong, as I have not used these before
float MathsLibrary::GammaToLinearSpace(float value)
{
	if (value < 0.f || value > 1.f) {
		return 0.f;
	}
	return Pow(value, 2.2f);
}

float MathsLibrary::LinearToGammaSpace(float value)
{
	if (value < 0.f || value > 1.f) {
		return 0.f;
	}
	return Pow(value,0.454545454f);
}
