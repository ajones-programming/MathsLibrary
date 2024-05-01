#include "MathsLibrary.h"
#include "Tests.h"
#include<iostream>
#include <math.h>

void Tests::Exp()
{
	std::cout << "Exponential. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	float manuallyCalculated = std::exp(input);
	std::cout << "Output from function: " << MathsLibrary::Exp(input) << std::endl;
	std::cout << "Output from manual calculated: " << manuallyCalculated << std::endl;
}

void Tests::Log()
{
	std::cout << "Ln. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	float manuallyCalculated = std::log(input);
	std::cout << "Output from function: " << MathsLibrary::Log(input) << std::endl;
	std::cout << "Output from manual calculated: " << manuallyCalculated << std::endl;

}

void Tests::Log10()
{
	std::cout << "Log10. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	float manuallyCalculated = std::log10(input);
	std::cout << "Output from function: " << MathsLibrary::Log10(input) << std::endl;
	std::cout << "Output from manual calculated: " << manuallyCalculated << std::endl;
}
