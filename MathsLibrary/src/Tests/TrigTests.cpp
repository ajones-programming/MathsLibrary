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

	auto homemade = [input]() { return MathsLibrary::Acos(input, true); };
	auto standard = [input]() { return std::acos(input); };
	runBoth(homemade, standard);
}

////	Asin	Returns the arc - sine of f - the angle in radians whose sine is f.
//static float Asin(float);
void Tests::Asin()
{
	std::cout << "Asin Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;

	auto homemade = [input]() { return MathsLibrary::Asin(input, true); };
	auto standard = [input]() { return std::asin(input); };
	runBoth(homemade, standard);
}

////	Atan	Returns the arc - tangent of f - the angle in radians whose tangent is f.
//static float Atan(float);
void Tests::Atan()
{
	std::cout << "Atan Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;

	auto homemade = [input]() { return MathsLibrary::Atan(input, true); };
	auto standard = [input]() { return std::atan(input); };
	runBoth(homemade, standard);
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

	auto homemade = [x,y]() { return MathsLibrary::Atan2(x, y, true); };
	auto standard = [x,y]() { return std::atan2(y, x); };
	runBoth(homemade, standard);
}

////	Cos	Returns the cosine of angle f.
//static float Cos(float);
void Tests::Cos()
{
	std::cout << "Cos Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;

	auto homemade = [input]() { return MathsLibrary::Cos(input, true); };
	auto standard = [input]() { return std::cos(input); };
	runBoth(homemade, standard);
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
	auto homemade = [input]() { return MathsLibrary::Sin(input, true); };
	auto standard = [input]() { return std::sin(input); };
	runBoth(homemade, standard);
}

////	Tan	Returns the tangent of angle f in radians.
//static float Tan(float);
void Tests::Tan()
{
	std::cout << "Tan Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	auto homemade = [input]() { return MathsLibrary::Tan(input, true); };
	auto standard = [input]() { return std::tan(input); };
	runBoth(homemade, standard);
}

