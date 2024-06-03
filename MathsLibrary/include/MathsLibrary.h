#pragma once

#ifdef MATHSLIBRARY_EXPORTS
#define MATHSLIBRARY_API __declspec(dllexport)
#else
#define MATHSLIBRARY_API __declspec(dllimport)
#endif

#include <limits>

extern "C" MATHSLIBRARY_API class MathsLibrary {
public:

	//Deg2Rad	Degrees - to - radians conversion constant(Read Only).
	MATHSLIBRARY_API static float Deg2Rad(const float value);

	//	Infinity	A representation of positive infinity(Read Only).
	MATHSLIBRARY_API static inline constexpr float Infinity{ std::numeric_limits<double>::infinity() };

	//	NegativeInfinity	A representation of negative infinity(Read Only).
	MATHSLIBRARY_API static inline constexpr float NegativeInfinity{ -std::numeric_limits<double>::infinity() };

	//	PI	The well - known 3.14159265358979... value(Read Only).
	MATHSLIBRARY_API static inline constexpr float PI{ 3.141592f };

	//	Rad2Deg	Radians - to - degrees conversion constant(Read Only).
	MATHSLIBRARY_API static float Rad2Deg(const float value);

	//BASIC:
	//	Abs	Returns the absolute value of f.
	MATHSLIBRARY_API static float Abs (const float value);
	//	Approximately	Compares two floating point values and returns true if they are similar.
	MATHSLIBRARY_API static bool Approx(const float input, const float toCompareTo);
	//	Ceil	Returns the smallest integer greater to or equal to f.
	MATHSLIBRARY_API static float Ceil(const float value);
	//	CeilToInt	Returns the smallest integer greater to or equal to f.
	MATHSLIBRARY_API static int CeilToInt(const float value);
	//	Clamp	Clamps the given value between the given minimum float and maximum float values.
	//  Returns the given value if it is within the minimumand maximum range.
	MATHSLIBRARY_API static float Clamp(const float value, const float minimum, const float maximum);
	//	Clamp01	Clamps value between 0 and 1 and returns value.
	MATHSLIBRARY_API static float Clamp01(const float value);
	//	Floor	Returns the largest integer smaller than or equal to f.
	MATHSLIBRARY_API static float Floor(const float value);
	//	FloorToInt	Returns the largest integer smaller to or equal to f.
	MATHSLIBRARY_API static int FloorToInt(const float value);
	//	Max	Returns largest of two or more values.
	MATHSLIBRARY_API static float Max(const float value, const float toCompareTo);
	MATHSLIBRARY_API static float Max(const float[], const int numberInArray);
	//	Min	Returns the smallest of two or more values.
	MATHSLIBRARY_API static float Min(const float value1, const float value2);
	MATHSLIBRARY_API static float Min(const float[], const int numberInArray);
	//	Pow	Returns f raised to power p.
	MATHSLIBRARY_API static int Pow(const int value, const int toPowerOf);
	MATHSLIBRARY_API static float Pow(const float value, const int toPowerOf);
	MATHSLIBRARY_API static float Pow(const float value, const float toPowerOf);
	//	Round	Returns f rounded to the nearest integer.
	MATHSLIBRARY_API static float Round(const float value);
	//	RoundToInt	Returns f rounded to the nearest integer.
	MATHSLIBRARY_API static float RoundToInt(const float value);
	//	Sign	Returns the sign of f.
	MATHSLIBRARY_API static float Sign(const float value);
	//	Sqrt	Returns square root of f.
	MATHSLIBRARY_API static float Sqrt(const float value);


	//TRIG:
	//	Acos	Returns the arc - cosine of f - the angle in radians whose cosine is f.
	MATHSLIBRARY_API static float Acos(const float value, const bool isRadians);
	//	Asin	Returns the arc - sine of f - the angle in radians whose sine is f.
	MATHSLIBRARY_API static float Asin(const float value, const bool isRadians);
	//	Atan	Returns the arc - tangent of f - the angle in radians whose tangent is f.
	MATHSLIBRARY_API static float Atan(const float value, const bool isRadians);
	//	Atan2	Returns the angle in radians whose Tan is y / x.
	MATHSLIBRARY_API static float Atan2(const float x, const float y, const bool isRadians);
	//	Cos	Returns the cosine of angle f.
	MATHSLIBRARY_API static float Cos(const float value, const bool isRadians);
	//	DeltaAngle	Calculates the shortest difference between two given angles given in degrees.
	MATHSLIBRARY_API static float DeltaAngle(const float value, const float value2, const bool isRadians);
	//	Sin	Returns the sine of angle f.
	MATHSLIBRARY_API static float Sin(const float value, const bool isRadians);
	//	Tan	Returns the tangent of angle f in radians.
	MATHSLIBRARY_API static float Tan(const float value, const bool isRadians);

	//POWERS
	//	ClosestPowerOfTwo	Returns the closest power of two value.
	MATHSLIBRARY_API static float ClosestPowerOfTwo(float);
	//	IsPowerOfTwo	Returns true if the value is power of two.
	MATHSLIBRARY_API static bool IsPowerOfTwo(float);
	//	NextPowerOfTwo	Returns the next power of two that is equal to, or greater than, the argument.
	MATHSLIBRARY_API static float NextPowerOfTwo(float);

	//EXPONENTIALS
	//	Exp	Returns e raised to the specified power.
	MATHSLIBRARY_API static float Exp(float);
	//	Log	Returns the logarithm of a specified number in a specified base.
	MATHSLIBRARY_API static float Log(float);
	//	Log10	Returns the base 10 logarithm of a specified number.
	MATHSLIBRARY_API static float Log10(float);

	//COLOUR
	//	CorrelatedColorTemperatureToRGB	Convert a color temperature in Kelvin to RGB color.
	//CANNOT DO YET
	//static float CorrolatedColourTemperatureToRPG(float);
	//	GammaToLinearSpace	Converts the given value from gamma(sRGB) to linear color space.
	MATHSLIBRARY_API static float GammaToLinearSpace(float);
	//	LinearToGammaSpace	Converts the given value from linear to gamma(sRGB) color space.
	MATHSLIBRARY_API static float LinearToGammaSpace(float);

	//ENCODING
	//	FloatToHalf	Encode a floating point value into a 16 - bit representation.
	MATHSLIBRARY_API static unsigned short FloatToHalf(float);
	//	HalfToFloat	Convert a half precision float to a 32 - bit floating point value.
	MATHSLIBRARY_API static float HalfToFloat(unsigned short);

	//LERPING
	//	InverseLerp	Determines where a value lies between two points.
	MATHSLIBRARY_API static float InverseLerp(float start, float end, float value);
	//	Lerp	Linearly interpolates between aand b by t.
	MATHSLIBRARY_API static float Lerp(float start, float end, float t);
	//	LerpAngle	Same as Lerp but makes sure the values interpolate correctly when they wrap around 360 degrees.
	MATHSLIBRARY_API static float LerpAngle(float start, float end, float t, bool isRadians = true);
	//	LerpUnclamped	Linearly interpolates between a and b by t with no limit to t.
	MATHSLIBRARY_API static float LerpUnclamped(float start, float end, float t);
	//	MoveTowards	Moves a value current towards target.
	MATHSLIBRARY_API static float MoveTowards(float current, float end, float maxDelta);
	//	MoveTowardsAngle	Same as MoveTowards but makes sure the values interpolate correctly when they wrap around 360 degrees.
	MATHSLIBRARY_API static float MoveTowardsAngle(float current, float end, float maxDelta, bool isRadians);
	//	SmoothDamp	Gradually changes a value towards a desired goal over time.
	MATHSLIBRARY_API static float SmoothDamp(const float current, const float target, float& velocity, const float time, const float maxSpeed = Infinity, const float deltaTime = 0);
	//	SmoothDampAngle	Gradually changes an angle given in degrees towards a desired goal angle over time.
	MATHSLIBRARY_API static float SmoothDampAngle(const float current, const float target, float& velocity, const float time, const bool isRadians, const float maxSpeed = Infinity, const float deltaTime = 0);
	//	SmoothStep	Interpolates between min and max with smoothing at the limits.
	MATHSLIBRARY_API static float SmoothStep(const float min, const float max,const float t);

	//RANDOMNESS
	//	PerlinNoise	Generate 2D Perlin noise.
	MATHSLIBRARY_API static float PerlinNoise(const float x, const float y);
	//	PingPong	PingPong returns a value that will increment and decrement between the value 0 and length.
	MATHSLIBRARY_API static float PingPong(const float time, const float length);
	//	Repeat	Loops the value t, so that it is never larger than lengthand never smaller than 0.
	MATHSLIBRARY_API static float Repeat(const float time, const float length);


private:
	//ease


	static float PowerInt(float, int);
	static float DecimalPower(float, float);
	static float ExpCore(float);
	static constexpr int ACCURACY{ 5 };
	static float totalTaylorSeries__DivisionPrecalculated(float value, float taylor_values[ACCURACY]);
	static float totalTaylorSeries__DivisionPrecalculated(float value, float* taylor_values, int size);

	static float acosRadians(float);
	static float asinRadians(float);
	static float atanRadians(float);

	static int ClosestTwoPowerN(float);
	static float DividedByClosestPowerOfTwo(float);
	static float FindLnValueBetween1And2(float);


	typedef union {
		float f;
		struct {
			unsigned int mantisa : 23;
			unsigned int exponent : 8;
			unsigned int sign : 1;
		} parts;
	} float_cast;

	typedef union {
		signed short s;
		struct {
			unsigned int mantissa : 10;
			unsigned int exponent : 5;
			unsigned int sign : 1;
		} parts;

	} half_cast;



	
};