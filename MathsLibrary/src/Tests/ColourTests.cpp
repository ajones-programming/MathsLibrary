#include "MathsLibrary.h"
#include "Tests.h"
#include <iostream>

void Tests::GammaToLinear()
{
	std::cout << "Gamma to Linear." << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	std::cout << "Output from function: " << MathsLibrary::GammaToLinearSpace(input) << std::endl;
}

void Tests::LinearToGamma()
{

	std::cout << "Linear to Gamma." << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	std::cout << "Output from function: " << MathsLibrary::LinearToGammaSpace(input) << std::endl;
}
