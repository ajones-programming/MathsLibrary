#include "MathsLibrary.h"
#include "Tests.h"
#include <iostream>
#include <math.h>
#include <algorithm>

////	Abs	Returns the absolute value of f.
//static float Abs(float);
void Tests::Abs()
{
	std::cout << "Absolute Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;

	auto homemade = [input]() { return MathsLibrary::Abs(input); };
	auto standard = [input]() { return std::abs(input); };
	runBoth(homemade, standard);
}

////	Approximately	Compares two floating point values and returns true if they are similar.
//static float Approx(float, float);
void Tests::Approx()
{
	std::cout << "Approx Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value: ";
	float input;
	std::cin >> input;
	std::cout << "Value to Compare: ";
	float toCompare;
	std::cin >> toCompare;

	auto homemade = [input, toCompare]() { return MathsLibrary::Approx(input, toCompare); };
	auto standard = [input, toCompare]() { return std::abs(input - toCompare); };
	runBoth(homemade, standard);
}

////	Ceil	Returns the smallest integer greater to or equal to f.
//static float Ciel(float);
void Tests::Ciel()
{
	std::cout << "Ceiling Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;

	auto homemade = [input]() { return MathsLibrary::Ciel(input); };
	auto standard = [input]() { return std::ceil(input); };
	runBoth(homemade, standard);
}

////	CeilToInt	Returns the smallest integer greater to or equal to f.
//static int CielToInt(float);
void Tests::CielToInt()
{
	std::cout << "Ceiling Int Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;

	auto homemade = [input]() { return MathsLibrary::CielToInt(input); };
	auto standard = [input]() { return (int)std::ceil(input); };
	runBoth(homemade, standard);
}

////	Clamp	Clamps the given value between the given minimum float and maximum float values.Returns the given value if it is within the minimumand maximum range.
//static float Clamp(float, float, float);
void Tests::Clamp()
{
	
	std::cout << "Clamp Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	std::cout << "Minimum value: " << std::endl;
	float minimum;
	std::cin >> minimum;
	std::cout << "Maximum value: " << std::endl;
	float maximum;
	std::cin >> maximum;

	auto homemade = [input, minimum, maximum]() { return MathsLibrary::Clamp(input, minimum, maximum); };
	auto standard = [input, minimum, maximum]() { return std::clamp(input, minimum, maximum); };
	runBoth(homemade, standard);
}

////	Clamp01	Clamps value between 0 and 1 and returns value.
//static float Clamp01(float);
void Tests::Clamp01()
{
	std::cout << "Clamp01 Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	auto homemade = [input]() { return MathsLibrary::Clamp01(input); };
	auto standard = [input]() { return std::clamp(input,0.f,1.f); };
	runBoth(homemade, standard);
}

////	Floor	Returns the largest integer smaller than or equal to f.
//static float Floor(float);
void Tests::Floor()
{
	std::cout << "Floor Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	auto homemade = [input]() { return MathsLibrary::Floor(input); };
	auto standard = [input]() { return std::floor(input); };
	runBoth(homemade, standard);
}

////	FloorToInt	Returns the largest integer smaller to or equal to f.
//static int FloorToInt(float);
void Tests::FloorToInt()
{
	std::cout << "Floor to Int Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;

	auto homemade = [input]() { return MathsLibrary::FloorToInt(input); };
	auto standard = [input]() { return std::floor(input); };
	runBoth(homemade, standard);
}

////	Max	Returns largest of two or more values.
//static float Max(float, float);
//static float Max(float[], int);
void Tests::Max()
{
	std::cout << "Maximum Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Number of values to compare: " << std::endl;
	unsigned int numberInArray;
	std::cin >> numberInArray;
	float* arrayOfNumbers = new float[numberInArray];
	for (int Count = 0; Count < numberInArray;Count++) {
		std::cout << "Input a number (" << (Count + 1) << ")" << std::endl;
		std::cin >> arrayOfNumbers[Count];
	}

	float output = numberInArray == 2 ? MathsLibrary::Max(arrayOfNumbers[0], arrayOfNumbers[1]) : MathsLibrary::Max(arrayOfNumbers, (int)numberInArray);
	std::cout << "Output from function: " << output << std::endl;
	delete[] arrayOfNumbers;
}

////	Min	Returns the smallest of two or more values.
//static float Min(float, float);
//static float Min(float[], int);
void Tests::Min()
{
	std::cout << "Minimum Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Number of values to compare: " << std::endl;
	unsigned int numberInArray;
	std::cin >> numberInArray;
	float* arrayOfNumbers = new float[numberInArray];
	for (int Count = 0; Count < numberInArray;Count++) {
		std::cout << "Input a number (" << (Count + 1) << ")" << std::endl;
		std::cin >> arrayOfNumbers[Count];
	}
	float output = numberInArray == 2 ? MathsLibrary::Min(arrayOfNumbers[0], arrayOfNumbers[1]) : MathsLibrary::Min(arrayOfNumbers, (int)numberInArray);
	std::cout << "Output from function: " << output << std::endl;
	delete[] arrayOfNumbers;
}

////	Pow	Returns f raised to power p.
//static float Pow(float, float);
void Tests::Pow()
{
	std::cout << "Power of Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value: ";
	float input;
	std::cin >> input;
	std::cout << "To the power of: ";
	float toThePowerOf;
	std::cin >> toThePowerOf;

	auto homemade = [input, toThePowerOf]() { return MathsLibrary::Pow(input, toThePowerOf); };
	auto standard = [input, toThePowerOf]() { return std::pow(input, toThePowerOf); };
	runBoth( homemade, standard);
}

////	Round	Returns f rounded to the nearest integer.
//static float Round(float);
void Tests::Round()
{
	std::cout << "Round Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;

	auto homemade = [input]() { return MathsLibrary::Round(input); };
	auto standard = [input]() { return std::round(input); };
	runBoth(homemade, standard);
}

////	RoundToInt	Returns f rounded to the nearest integer.
//static float RoundToInt(float);
void Tests::RoundToInt()
{
	std::cout << "Round to Int Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	auto homemade = [input]() { return MathsLibrary::RoundToInt(input); };
	auto standard = [input]() { return std::round(input); };
	runBoth(homemade, standard);
}

////	Sign	Returns the sign of f.
//static float Sign(float);
void Tests::Sign()
{
	std::cout << "Sign Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;

	auto homemade = [input]() { return MathsLibrary::Sign(input); };
	auto standard = [input]() { return input > 0.f ? 1.f : (input == 0.f ? 0.f : -1.f); };
	runBoth(homemade, standard);
}

////	Sqrt	Returns square root of f.
//static float Sqrt(float);
void Tests::Sqrt()
{
	std::cout << "Square Root Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;

	auto homemade = [input]() { return MathsLibrary::Sqrt(input); };
	auto standard = [input]() { return std::sqrt(input); };
	runBoth(homemade, standard);
}
