#include "MathsLibrary.h"
#include "Tests.h"
#include <iostream>
#include <string>


void Tests::FloatToHalf()
{
	std::cout << "Float to Half." << std::endl;
	std::cout << "Input Value to Convert: ";
	float input;
	std::cin >> input;
	unsigned short output = MathsLibrary::FloatToHalf(input);
	for (int Count = 0; Count < 16; Count++) {
		int b = output >> Count;
		if (b & 1)
			std::cout << "1";
		else
			std::cout << "0";
	}

	std::cout << std::endl;
	std::cout << "As unsigned short: " << output << std::endl;
}
void Tests::HalfToFloat()
{
	std::cout << "Half to Float." << std::endl;
	std::cout << "Input Value to Convert: ";
	unsigned short input;
	std::cin >> input;
	
	float output = MathsLibrary::HalfToFloat(input);
	char * fourChars = (char*)&output;
	for (int Count = 0; Count < 4; Count++) {
		for (int newCount = 0; newCount < 8; newCount++) {
			int b = *(fourChars + Count) >> newCount;
			if (b & 1)
				std::cout << "1";
			else
				std::cout << "0";

		}
	}

	std::cout << std::endl;
	std::cout << "As float: " << output << std::endl;
}

