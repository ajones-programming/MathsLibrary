#include "MathsLibrary.h"
#include "Tests.h"
#include <iostream>

void Tests::PerlinNoise()
{
	std::cout << "Perlin Noise" << std::endl;
	std::cout << "Insert row to intersect: ";
	float rowToIntersect;
	std::cin >> rowToIntersect;
	float deltaTime = 0.1f;
	for (float Count = 0; Count < 3.f; Count+= deltaTime) {
		std::cout << "For X = " << Count << ", Y = " << rowToIntersect << ", Perlin Noise = " << MathsLibrary::PerlinNoise(Count, rowToIntersect) << std::endl;
	}
}

void Tests::PingPong()
{
	std::cout << "Ping Pong" << std::endl;
	std::cout << "Length: ";
	float length;
	std::cin >> length;
	float deltaTime = 0.5f;
	for (float Count = 0; Count <= length; Count += deltaTime) {
		std::cout << "For X = " << Count << ", PingPong = " << MathsLibrary::PingPong(Count, length) << std::endl;
	}
}

void Tests::Repeat()
{
	std::cout << "Repeat" << std::endl;
	std::cout << "Length: ";
	float length;
	std::cin >> length;
	float deltaTime = 0.5f;
	for (float Count = 0; Count <= length; Count += deltaTime) {
		std::cout << "For X = " << Count << ", Repeat = " << MathsLibrary::Repeat(Count, length) << std::endl;
	}
}

