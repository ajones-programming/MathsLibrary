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

	auto homemade = [input]() { return MathsLibrary::Exp(input); };
	auto standard = [input]() { return std::exp(input); };
	runBoth(homemade, standard);
}

void Tests::Log()
{
	std::cout << "Ln. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;

	auto homemade = [input]() { return MathsLibrary::Log(input); };
	auto standard = [input]() { return std::log(input); };
	runBoth(homemade, standard);

}

void Tests::Log10()
{
	std::cout << "Log10. Comparing homemade function to existing function" << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;

	auto homemade = [input]() { return MathsLibrary::Log10(input); };
	auto standard = [input]() { return std::log10(input); };
	runBoth(homemade, standard);
}
