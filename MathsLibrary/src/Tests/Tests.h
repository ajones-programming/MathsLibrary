#pragma once
#include <map>
#include <string>

class Tests
{
public:
	Tests();
private:

	void ShowIntroduction();
	void MainOptions(bool&);
	void TypeCategory();

	typedef enum {
		STATIC,
		BASIC,
		TRIG,
		POWERS,
		EXPONENTIALS,
		COLOUR,
		ENCODING,
		LERPING,
		RANDOMNESS
	} MAIN_TEST_TYPES;
	std::map<int, std::string> allMainOptionsText = std::map<int, std::string>{
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
		typedef enum {
			DEG_2_RAD,
			INFINITY__DEFINED,
			NEGATIVE_INFINITY,
			PI__DEFINED,
			RAD_2_DEGREE

		} STATIC_TESTS;

		std::map<int, std::string> allStaticOptionsText = std::map<int, std::string>{
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

		void StaticTests();

	//BASIC
		typedef enum {
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
		} BASIC_TESTS;

		std::map<int, std::string> allBasicOptionsText = std::map<int, std::string>{
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

		void BasicTests();

	////TRIG:
		typedef enum {
			ACOS,
			ASIN,
			ATAN,
			ATAN2,
			COS,
			DELTAANGLE,
			SIN,
			TAN
		} TRIG_TESTS;

		std::map<int, std::string> allTrigOptionsText = std::map<int, std::string>{
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

		void TrigTests();

	////POWERS

		typedef enum {
			CLOSEST_POWER_OF_TWO,
			IS_POWER_OF_TWO,
			NEXT_POWER_OF_TWO
		} POWERS_TESTS;

		std::map<int, std::string> allPowersOptionsText = std::map<int, std::string>{
			{POWERS_TESTS::CLOSEST_POWER_OF_TWO,"Closest Power of Two"},
			{POWERS_TESTS::IS_POWER_OF_TWO, "Is Power of Two"},
			{POWERS_TESTS::NEXT_POWER_OF_TWO, "Next Power of Two"}
		};

		void ClosestPowerOfTwo();
		void IsPowerOfTwo();
		void NextPowerOfTwo();

		void PowersTests();

	////EXPONENTIALS
		typedef enum {
			EXP,
			LOG,
			LOG10
		} EXPONENTIALS_TESTS;

		std::map<int, std::string> allExponentialsOptionsText = std::map<int, std::string>{
			{EXPONENTIALS_TESTS::EXP,"Exponential"},
			{EXPONENTIALS_TESTS::LOG, "Ln"},
			{EXPONENTIALS_TESTS::LOG10, "Log 10"}
		};

		void Exp();
		void Log();
		void Log10();

		void ExponentialsTests();

	////COLOUR
		typedef enum {
			GAMMA_TO_LINEAR,
			LINEAR_TO_GAMMA
		} COLOUR_TESTS;

		std::map<int, std::string> allColourOptionsText = std::map<int, std::string>{
			{COLOUR_TESTS::GAMMA_TO_LINEAR,"Gamma To Linear"},
			{COLOUR_TESTS::LINEAR_TO_GAMMA,"Linear to Gamma"}
		};

		void GammaToLinear();
		void LinearToGamma();

		void ColourTests();

	////ENCODING
		typedef enum {
			FLOAT_TO_HALF,
			HALF_TO_FLOAT
		} ENCODING_TESTS;

		std::map<int, std::string> allEncodingOptionsText = std::map<int, std::string>{
			{ENCODING_TESTS::FLOAT_TO_HALF, "Float to Half"},
			{ENCODING_TESTS::HALF_TO_FLOAT, "Half to Float"}

		};

		void FloatToHalf();
		void HalfToFloat();

		void EncodingTests();

	////LERPING
		typedef enum {
			INVERSE_LERP,
			LERP,
			LERP_ANGLE,
			LERP_UNCLAMPED,
			MOVE_TOWARDS,
			MOVE_TOWARDS_ANGLE,
			SMOOTH_DAMP,
			SMOOTH_DAMP_ANGLE,
			SMOOTH_STEP
		} LERPING_TESTS;

		std::map<int, std::string> allLerpingOptionsText = std::map<int, std::string>{
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

		void LerpingTests();

	////RANDOMNESS
		typedef enum {
			PERLIN_NOISE,
			PING_PONG,
			REPEAT
		} RANDOMNESS_TESTS;
		std::map<int, std::string> allRandomnessOptionsText = std::map<int, std::string>{
			{RANDOMNESS_TESTS::PERLIN_NOISE,"Perlin Noise"},
			{RANDOMNESS_TESTS::PING_PONG, "Ping Pong"},
			{RANDOMNESS_TESTS::REPEAT,"Repeat"}
		};

		void PerlinNoise();
		void PingPong();
		void Repeat();

		void RandomnessTests();


};

