#include "MathsLibrary.h"
#include "Tests.h"
#include <iostream>
#include <chrono>
#include <math.h>

////	Abs	Returns the absolute value of f.
//static float Abs(float);
void Tests::Abs()
{
	std::cout << "Absolute Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	float manuallyCalculated = std::abs(input);
	std::cout << "Output from function: " << MathsLibrary::Abs(input) << std::endl;
	std::cout << "Output from manual calculated: " << manuallyCalculated << std::endl;
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

	bool isApproxEqual = MathsLibrary::Approx(input, toCompare);
	float differenceBetween = std::abs(input - toCompare);
	std::cout << "Is approx equal: " << std::to_string( isApproxEqual) << std::endl;
	std::cout << "Difference between values: " << differenceBetween << std::endl;
}

////	Ceil	Returns the smallest integer greater to or equal to f.
//static float Ciel(float);
void Tests::Ciel()
{
	std::cout << "Ceiling Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	float manuallyCalculated = std::ceil(input);
	std::cout << "Output from function: " << MathsLibrary::Ciel(input) << std::endl;
	std::cout << "Output from manual calculated: " << manuallyCalculated << std::endl;
}

////	CeilToInt	Returns the smallest integer greater to or equal to f.
//static int CielToInt(float);
void Tests::CielToInt()
{
	std::cout << "Ceiling Int Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	float manuallyCalculated = std::ceil(input);
	std::cout << "Output from function: " << MathsLibrary::CielToInt(input) << std::endl;
	std::cout << "Output from manual calculated: " << manuallyCalculated << std::endl;
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

	std::cout << "Output from function: " << MathsLibrary::Clamp(input,minimum,maximum) << std::endl;
}

////	Clamp01	Clamps value between 0 and 1 and returns value.
//static float Clamp01(float);
void Tests::Clamp01()
{
	std::cout << "Clamp01 Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	std::cout << "Output from function: " << MathsLibrary::Clamp01(input) << std::endl;
}

////	Floor	Returns the largest integer smaller than or equal to f.
//static float Floor(float);
void Tests::Floor()
{
	std::cout << "Floor Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	float manuallyCalculated = std::floor(input);
	std::cout << "Output from function: " << MathsLibrary::Floor(input) << std::endl;
	std::cout << "Output from manual calculated: " << manuallyCalculated << std::endl;
}

////	FloorToInt	Returns the largest integer smaller to or equal to f.
//static int FloorToInt(float);
void Tests::FloorToInt()
{
	std::cout << "Floor to Int Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	float manuallyCalculated = std::floor(input);
	std::cout << "Output from function: " << MathsLibrary::FloorToInt(input) << std::endl;
	std::cout << "Output from manual calculated: " << manuallyCalculated << std::endl;
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

	float homemade = MathsLibrary::Pow(input, toThePowerOf);
	float mathsLibraryVer = std::pow(input, toThePowerOf);
	std::cout << "Homemade version: " << homemade << std::endl;
	std::cout << "Math.h version: " << mathsLibraryVer << std::endl;
}

////	Round	Returns f rounded to the nearest integer.
//static float Round(float);
void Tests::Round()
{
	std::cout << "Round Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	float manuallyCalculated = std::round(input);
	std::cout << "Output from function: " << MathsLibrary::Round(input) << std::endl;
	std::cout << "Output from manual calculated: " << manuallyCalculated << std::endl;
}

////	RoundToInt	Returns f rounded to the nearest integer.
//static float RoundToInt(float);
void Tests::RoundToInt()
{
	std::cout << "Round to Int Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	float manuallyCalculated = std::round(input);
	std::cout << "Output from function: " << MathsLibrary::RoundToInt(input) << std::endl;
	std::cout << "Output from manual calculated: " << manuallyCalculated << std::endl;
}

////	Sign	Returns the sign of f.
//static float Sign(float);
void Tests::Sign()
{
	std::cout << "Sign Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	float manuallyCalculated = input > 0.f ? 1.f : (input == 0.f ? 0.f : -1.f);
	std::cout << "Output from function: " << MathsLibrary::Sign(input) << std::endl;
	std::cout << "Output from manual calculated: " << manuallyCalculated << std::endl;
}

////	Sqrt	Returns square root of f.
//static float Sqrt(float);
void Tests::Sqrt()
{
	std::cout << "Square Root Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	float manuallyCalculated = std::sqrt(input);
	std::cout << "Output from function: " << MathsLibrary::Sqrt(input) << std::endl;
	std::cout << "Output from manual calculated: " << manuallyCalculated << std::endl;
}
