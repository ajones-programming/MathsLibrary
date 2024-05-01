#include "Tests.h"
#include "MathsLibrary.h"
#include <iostream>
#include <chrono>
#include <numbers>
#include <cmath>

# define M_PI           3.14159265358979323846  /* pi */

////Deg2Rad	Degrees - to - radians conversion constant(Read Only).
//static float Deg2Rad(float);
void Tests::DegToRad()
{
	std::cout << "Degree to Radians. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Degrees to Convert: ";
	float input;
	std::cin >> input;
	float manuallyCalculated = input * (M_PI / 180.f);
	std::cout << "Output from function: " << MathsLibrary::Deg2Rad(input) << std::endl;
	std::cout << "Output from manual calculated: " << manuallyCalculated << std::endl;
	
}

////	Infinity	A representation of positive infinity(Read Only).
//static const float Infinity;
void Tests::Infinity()
{
	std::cout << "Infinity as defined in standard c++ maths library: " << std::numeric_limits<float>::infinity() << std::endl;
	std::cout << "Infinity as defined in mathslibrary: " << MathsLibrary::Infinity << std::endl;
}

////	NegativeInfinity	A representation of negative infinity(Read Only).
//static const float NegativeInfinity;
void Tests::NegativeInfinity()
{
	std::cout << "Negative Infinity as defined in standard c++ maths library: " << -std::numeric_limits<float>::infinity() << std::endl;
	std::cout << "Negative Infinity as defined in mathslibrary: " << MathsLibrary::NegativeInfinity << std::endl;
}

////	PI	The well - known 3.14159265358979... value(Read Only).
//static const float PI;
void Tests::PI()
{
	std::cout << "PI as defined in c++: " << M_PI << std::endl;
	std::cout << "PI as defined in MathsLibrary: " << MathsLibrary::PI << std::endl;
}

////	Rad2Deg	Radians - to - degrees conversion constant(Read Only).
//static float Rad2Deg(float);
void Tests::Rad2Deg()
{
	std::cout << "Radians to Degrees. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Radians to Convert: ";
	float input;
	std::cin >> input;
	float manuallyCalculated = input * (180.f/ M_PI);
	std::cout << "Output from function: " << MathsLibrary::Rad2Deg(input) << std::endl;
	std::cout << "Output from manual calculated: " << manuallyCalculated << std::endl;
}
