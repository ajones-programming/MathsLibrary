#include "MathsLibrary.h"
#include "Tests.h"
#include <iostream>

void Tests::InverseLerp()
{
	std::cout << "Inverse Lerp." << std::endl;
	std::cout << "Input Start: ";
	float LowerBound;
	std::cin >> LowerBound;
	std::cout << "Input End: ";
	float UpperBound;
	std::cin >> UpperBound;
	std::cout << "Value: ";
	float Value;
	std::cin >> Value;
	
	std::cout << "Output from function: " << MathsLibrary::InverseLerp(LowerBound, UpperBound,Value) << std::endl;
}

void Tests::Lerp()
{
	std::cout << "Lerp." << std::endl;
	std::cout << "Input Start: ";
	float LowerBound;
	std::cin >> LowerBound;
	std::cout << "Input End: ";
	float UpperBound;
	std::cin >> UpperBound;
	std::cout << "Value: ";
	float Value;
	std::cin >> Value;
	std::cout << "Output from function: " << MathsLibrary::Lerp(LowerBound, UpperBound, Value) << std::endl;
}

void Tests::LerpAngle()
{
	std::cout << "Lerp Angle." << std::endl;
	std::cout << "Input Start: ";
	float LowerBound;
	std::cin >> LowerBound;
	std::cout << "Input End: ";
	float UpperBound;
	std::cin >> UpperBound;
	std::cout << "T: ";
	float Value;
	std::cin >> Value;
	std::cout << "Output from function: " << MathsLibrary::LerpAngle(LowerBound, UpperBound, Value,true) << std::endl;
}

void Tests::LerpUnclamped()
{
	std::cout << "Lerp Unclamped." << std::endl;
	std::cout << "Input Start: ";
	float LowerBound;
	std::cin >> LowerBound;
	std::cout << "Input End: ";
	float UpperBound;
	std::cin >> UpperBound;
	std::cout << "Value: ";
	float Value;
	std::cin >> Value;
	std::cout << "Output from function: " << MathsLibrary::LerpUnclamped(LowerBound, UpperBound, Value) << std::endl;
}

void Tests::MoveTowards()
{
	std::cout << "Move Towards." << std::endl;
	std::cout << "Input Start: ";
	float LowerBound;
	std::cin >> LowerBound;
	std::cout << "Input End: ";
	float UpperBound;
	std::cin >> UpperBound;
	std::cout << "Value: ";
	float Value;
	std::cin >> Value;
	std::cout << "Output from function: " << MathsLibrary::MoveTowards(LowerBound, UpperBound, Value) << std::endl;
}

void Tests::MoveTowardsAngle()
{
	std::cout << "Move Towards." << std::endl;
	std::cout << "Input Start: ";
	float LowerBound;
	std::cin >> LowerBound;
	std::cout << "Input End: ";
	float UpperBound;
	std::cin >> UpperBound;
	std::cout << "Value: ";
	float Value;
	std::cin >> Value;
	std::cout << "Output from function: " << MathsLibrary::MoveTowardsAngle(LowerBound, UpperBound, Value, true) << std::endl;
}

void Tests::SmoothDamp()
{
	std::cout << "Smooth Damp." << std::endl;
	std::cout << "Input Start: ";
	float current;
	std::cin >> current;
	std::cout << "Target: ";
	float target;
	std::cin >> target;
	std::cout << "Velocity: ";
	float velocity;
	std::cin >> velocity;
	std::cout << "Time: ";
	float time;
	std::cin >> time;
	std::cout << "DeltaTime: ";
	float deltaTime;
	std::cin >> deltaTime;
	if (deltaTime <= 0.f) {
		deltaTime = 0.01f;
	}
	for (int Count = 0; Count <  (time / deltaTime); Count++) {
		current = MathsLibrary::SmoothDamp(current, target, velocity, time, MathsLibrary::Infinity, deltaTime);
		float timeHere = Count * deltaTime;
		std::cout << "Output from function at " << timeHere<<": " << current << " with new velocity of " << velocity << std::endl;
	}
	

}

void Tests::SmoothDampAngle()
{
	std::cout << "Smooth Damp Angle." << std::endl;
	std::cout << "Input Start: ";
	float current;
	std::cin >> current;
	std::cout << "Target: ";
	float target;
	std::cin >> target;
	std::cout << "Velocity: ";
	float velocity;
	std::cin >> velocity;
	std::cout << "Time: ";
	float time;
	std::cin >> time;
	std::cout << "DeltaTime: ";
	float deltaTime;
	std::cin >> deltaTime;
	if (deltaTime <= 0.f) {
		deltaTime = 0.01f;
	}
	for (int Count = 0; Count <= (time / deltaTime); Count++) {
		current = MathsLibrary::SmoothDamp(current, target, velocity, time, MathsLibrary::Infinity, deltaTime);
		float timeHere = Count * deltaTime;
		std::cout << "Output from function at " << timeHere << ": " << current << " with new velocity of " << velocity << std::endl;
	}
}

void Tests::SmoothStep()
{
	std::cout << "Smooth step." << std::endl;
	std::cout << "Start: ";
	float start;
	std::cin >> start;
	std::cout << "End: ";
	float end;
	std::cin >> end;
	for (float time = 0; time <= 1.f; time += 0.05f) {
		std::cout << "For time=" << time << ", value is " << MathsLibrary::SmoothStep(start, end, time) << std::endl;
	}
}

