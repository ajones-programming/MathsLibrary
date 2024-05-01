#include "MathsLibrary.h"
#include "Tests.h"
#include <iostream>

////	ClosestPowerOfTwo	Returns the closest power of two value.
//static float ClosestPowerOfTwo(float);
void Tests::ClosestPowerOfTwo()
{
	std::cout << "Closest Power of Two Value. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	std::cout << "Output from function: " << MathsLibrary::ClosestPowerOfTwo(input) << std::endl;
}

////	IsPowerOfTwo	Returns true if the value is power of two.
//static bool IsPowerOfTwo(float);
void Tests::IsPowerOfTwo()
{
	std::cout << "Is Power of Two. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	std::cout << "Output from function: " << (MathsLibrary::IsPowerOfTwo(input) ? "true" : "false") << std::endl;
}

////	NextPowerOfTwo	Returns the next power of two that is equal to, or greater than, the argument.
//static float NextPowerOfTwo(float);
void Tests::NextPowerOfTwo()
{
	std::cout << "Next Power of Two. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	std::cout << "Output from function: " << MathsLibrary::NextPowerOfTwo(input) << std::endl;
}
