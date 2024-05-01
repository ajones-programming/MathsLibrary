#include "Tests.h"
#include <iostream>

Tests::Tests()
{
	ShowIntroduction();
	//while not quit
	bool hasQuit = false;
	while (!hasQuit) {
		MainOptions(hasQuit);
	}

}

void Tests::ShowIntroduction()
{
	std::cout << "WELCOME TO THE TESTS FOR THE MATHS LIBRARY" << std::endl;
	
}

void Tests::MainOptions(bool &hasQuit)
{

	std::cout << "WHICH DO YOU WANT TO DO:" << std::endl;
	std::cout << "\tRUN TESTS: 0" << std::endl;
	std::cout << "\tQUIT: 1" << std::endl;
	
	int value;
	std::cin >> value;
	if (value == 1) {
		hasQuit = true;
	}
	else {
		TypeCategory();
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "========================================" << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
}

void Tests::TypeCategory()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "ALL TESTS: " << std::endl;
	for (std::pair<int, std::string> pair : allMainOptionsText) {
		std::cout << " - " << pair.second << ": " << pair.first << std::endl;
	}
	MAIN_TEST_TYPES typeOfTest;
	int val;
	std::cin >> val;
	typeOfTest = (MAIN_TEST_TYPES)val;

	switch (typeOfTest) {
	case MAIN_TEST_TYPES::STATIC:
		StaticTests();
		break;
	case MAIN_TEST_TYPES::BASIC:
		BasicTests();
		break;
	case MAIN_TEST_TYPES::TRIG:
		TrigTests();
		break;
	case MAIN_TEST_TYPES::POWERS:
		PowersTests();
		break;
	case MAIN_TEST_TYPES::EXPONENTIALS:
		ExponentialsTests();
		break;
	case MAIN_TEST_TYPES::COLOUR:
		ColourTests();
		break;
	case MAIN_TEST_TYPES::ENCODING:
		EncodingTests();
		break;
	case MAIN_TEST_TYPES::LERPING:
		LerpingTests();
		break;
	case MAIN_TEST_TYPES::RANDOMNESS:
		RandomnessTests();
		break;
	}


	


}

void Tests::StaticTests()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "ALL STATIC TESTS: " << std::endl;
	for (std::pair<int, std::string> pair : allStaticOptionsText) {
		std::cout << " - " << pair.second << ": " << pair.first << std::endl;
	}
	STATIC_TESTS typeOfTest;
	int val;
	std::cin >> val;
	typeOfTest = (STATIC_TESTS)val;

	switch (typeOfTest) {
	case STATIC_TESTS::DEG_2_RAD:
	{
		DegToRad();
		break;
	}
	case STATIC_TESTS::INFINITY__DEFINED:
	{
		Infinity();
		break;
	}	case STATIC_TESTS::NEGATIVE_INFINITY:
	{
		NegativeInfinity();
		break;
	}	case STATIC_TESTS::PI__DEFINED:
	{
		PI();
		break;
	}	case STATIC_TESTS::RAD_2_DEGREE:
	{
		Rad2Deg();
		break;
	}
	}
}

void Tests::BasicTests()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "ALL BASIC TESTS: " << std::endl;
	for (std::pair<int, std::string> pair : allBasicOptionsText) {
		std::cout << " - " << pair.second << ": " << pair.first << std::endl;
	}
	BASIC_TESTS typeOfTest;
	int val;
	std::cin >> val;
	typeOfTest = (BASIC_TESTS)val;

	switch (typeOfTest){
	case BASIC_TESTS::ABS:
		Abs();
		break;

	case BASIC_TESTS::APPROX:
		Approx();
		break;
	case BASIC_TESTS::CIEL:
		Ciel();
		break;
	case BASIC_TESTS::CIEL_TO_INT:
		CielToInt();
		break;
	case BASIC_TESTS::CLAMP:
		Clamp();
		break;
	case BASIC_TESTS::CLAMP01:
		Clamp01();
		break;
	case BASIC_TESTS::FLOOR:
		Floor();
		break;
	case BASIC_TESTS::FLOOR_TO_INT:
		FloorToInt();
		break;
	case BASIC_TESTS::MAX:
		Max();
		break;
	case BASIC_TESTS::MIN:
		Min();
		break;
	case BASIC_TESTS::POW:
		Pow();
		break;
	case BASIC_TESTS::ROUND:
		Round();
		break;
	case BASIC_TESTS::ROUND_TO_INT:
		RoundToInt();
		break;
	case BASIC_TESTS::SIGN:
		Sign();
		break;
	case BASIC_TESTS::SQRT:
		Sqrt();
		break;
	}
}

void Tests::TrigTests()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "ALL TRIG TESTS: " << std::endl;
	for (std::pair<int, std::string> pair : allTrigOptionsText) {
		std::cout << " - " << pair.second << ": " << pair.first << std::endl;
	}
	TRIG_TESTS typeOfTest;
	int val;
	std::cin >> val;
	typeOfTest = (TRIG_TESTS)val;

	switch (typeOfTest) {
	case TRIG_TESTS::ACOS:
		Acos();
		break;
	case TRIG_TESTS::ASIN:
		Asin();
		break;
	case TRIG_TESTS::ATAN:
		Atan();
		break;
	case TRIG_TESTS::ATAN2:
		Atan2();
		break;
	case TRIG_TESTS::COS:
		Cos();
		break;
	case TRIG_TESTS::DELTAANGLE:
		DeltaAngle();
		break;
	case TRIG_TESTS::SIN:
		Sin();
		break;
	case TRIG_TESTS::TAN:
		Tan();
		break;
	}
}

void Tests::PowersTests()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "ALL POWERS TESTS: " << std::endl;
	for (std::pair<int, std::string> pair : allPowersOptionsText) {
		std::cout << " - " << pair.second << ": " << pair.first << std::endl;
	}
	POWERS_TESTS typeOfTest;
	int val;
	std::cin >> val;
	typeOfTest = (POWERS_TESTS)val;

	switch (typeOfTest) {
	case POWERS_TESTS::CLOSEST_POWER_OF_TWO:
		ClosestPowerOfTwo();
		break;
	case POWERS_TESTS::IS_POWER_OF_TWO:
		IsPowerOfTwo();
		break;
	case POWERS_TESTS::NEXT_POWER_OF_TWO:
		NextPowerOfTwo();
		break;
	}
}

void Tests::ExponentialsTests()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "ALL EXPONENTIALS TESTS: " << std::endl;
	for (std::pair<int, std::string> pair : allExponentialsOptionsText) {
		std::cout << " - " << pair.second << ": " << pair.first << std::endl;
	}
	EXPONENTIALS_TESTS typeOfTest;
	int val;
	std::cin >> val;
	typeOfTest = (EXPONENTIALS_TESTS)val;

	switch (typeOfTest) {
	case EXPONENTIALS_TESTS::EXP:
		Exp();
		break;
	case EXPONENTIALS_TESTS::LOG:
		Log();
		break;
	case EXPONENTIALS_TESTS::LOG10:
		Log10();
		break;
	}
}


void Tests::ColourTests()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "ALL COLOUR TESTS: " << std::endl;
	for (std::pair<int, std::string> pair : allColourOptionsText) {
		std::cout << " - " << pair.second << ": " << pair.first << std::endl;
	}
	COLOUR_TESTS typeOfTest;
	int val;
	std::cin >> val;
	typeOfTest = (COLOUR_TESTS)val;

	switch (typeOfTest) {
	case COLOUR_TESTS::GAMMA_TO_LINEAR:
		GammaToLinear();
		break;
	case COLOUR_TESTS::LINEAR_TO_GAMMA:
		LinearToGamma();
		break;
	}
}

void Tests::EncodingTests()
{

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "ALL ENCODING TESTS: " << std::endl;
	for (std::pair<int, std::string> pair : allEncodingOptionsText) {
		std::cout << " - " << pair.second << ": " << pair.first << std::endl;
	}
	ENCODING_TESTS typeOfTest;
	int val;
	std::cin >> val;
	typeOfTest = (ENCODING_TESTS)val;

	switch (typeOfTest) {
	case ENCODING_TESTS::FLOAT_TO_HALF:
		FloatToHalf();
		break;
	case ENCODING_TESTS::HALF_TO_FLOAT:
		HalfToFloat();
		break;
	}
}

void Tests::LerpingTests()
{


	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "ALL LERPING TESTS: " << std::endl;
	for (std::pair<int, std::string> pair : allLerpingOptionsText) {
		std::cout << " - " << pair.second << ": " << pair.first << std::endl;
	}
	LERPING_TESTS typeOfTest;
	int val;
	std::cin >> val;
	typeOfTest = (LERPING_TESTS)val;

	switch (typeOfTest) {
	case (LERPING_TESTS::INVERSE_LERP):
			InverseLerp();
			break;
	case (LERPING_TESTS::LERP):
		Lerp();
		break;
	case (LERPING_TESTS::LERP_ANGLE):
		LerpAngle();
		break;
	case (LERPING_TESTS::LERP_UNCLAMPED):
		LerpUnclamped();
		break;
	case (LERPING_TESTS::MOVE_TOWARDS):
		MoveTowards();
		break;
	case (LERPING_TESTS::MOVE_TOWARDS_ANGLE):
		MoveTowardsAngle();
		break;
	case (LERPING_TESTS::SMOOTH_DAMP):
		SmoothDamp();
		break;
	case (LERPING_TESTS::SMOOTH_DAMP_ANGLE):
		SmoothDampAngle();
		break;
	case (LERPING_TESTS::SMOOTH_STEP):
		SmoothStep();
		break;
	}
}

void Tests::RandomnessTests()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "ALL RANDOMNESS TESTS: " << std::endl;
	for (std::pair<int, std::string> pair : allRandomnessOptionsText) {
		std::cout << " - " << pair.second << ": " << pair.first << std::endl;
	}
	RANDOMNESS_TESTS typeOfTest;
	int val;
	std::cin >> val;
	typeOfTest = (RANDOMNESS_TESTS)val;

	switch (typeOfTest) {
	case RANDOMNESS_TESTS::PERLIN_NOISE:
		PerlinNoise();
		break;
	case RANDOMNESS_TESTS::PING_PONG:
		PingPong();
		break;
	case RANDOMNESS_TESTS::REPEAT:
		Repeat();
		break;
	}
}