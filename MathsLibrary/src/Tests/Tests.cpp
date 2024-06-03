#include "Tests.h"
#include <iostream>
#include <concepts>
#include <map>
#include <string>


template <typename T>
T listAndGetValues(std::map<T, std::string> list, std::string testName = "");

Tests::Tests()
{
	ShowIntroduction();
	//while not quit
	bool hasQuit = false;
	while (!hasQuit) {
		hasQuit = MainOptions();
	}

}

void Tests::ShowIntroduction()
{
	std::cout << "WELCOME TO THE TESTS FOR THE MATHS LIBRARY" << std::endl;
	
}

bool Tests::MainOptions()
{

	std::cout << "WHICH DO YOU WANT TO DO:" << std::endl;
	std::cout << "\tRUN TESTS: 0" << std::endl;
	std::cout << "\tQUIT: 1" << std::endl;
	
	int value;
	std::cin >> value;
	if (value == 1) {
		return true;
	}
	TypeCategory();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	return false;
}

void Tests::TypeCategory()
{
	std::cout << std::endl;
	std::cout << std::endl;

	switch (listAndGetValues(allMainOptionsText,"")) {
		using enum MAIN_TEST_TYPES;
		case STATIC: StaticTests(); break;
		case BASIC: BasicTests(); break;
		case TRIG: TrigTests(); break;
		case POWERS: PowersTests(); break;
		case EXPONENTIALS: ExponentialsTests(); break;
		case COLOUR: ColourTests(); break;
		case ENCODING: EncodingTests(); break;
		case LERPING: LerpingTests(); break;
		case RANDOMNESS: RandomnessTests(); break;
	}

}

void Tests::StaticTests()
{
	std::cout << std::endl;
	std::cout << std::endl;

	switch (listAndGetValues(allStaticOptionsText, "STATIC")) {
		using enum STATIC_TESTS;
		case DEG_2_RAD: DegToRad(); break;
		case INFINITY__DEFINED: Infinity(); break;
		case NEGATIVE_INFINITY: NegativeInfinity(); break;
		case PI__DEFINED: PI(); break;
		case RAD_2_DEGREE: Rad2Deg(); break;
	}
}

void Tests::BasicTests()
{
	std::cout << std::endl;
	std::cout << std::endl;

	switch (listAndGetValues(allBasicOptionsText, "BASIC")) {
		using enum BASIC_TESTS;
		case ABS: Abs(); break;
		case APPROX: Approx(); break;
		case CIEL: Ciel(); break;
		case CIEL_TO_INT: CielToInt(); break;
		case CLAMP: Clamp(); break;
		case CLAMP01: Clamp01(); break;
		case FLOOR: Floor(); break;
		case FLOOR_TO_INT: FloorToInt(); break;
		case MAX: Max(); break;
		case MIN: Min(); break;
		case POW: Pow(); break;
		case ROUND: Round(); break;
		case ROUND_TO_INT: RoundToInt(); break;
		case SIGN: Sign(); break;
		case SQRT: Sqrt(); break;
	}
}

void Tests::TrigTests()
{
	std::cout << std::endl;
	std::cout << std::endl;
	
	switch (listAndGetValues(allTrigOptionsText, "TRIG")) {
		using enum TRIG_TESTS;
		case ACOS: Acos(); break;
		case ASIN: Asin(); break;
		case ATAN: Atan(); break;
		case ATAN2: Atan2(); break;
		case COS: Cos(); break;
		case DELTAANGLE: DeltaAngle(); break;
		case SIN: Sin(); break;
		case TAN: Tan(); break;
	}
}

void Tests::PowersTests()
{
	std::cout << std::endl;
	std::cout << std::endl;

	switch (listAndGetValues(allPowersOptionsText, "POWERS")) {
		using enum POWERS_TESTS;
		case CLOSEST_POWER_OF_TWO: ClosestPowerOfTwo(); break;
		case IS_POWER_OF_TWO: IsPowerOfTwo(); break;
		case NEXT_POWER_OF_TWO: NextPowerOfTwo(); break;
	}
}

void Tests::ExponentialsTests()
{
	std::cout << std::endl;
	std::cout << std::endl;
	
	switch (listAndGetValues(allExponentialsOptionsText, "EXPONENTIAL")) {
		using enum EXPONENTIALS_TESTS;
		case EXP: Exp(); break;
		case LOG: Log(); break;
		case LOG10: Log10(); break;
	}
}

void Tests::ColourTests()
{
	std::cout << std::endl;
	std::cout << std::endl;
	
	switch (listAndGetValues(allColourOptionsText, "COLOUR")) {
		using enum COLOUR_TESTS;
		case GAMMA_TO_LINEAR: GammaToLinear(); break;
		case LINEAR_TO_GAMMA: LinearToGamma(); break;
	}
}

void Tests::EncodingTests()
{
	std::cout << std::endl;
	std::cout << std::endl;

	switch (listAndGetValues(allEncodingOptionsText, "ENCODING")) {
		using enum ENCODING_TESTS;
		case FLOAT_TO_HALF: FloatToHalf(); break;
		case HALF_TO_FLOAT: HalfToFloat(); break;
	}
}

void Tests::LerpingTests()
{
	std::cout << std::endl;
	std::cout << std::endl;
	
	switch (listAndGetValues(allLerpingOptionsText, "LERPING"))
	{
		using enum LERPING_TESTS;
		case INVERSE_LERP: InverseLerp(); break;
		case LERP: Lerp(); break;
		case LERP_ANGLE: LerpAngle(); break;
		case LERP_UNCLAMPED: LerpUnclamped(); break;
		case MOVE_TOWARDS: MoveTowards(); break;
		case MOVE_TOWARDS_ANGLE: MoveTowardsAngle(); break;
		case SMOOTH_DAMP: SmoothDamp(); break;
		case SMOOTH_DAMP_ANGLE: SmoothDampAngle(); break;
		case SMOOTH_STEP: SmoothStep(); break;
	}
}

void Tests::RandomnessTests()
{
	std::cout << std::endl;
	std::cout << std::endl;

	switch (listAndGetValues(allRandomnessOptionsText, "RANDOMNESS")) {
		using enum RANDOMNESS_TESTS;
		case PERLIN_NOISE: PerlinNoise(); break;
		case PING_PONG: PingPong(); break;
		case REPEAT: Repeat(); break;
	}
}



template <typename T>
T listAndGetValues(std::map<T, std::string> list, std::string testName) {
	std::cout << "ALL " << testName << " TESTS:" << std::endl;
	for (auto pair : list) {
		std::cout << " - " << pair.second << ": " << (int)pair.first << std::endl;
	}
	int val;
	std::cin >> val;
	return (T)val;
}