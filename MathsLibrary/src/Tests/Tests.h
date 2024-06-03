#pragma once
#include <map>
#include <string>
#include <concepts>
#include <chrono>
#include <iostream>

class Tests
{
public:
	Tests();
private:

	void ShowIntroduction();

	void TypeCategory();

	template <typename lambdaFunc1, typename lambdaFunc2>
	void runBoth(const lambdaFunc1& homemade, const lambdaFunc2& standard)
	{
		std::cout << "Runtime:" << std::endl;
		
		
		std::cout << "\tStandard" << std::endl;
		auto start = std::chrono::high_resolution_clock::now();
		auto resultstandard = standard();
		auto stop = std::chrono::high_resolution_clock::now();
		std::cout << "\t\tResult: " << resultstandard << std::endl;
		std::cout << "\t\tTime: " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << std::endl;

		std::cout << "\tHomemade" << std::endl;
		start = std::chrono::high_resolution_clock::now();
		auto resulthomemade = homemade();
		stop = std::chrono::high_resolution_clock::now();
		std::cout << "\t\tResult: " << resulthomemade << std::endl;
		std::cout << "\t\tTime: " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << std::endl;
	}

	//MAIN TESTS
	bool MainOptions();
	enum class MAIN_TEST_TYPES {
		STATIC,
		BASIC,
		TRIG,
		POWERS,
		EXPONENTIALS,
		COLOUR,
		ENCODING,
		LERPING,
		RANDOMNESS
	} ;
	std::map<MAIN_TEST_TYPES, std::string> allMainOptionsText = std::map<MAIN_TEST_TYPES, std::string>{
		
		{MAIN_TEST_TYPES::STATIC,"STATIC TESTS"},
		{MAIN_TEST_TYPES::BASIC,"BASIC TESTS"},
		{MAIN_TEST_TYPES::TRIG,"TRIG TESTS"},
		{MAIN_TEST_TYPES::POWERS,"POWERS TESTS"},
		{MAIN_TEST_TYPES::EXPONENTIALS,"EXPONENTIALS TESTS"},
		{MAIN_TEST_TYPES::COLOUR, "COLOUR TESTS"},
		{MAIN_TEST_TYPES::ENCODING, "ENCODING TESTS"},
		{MAIN_TEST_TYPES::LERPING, "LERPING TESTS"},
		{MAIN_TEST_TYPES::RANDOMNESS,"RANDOMNESS TESTS"}
	};

	//STATIC
	void StaticTests();
	enum class STATIC_TESTS {
		DEG_2_RAD,
		INFINITY__DEFINED,
		NEGATIVE_INFINITY,
		PI__DEFINED,
		RAD_2_DEGREE
	} ;
	std::map<STATIC_TESTS, std::string> allStaticOptionsText = std::map<STATIC_TESTS, std::string>{
		{STATIC_TESTS::DEG_2_RAD , "Degrees to Radians"},
		{STATIC_TESTS::INFINITY__DEFINED,"Infinity"},
		{STATIC_TESTS::NEGATIVE_INFINITY,"Negative Infinity"},
		{STATIC_TESTS::PI__DEFINED,"PI"},
		{STATIC_TESTS::RAD_2_DEGREE,"Radians to Degrees"}
	};
	void DegToRad();
	void Infinity();
	void NegativeInfinity();
	void PI();
	void Rad2Deg();



	//BASIC
	void BasicTests();
	enum class BASIC_TESTS  {
		ABS,
		APPROX,
		CIEL,
		CIEL_TO_INT,
		CLAMP,
		CLAMP01,
		FLOOR,
		FLOOR_TO_INT,
		MAX,
		MIN,
		POW,
		ROUND,
		ROUND_TO_INT,
		SIGN,
		SQRT
	} ;
	std::map<BASIC_TESTS, std::string> allBasicOptionsText = std::map<BASIC_TESTS, std::string>
	{
		
		{BASIC_TESTS::ABS, "Abs"},
		{BASIC_TESTS::APPROX, "Approx"},
		{BASIC_TESTS::CIEL,"Ciel"},
		{BASIC_TESTS::CIEL_TO_INT,"Cieling to Int"},
		{BASIC_TESTS::CLAMP,"Clamp"},
		{BASIC_TESTS::CLAMP01,"Clamp01"},
		{BASIC_TESTS::FLOOR, "Floor"},
		{BASIC_TESTS::FLOOR_TO_INT,"Floor to Int"},
		{BASIC_TESTS::MAX,"Max"},
		{BASIC_TESTS::MIN,"Min"},
		{BASIC_TESTS::POW,"Power"},
		{BASIC_TESTS::ROUND,"Round"},
		{BASIC_TESTS::ROUND_TO_INT,"Round to Int"},
		{BASIC_TESTS::SIGN,"Sign"},
		{BASIC_TESTS::SQRT,"Square Root"}
	};
	void Abs();
	void Approx();
	void Ciel();
	void CielToInt();
	void Clamp();
	void Clamp01();
	void Floor();
	void FloorToInt();
	void Max();
	void Min();
	void Pow();
	void Round();
	void RoundToInt();
	void Sign();
	void Sqrt();


	//TRIG:
	void TrigTests();
	enum class TRIG_TESTS {
		ACOS,
		ASIN,
		ATAN,
		ATAN2,
		COS,
		DELTAANGLE,
		SIN,
		TAN
	};
	std::map<TRIG_TESTS, std::string> allTrigOptionsText = std::map<TRIG_TESTS, std::string>{
		{TRIG_TESTS::ACOS, "ACos"},
		{TRIG_TESTS::ASIN,"Asin"},
		{TRIG_TESTS::ATAN,"Atan"},
		{TRIG_TESTS::ATAN2,"Atan2"},
		{TRIG_TESTS::COS,"Cos"},
		{TRIG_TESTS::DELTAANGLE,"DeltaAngle"},
		{TRIG_TESTS::SIN,"Sine"},
		{TRIG_TESTS::TAN,"Tan"}
	};
	void Acos();
	void Asin();
	void Atan();
	void Atan2();
	void Cos();
	void DeltaAngle();
	void Sin();
	void Tan();



	//POWERS
	void PowersTests();
	enum class POWERS_TESTS{
		CLOSEST_POWER_OF_TWO,
		IS_POWER_OF_TWO,
		NEXT_POWER_OF_TWO
	} ;
	std::map<POWERS_TESTS, std::string> allPowersOptionsText = std::map<POWERS_TESTS, std::string>{
		{POWERS_TESTS::CLOSEST_POWER_OF_TWO,"Closest Power of Two"},
		{POWERS_TESTS::IS_POWER_OF_TWO, "Is Power of Two"},
		{POWERS_TESTS::NEXT_POWER_OF_TWO, "Next Power of Two"}
	};
	void ClosestPowerOfTwo();
	void IsPowerOfTwo();
	void NextPowerOfTwo();

	

	//EXPONENTIALS
	void ExponentialsTests();
	enum class EXPONENTIALS_TESTS  {
		EXP,
		LOG,
		LOG10
	} ;
	std::map<EXPONENTIALS_TESTS, std::string> allExponentialsOptionsText = std::map<EXPONENTIALS_TESTS, std::string>{
		{EXPONENTIALS_TESTS::EXP,"Exponential"},
		{EXPONENTIALS_TESTS::LOG, "Ln"},
		{EXPONENTIALS_TESTS::LOG10, "Log 10"}
	};
	void Exp();
	void Log();
	void Log10();

	

	//COLOUR
	void ColourTests();
	enum class COLOUR_TESTS {
		GAMMA_TO_LINEAR,
		LINEAR_TO_GAMMA
	} ;
	std::map<COLOUR_TESTS, std::string> allColourOptionsText = std::map<COLOUR_TESTS, std::string>{
		{COLOUR_TESTS::GAMMA_TO_LINEAR,"Gamma To Linear"},
		{COLOUR_TESTS::LINEAR_TO_GAMMA,"Linear to Gamma"}
	};
	void GammaToLinear();
	void LinearToGamma();

	

	//ENCODING
	void EncodingTests();
	enum class ENCODING_TESTS {
		FLOAT_TO_HALF,
		HALF_TO_FLOAT
	} ;
	std::map<ENCODING_TESTS, std::string> allEncodingOptionsText = std::map<ENCODING_TESTS, std::string>{
		{ENCODING_TESTS::FLOAT_TO_HALF, "Float to Half"},
		{ENCODING_TESTS::HALF_TO_FLOAT, "Half to Float"}

	};
	void FloatToHalf();
	void HalfToFloat();

	

	//LERPING
	void LerpingTests();
	enum class LERPING_TESTS {
		INVERSE_LERP,
		LERP,
		LERP_ANGLE,
		LERP_UNCLAMPED,
		MOVE_TOWARDS,
		MOVE_TOWARDS_ANGLE,
		SMOOTH_DAMP,
		SMOOTH_DAMP_ANGLE,
		SMOOTH_STEP
	};
	std::map<LERPING_TESTS, std::string> allLerpingOptionsText = std::map<LERPING_TESTS, std::string>{
		{LERPING_TESTS::INVERSE_LERP, "Inverse Lerp"},
		{LERPING_TESTS::LERP, "Lerp"},
		{LERPING_TESTS::LERP_ANGLE, "Lerp Angle"},
		{LERPING_TESTS::LERP_UNCLAMPED, "Lerp Unclamped"},
		{LERPING_TESTS::MOVE_TOWARDS, "Move Towards"},
		{LERPING_TESTS::MOVE_TOWARDS_ANGLE,"Move Towards Angle"},
		{LERPING_TESTS::SMOOTH_DAMP, "Smooth Damp"},
		{LERPING_TESTS::SMOOTH_DAMP_ANGLE, "Smooth Damp Angle"},
		{LERPING_TESTS::SMOOTH_STEP, "Smooth Step"}
	};
	void InverseLerp();
	void Lerp();
	void LerpAngle();
	void LerpUnclamped();
	void MoveTowards();
	void MoveTowardsAngle();
	void SmoothDamp();
	void SmoothDampAngle();
	void SmoothStep();

	//RANDOMNESS
	void RandomnessTests();
	enum class RANDOMNESS_TESTS {
		PERLIN_NOISE,
		PING_PONG,
		REPEAT
	} ;
	std::map<RANDOMNESS_TESTS, std::string> allRandomnessOptionsText = std::map<RANDOMNESS_TESTS, std::string>{
		{RANDOMNESS_TESTS::PERLIN_NOISE,"Perlin Noise"},
		{RANDOMNESS_TESTS::PING_PONG, "Ping Pong"},
		{RANDOMNESS_TESTS::REPEAT,"Repeat"}
	};
	void PerlinNoise();
	void PingPong();
	void Repeat();

	
};