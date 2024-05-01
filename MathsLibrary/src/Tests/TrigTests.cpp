#include "MathsLibrary.h"
#include "Tests.h"
#include <iostream>

////	Acos	Returns the arc - cosine of f - the angle in radians whose cosine is f.
//static float Acos(float, bool isRadians = true);
void Tests::Acos()
{
	std::cout << "Acos Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	float manuallyCalculated = std::acos(input);
	std::cout << "Output from function: " << MathsLibrary::Acos(input, true) << std::endl;
	std::cout << "Output from manual calculated: " << manuallyCalculated << std::endl;
}

////	Asin	Returns the arc - sine of f - the angle in radians whose sine is f.
//static float Asin(float);
void Tests::Asin()
{
	std::cout << "Asin Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	float manuallyCalculated = std::asin(input);
	std::cout << "Output from function: " << MathsLibrary::Asin(input, true) << std::endl;
	std::cout << "Output from manual calculated: " << manuallyCalculated << std::endl;
}

////	Atan	Returns the arc - tangent of f - the angle in radians whose tangent is f.
//static float Atan(float);
void Tests::Atan()
{
	std::cout << "Atan Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	float manuallyCalculated = std::atan(input);
	std::cout << "Output from function: " << MathsLibrary::Atan(input, true) << std::endl;
	std::cout << "Output from manual calculated: " << manuallyCalculated << std::endl;
}

////	Atan2	Returns the angle in radians whose Tan is y / x.
//static float Atan2(float);
void Tests::Atan2()
{
	std::cout << "Atan2 Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "X Value to Convert: ";
	float x;
	std::cin >> x;
	std::cout << "Y Value to Convert: ";
	float y;
	std::cin >> y;
	float manuallyCalculated = std::atan2(y,x);
	std::cout << "Output from function: " << MathsLibrary::Atan2(x,y, true) << std::endl;
	std::cout << "Output from manual calculated: " << manuallyCalculated << std::endl;
}

////	Cos	Returns the cosine of angle f.
//static float Cos(float);
void Tests::Cos()
{
	std::cout << "Cos Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	float manuallyCalculated = std::cos(input);
	std::cout << "Output from function: " << MathsLibrary::Cos(input, true) << std::endl;
	std::cout << "Output from manual calculated: " << manuallyCalculated << std::endl;
}

////	DeltaAngle	Calculates the shortest difference between two given angles given in degrees.
//static float DeltaAngle(float);
void Tests::DeltaAngle()
{
	std::cout << "Delta Angle Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Value 1: ";
	float x;
	std::cin >> x;
	std::cout << "Value 2: ";
	float y;
	std::cin >> y;
	std::cout << "Output from function: " << MathsLibrary::DeltaAngle(x, y, true) << std::endl;
}

////	Sin	Returns the sine of angle f.
//static float Sin(float);
void Tests::Sin()
{
	std::cout << "Sin Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	float manuallyCalculated = std::sin(input);
	std::cout << "Output from function: " << MathsLibrary::Sin(input, true) << std::endl;
	std::cout << "Output from manual calculated: " << manuallyCalculated << std::endl;
}

////	Tan	Returns the tangent of angle f in radians.
//static float Tan(float);
void Tests::Tan()
{
	std::cout << "Tan Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	float manuallyCalculated = std::tan(input);
	std::cout << "Output from function: " << MathsLibrary::Tan(input, true) << std::endl;
	std::cout << "Output from manual calculated: " << manuallyCalculated << std::endl;
}

