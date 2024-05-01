#include "MathsLibrary.h"
#include <iostream>

//ALL A-VALUES RETURN BETWEEN 0 TO PI

//I WAS NOT ABLE TO FIND A RECURSIVE WAY TO FIND ACOS OR ASIN, SO I AM USING THE FIRST FIVE OF THE TAYLOR SERIES, GIVEN DIFFERENT CONDITIONS
//THIS WILL SPLIT UP THE POSSIBLE INPUT VALUES BETWEEN -1 and 1 INTO FIVE CATEGORIES
//WHICH WILL DETERMINE WHICH EQUATION I USE TO CALCULATE 


float MathsLibrary::Acos(const float value, const bool isRadians)
{
	if (value > 1.f || value < -1.f) {
		//ERROR HERE
		return 0.f;
	}
	float returnValue = acosRadians(value);
	return isRadians ? returnValue : MathsLibrary::Rad2Deg(returnValue);
}
float MathsLibrary::acosRadians(const float value) {
	//EXPECTED VALUES
	if (value == 0.f) {
		return MathsLibrary::PI * 0.5f;
	}
	if (value == 1.f) {
		return 0.f;
	}
	if (value == -1.f) {
		return  MathsLibrary::PI;
	}
	//root2/2
	if (MathsLibrary::Approx(0.7071067812f, value)) {
		return  MathsLibrary::PI * 0.25f;
	}
	//-root2/2
	if (MathsLibrary::Approx(-0.7071067812f, value)) {
		return  MathsLibrary::PI * 0.75f;
	}
	//root3/2
	if (MathsLibrary::Approx(0.8660254038f, value)) {
		return  MathsLibrary::PI / 6.f;
	}
	//-root3/2
	if (MathsLibrary::Approx(-0.8660254038f, value)) {
		return 5*MathsLibrary::PI / 6.f;
	}
	//0.5
	if (MathsLibrary::Approx(0.5f, value)) {
		return MathsLibrary::PI / 3.f;
	}
	//-0.5
	if (MathsLibrary::Approx(-0.5f, value)) {
		return  2 * MathsLibrary::PI / 3.f;
	}

	//TAYLOR SERIES CENTRED AROUND 0
	if (value >= -0.2f && value <= 0.2f) {
		float VALUES_LIST[ACCURACY] = { 1.570796327f, -1.f, 0, -0.1666666667f, 0 };
		return totalTaylorSeries__DivisionPrecalculated(value, VALUES_LIST);
	}
	if (value > 0.f) {
		//TAYLOR SERIES CENTRED AROUND 0.5
		if (value >= 0.2f && value <= 0.8f) {
			float newVal = value - 0.5f;
			float VALUES_LIST[ACCURACY] = { 1.047197551f,-1.154700538f,-0.3849001795f,-0.5132002393f,-0.5987336125f };
			return totalTaylorSeries__DivisionPrecalculated(newVal, VALUES_LIST);
		}
		//TAYLOR SERIES CENTRED AROUND 0.9
		else {
			float newVal = value - 0.9f;
			float VALUES_LIST[ACCURACY] = { 0.4510268118f,-2.294157339f,-5.433530539f,-27.75019496f,-173.8428746f };
			return totalTaylorSeries__DivisionPrecalculated(newVal, VALUES_LIST);
		}
	}
	else {
		//TAYLOR SERIES CENTRED AROUND -0.5
		if (value <= -0.2f && value >= -0.8f) {
			float newVal = value + 0.5f;
			float VALUES_LIST[ACCURACY] = { 2.094395102f,-1.154700538f,0.3849001795f,-0.5132002393f,0.5987336125f };
			return totalTaylorSeries__DivisionPrecalculated(newVal, VALUES_LIST);
		}
		//TAYLOR SERIES CENTRED AROUND -0.9
		else {
			float newVal = value + 0.9f;
			float VALUES_LIST[ACCURACY] = { 2.690565842f,-2.294157339f,5.433530539f, -27.75019496f, 173.8428746f };
			return totalTaylorSeries__DivisionPrecalculated(newVal, VALUES_LIST);
		}
	}

	return 0.0f;
}

//alternate solution would be to flip the result and minus half pi!

float MathsLibrary::Asin(const float value, const bool isRadians)
{
	if (value > 1.f || value < -1.f) {
		//ERROR HERE
		return 0.f;
	}
	float returnValue = asinRadians(value);
	return isRadians ? returnValue : MathsLibrary::Rad2Deg(returnValue);
}
float MathsLibrary::asinRadians(float value) {
	if (value == 0.f) {
		return 0.f;
	}
	if (value == 1.f) {
		return MathsLibrary::PI * 0.5f;
	}
	if (value == -1.f) {
		return -MathsLibrary::PI * 0.5f;
	}
	//root2/2
	if (MathsLibrary::Approx(0.7071067812f, value)) {
		return  MathsLibrary::PI * 0.25f;
	}
	//-root2/2
	if (MathsLibrary::Approx(-0.7071067812f, value)) {
		return - MathsLibrary::PI * 0.25f;
	}
	//root3/2
	if (MathsLibrary::Approx(0.8660254038f, value)) {
		return  MathsLibrary::PI / 3.f;
	}
	//-root3/2
	if (MathsLibrary::Approx(-0.8660254038f, value)) {
		return - MathsLibrary::PI / 3.f;
	}
	//0.5
	if (MathsLibrary::Approx(0.5f, value)) {
		return MathsLibrary::PI / 6.f;
	}
	//-0.5
	if (MathsLibrary::Approx(-0.5f, value)) {
		return  -MathsLibrary::PI / 6.f;
	}

	//TAYLOR SERIES CENTRED AROUND 0
	if (value >= -0.2f && value <= 0.2f) {
		float VALUES_LIST[ACCURACY] = {0.f, 1.f, 0, 0.1666666667f, 0 };
		return totalTaylorSeries__DivisionPrecalculated(value, VALUES_LIST);
	}
	if (value > 0.f) {
		//TAYLOR SERIES CENTRED AROUND 0.5
		if (value >= 0.2f && value <= 0.8f) {
			float newVal = value - 0.5f;
			float VALUES_LIST[ACCURACY] = { 0.5235987756f,1.154700538f,0.3849001795f,0.5132002393f,0.5987336125f };
			return totalTaylorSeries__DivisionPrecalculated(newVal, VALUES_LIST);
		}
		//TAYLOR SERIES CENTRED AROUND 0.9
		else {
			float newVal = value - 0.9f;
			float VALUES_LIST[ACCURACY] = { 1.119769515f,2.294157339f,5.433530539f,27.75019496f,173.8428746f };
			return totalTaylorSeries__DivisionPrecalculated(newVal, VALUES_LIST);
		}
	}
	else {
		//TAYLOR SERIES CENTRED AROUND -0.5
		if (value <= -0.2f && value >= -0.8f) {
			float newVal = value + 0.5f;
			float VALUES_LIST[ACCURACY] = { -0.5235987756f,1.154700538f,-0.3849001795f,0.5132002393f,-0.5987336125f };
			return totalTaylorSeries__DivisionPrecalculated(newVal, VALUES_LIST);
		}
		//TAYLOR SERIES CENTRED AROUND -0.9
		else {
			float newVal = value + 0.9f;
			float VALUES_LIST[ACCURACY] = {-1.119769515f,2.294157339f,-5.433530539f,27.75019496f,-173.8428746f };
			return totalTaylorSeries__DivisionPrecalculated(newVal, VALUES_LIST);
		}
	}

	return 0.0f;
}


float MathsLibrary::Atan(const float value, const bool isRadians )
{
	float returnValue = atanRadians(value);
	return isRadians ? returnValue : MathsLibrary::Rad2Deg(returnValue);
}

float MathsLibrary::atanRadians(float value) {
	if (value == 0.f) {
		return 0.f;
	}
	if (value == MathsLibrary::Infinity) {
		return MathsLibrary::PI * 0.5f;
	}
	if (value == MathsLibrary::NegativeInfinity) {
		return -MathsLibrary::PI * 0.5f;
	}
	//1
	if (MathsLibrary::Approx(1.f, value)) {
		return  MathsLibrary::PI * 0.25f;
	}
	//-1
	if (MathsLibrary::Approx(-1.f, value)) {
		return -MathsLibrary::PI * 0.25f;
	}
	//root3
	if (MathsLibrary::Approx(1.732050808f, value)) {
		return  MathsLibrary::PI / 3.f;
	}
	//-root3
	if (MathsLibrary::Approx(-1.732050808f, value)) {
		return -MathsLibrary::PI / 3.f;
	}
	//root3/3
	if (MathsLibrary::Approx(0.5773502692f, value)) {
		return MathsLibrary::PI / 6.f;
	}
	//root3/3
	if (MathsLibrary::Approx(-0.5773502692, value)) {
		return  -MathsLibrary::PI / 6.f;
	}
	if (value <= 0.5f && value >= -0.5f) {
		float VALUES_LIST[ACCURACY] = { 0,1.f,0.f,-0.33333333f,0.f };
		return totalTaylorSeries__DivisionPrecalculated(value, VALUES_LIST);
	}

	if (value > 0.f) {
		//CENTRED AROUND 1
		if (value < 1.2f) {
			float newValue = value - 1.f;
			float VALUES_LIST[ACCURACY] = { 0.7853981634f,0.5f,-0.25f,0.0833333333f,0.f };
			return totalTaylorSeries__DivisionPrecalculated(newValue, VALUES_LIST);
		}
		if (value < 2.2f) {
			float newValue = value - 1.732050808f;
			float VALUES_LIST[ACCURACY] = { 1.047197551f,0.25f,-0.1082531755f,0.041666667f,-0.01353164693f };
			return totalTaylorSeries__DivisionPrecalculated(newValue, VALUES_LIST);
		}
		if (value < 5.f) {
			float newValue = value - 3.5f;
			float VALUES_LIST[ACCURACY] = { 1.292496668f,0.0754716981132f,-0.01993592026f,5.122797119e-3f,-1.27748888e-3f };
			return totalTaylorSeries__DivisionPrecalculated(newValue, VALUES_LIST);
		}
		if (value < 15.f) {
			float newValue = value - 10.f;
			float VALUES_LIST[ACCURACY] = { 1.471127674f,0.00990099f,-9.802960494e-4f,9.673548474e-5f,-9.51370541e-6f };
			return totalTaylorSeries__DivisionPrecalculated(newValue, VALUES_LIST);
		}
		if (value < 35.f) {
			float newValue = value - 25.f;
			float VALUES_LIST[ACCURACY] = {1.53081764f,1.597444089e-3f,-6.379569047e-5f,2.546392416e-6f,-1.015844575e-7f };
			return totalTaylorSeries__DivisionPrecalculated(newValue, VALUES_LIST);
		}
		if (value < 63.f) {
			float newValue = value - 40.f;
			float VALUES_LIST[ACCURACY] = { 1.545801533f,6.24609619e-4f,-1.560548705e-5f,3.898122649e-7f,-9.735160756e-9f };
			return totalTaylorSeries__DivisionPrecalculated(newValue, VALUES_LIST);
		}
		return MathsLibrary::PI * 0.5f;
	}
	else {
		if (value > -1.2f) {
			float newValue = value + 1.f;
			float VALUES_LIST[ACCURACY] = {-0.7853981634f,0.5f,0.25f,0.0833333333f,0.f };
			return totalTaylorSeries__DivisionPrecalculated(newValue, VALUES_LIST);
		}
		if (value > -2.2f) {
			float newValue = value + 1.732050808f;
			float VALUES_LIST[ACCURACY] = {-1.047197551f,0.25f,0.1082531755f,0.041666667f,0.01353164693f };
			return totalTaylorSeries__DivisionPrecalculated(newValue, VALUES_LIST);
		}
		if (value > -5.f) {
			float newValue = value + 3.5f;
			float VALUES_LIST[ACCURACY] = {-1.292496668f,0.0754716981132f,0.01993592026f,5.122797119e-3f,1.27748888e-3f };
			return totalTaylorSeries__DivisionPrecalculated(newValue, VALUES_LIST);
		}
		if (value > -15.f) {
			float newValue = value + 10.f;
			float VALUES_LIST[ACCURACY] = { -1.471127674f,0.00990099f,9.802960494e-4f,9.673548474e-5f,9.51370541e-6f };
			return totalTaylorSeries__DivisionPrecalculated(newValue, VALUES_LIST);
		}
		if (value > -35.f) {
			float newValue = value + 25.f;
			float VALUES_LIST[ACCURACY] = {-1.53081764f,1.597444089e-3f,6.379569047e-5f,2.546392416e-6f,1.015844575e-7f };
			return totalTaylorSeries__DivisionPrecalculated(newValue, VALUES_LIST);
		}
		if (value > -63.f) {
			float newValue = value - 40.f;
			float VALUES_LIST[ACCURACY] = { -1.545801533f,6.24609619e-4f,1.560548705e-5f,3.898122649e-7f,9.735160756e-9f };
			return totalTaylorSeries__DivisionPrecalculated(newValue, VALUES_LIST);
		}
		return MathsLibrary::PI * -0.5f;
	}

	return 0.0f;
}

float MathsLibrary::Atan2(const float x, const float y, const bool isRadians)
{
	//unmeasurable
	if (x == 0.f && y == 0.f) {
		return 0.f;
	}
	if (Approx(x,0.f)) {
		return (y > 0 ? PI * 0.5f : PI * -0.5f);
	}
	if (Approx(y, 0.f)) {
		return (x > 0 ? 0 : PI);
	}
	float value = y / x;
	float calculatedValue = 0;
	if (x > 0) {
		return Atan(value,isRadians);
	}
	if (y > 0) {
		return Atan(value, isRadians) + (isRadians ? PI : 180);
	}
	return Atan(value, isRadians) - (isRadians ? PI : 180);
}

float MathsLibrary::Cos(const float value, const bool isRadians)
{
	float calculatedValue = isRadians ? value : Deg2Rad(value);
	int chopOffAmount = FloorToInt((calculatedValue + PI) /( 2.f * PI));
	float rangedValue = calculatedValue - (2 * PI * chopOffAmount);

	if (Approx(rangedValue, 0)) { return 1; }
	//return sqrt 3 / 2
	if (Approx(rangedValue, PI / 6.f) || Approx(rangedValue, -PI / 6.f)) { return 0.8660254038f; }
	//return sqrt 2 / 2
	if (Approx(rangedValue, PI / 4.f) || Approx(rangedValue, -PI / 4.f)) { return 0.7071067812f; }
	if (Approx(rangedValue, PI / 3.f) || Approx(rangedValue, -PI / 3.f)) { return 0.5f; }
	if (Approx(rangedValue, PI / 2.f) || Approx(rangedValue, -PI / 2.f)) { return 0.f; }
	if (Approx(rangedValue, 2 * PI / 3.f) || Approx(rangedValue, -2.f * PI / 3.f)) { return -0.5f; }
	if (Approx(rangedValue, 3.f*PI/4.f) || Approx(rangedValue, -3.f * PI / 4.f)){return -0.7071067812f;}
	if (Approx(rangedValue, 5.f * PI / 6.f) || Approx(rangedValue, -5.f * PI / 6.f)) { return -0.8660254038f; }
	if (Approx(rangedValue, PI) || Approx(rangedValue, -PI)) { return -1.f; }


		//an improved version of this algorithm would just flip the result from x > 0 for x < 0
	if (rangedValue >= -PI * 0.25 && rangedValue <= PI * 0.25) {
		float squared = rangedValue * rangedValue;
		return 1.f - squared /2.f + Pow(squared,2)/24.f - Pow(squared,3)/720.f;
	}
	if (rangedValue > 0.f) {
		if (rangedValue < PI * 0.75f) {
			float offset = rangedValue - PI * 0.5f;
			float squared = offset * offset;
			return offset*(-1 + squared / 6.f - squared*squared / 120.f);
		}
		else {
			float offset = rangedValue - PI;
			float squared = offset * offset;
			return -1.f + squared / 2.f - squared * squared / 24.f + squared * squared*squared / 720.f;
		}
	}
	else {
		if (rangedValue > -PI * 0.75f) {
			float offset = rangedValue + PI * 0.5f;
			float squared = offset * offset;
			return offset*(1.f - squared / 6.f + squared * squared /120.f);
		}
		else {
			float offset = rangedValue + PI;
			float squared = offset * offset;
			return -1.f + squared / 2.f - squared * squared / 24.f + squared * squared*squared / 720.f;
		}
	}

	return 0.0f;
}

float MathsLibrary::DeltaAngle(const float value, const float value2, const bool isRadians)
{
	float compare1 = isRadians ? value : Deg2Rad(value);
	float compare2 = isRadians ? value2 : Deg2Rad(value2);

	float difference = compare2 - compare1;

	int differenceInt = FloorToInt((difference + PI) / (2.f * PI));
	return (difference - (2 * PI * differenceInt)) * (isRadians ? 1.f : 180.f / PI);


}

float MathsLibrary::Sin(const float value, const bool isRadians)
{
	float calculatedValue = isRadians ? value : Deg2Rad(value);
	int chopOffAmount = FloorToInt( (calculatedValue + PI) / (2.f * PI));
	float rangedValue = calculatedValue - (2 * PI * chopOffAmount);

	if (Approx(rangedValue, 0) || Approx(rangedValue, PI) || Approx(rangedValue, -PI)) { return 0; }
	if (Approx(rangedValue, PI / 6.f) || Approx(rangedValue, 5.f * PI / 6.f)) { return 0.5f; }
	//return sqrt 2 / 2
	if (Approx(rangedValue, PI / 4.f) || Approx(rangedValue, 3.f * PI / 4.f)) { return 0.7071067812f; }
	//return sqrt 3 / 2
	if (Approx(rangedValue, PI / 3.f) || Approx(rangedValue, 2.f * PI / 3.f)) { return 0.8660254038f; }
	if (Approx(rangedValue, PI / 2.f)) { return 1.f; }
	if (Approx(rangedValue, -PI / 6.f) || Approx(rangedValue, -5.f * PI / 6.f)) { return -0.5f; }
	if (Approx(rangedValue, -PI / 4.f) || Approx(rangedValue, -3.f * PI / 4.f)) {return -0.7071067812f;}
	if (Approx(rangedValue, -PI / 3.f) || Approx(rangedValue, -2.f * PI / 3.f)) {return -0.8660254038f;}
	if (Approx(rangedValue, -PI/2.f)) { return -1.f; }


	if (rangedValue >= -PI * 0.25 && rangedValue <= PI * 0.25) {
		float squared = rangedValue * rangedValue;
		return rangedValue * (1.f - squared / 6.f + Pow(squared, 2) / 120.f);
	}



	if (rangedValue > 0.f) {
		if (rangedValue < PI * 0.75f) {
			float offset = rangedValue - PI * 0.5f;
			float squared = offset * offset;
			return 1.f - squared / 2.f + Pow(squared, 2) / 24.f - Pow(squared, 3) / 720.f;
		}
		else {
			float offset = rangedValue - PI;
			float squared = offset * offset;
			return offset * (-1 + squared / 6.f - Pow(squared, 2) / 120.f);
		}
	}
	else {
		if (rangedValue > -PI * 0.75f) {
			float offset = rangedValue + PI * 0.5f;
			float squared = offset * offset;
			return -1.f + squared / 2.f - Pow(squared, 2) / 24.f + Pow(squared, 3) / 720.f;
		}
		else {
			float offset = rangedValue + PI;
			float squared = offset * offset;
			return offset * (-1 + squared / 6.f - Pow(squared, 2) / 120.f);
		}
	}

	return 0.0f;
}


float MathsLibrary::Tan(const float value, const bool isRadians)
{
	float calculatedValue = isRadians ? value : Deg2Rad(value);
	int chopOffAmount = FloorToInt((calculatedValue + PI / 2.f) / PI);
	float rangedValue = calculatedValue - (PI * chopOffAmount);

	if (Approx(rangedValue, 0)) { return 0; }
	//root 3 / 3
	if (Approx(rangedValue, PI / 6.f)) { return 0.5773502692f; }
	if (Approx(rangedValue, PI / 4.f)) { return 1.f; }
	//root 3
	if (Approx(rangedValue, PI / 3.f)) { return 1.732050808f; }
	if (Approx(rangedValue, PI / 2.f)) { return Infinity; }
	if (Approx(rangedValue, -PI / 6.f)) { return -0.5773502692f; }
	if (Approx(rangedValue, -PI / 4.f)) { return -1.f; }
	//root 3
	if (Approx(rangedValue, -PI / 3.f)) { return -1.732050808f; }
	if (Approx(rangedValue, -PI / 2.f)) { return NegativeInfinity; }


	//-0.95 to 0.95. Around value of 0
	if (rangedValue >= -0.95f && rangedValue <= 0.95f) {
		float squared = rangedValue * rangedValue;
		return rangedValue * (1.f + squared / 3.f + squared * squared / 5.f + squared * squared * squared / 7.f);
	}

	if (rangedValue > 0.f) {
		//AROUND 1.1. Between 0.95 to 1.2
		if (rangedValue < 1.2f) {

			float newVal = value - 1.1f;
			float VALUES_LIST[ACCURACY] = { 1.964759657f, 4.860280511f, 9.54928307f,20.38213964f, 43.22910004f };
			return totalTaylorSeries__DivisionPrecalculated(newVal, VALUES_LIST);
		}
		//AROUND 1.3 Between 1.2 to 1.5
		if (rangedValue < 1.4f) {

			float newVal = value - 1.3f;
			float VALUES_LIST[ACCURACY] = { 3.602102448f, 13.97514205f, 50.33989337f, 185.9878338f, 686.727196f };
			return totalTaylorSeries__DivisionPrecalculated(newVal, VALUES_LIST);
		}
		if (rangedValue < 1.48f) {

			float newVal = value - 1.45f;
			float VALUES_LIST[ACCURACY] = { 8.238092753f, 68.86617221f, 567.325914f, 4696.638893f, 38880.45547f };
			return totalTaylorSeries__DivisionPrecalculated(newVal, VALUES_LIST);
		}
		if (rangedValue < 1.52f) {

			float newVal = value - 1.5f;
			float VALUES_LIST[ACCURACY] = { 14.10141995f, 199.8500445f, 2818.169405f, 119420.4208f, 6747262.695f };
			return totalTaylorSeries__DivisionPrecalculated(newVal, VALUES_LIST);
		}
		//AROUND 1.54
		else if (rangedValue < 1.54){
			float newVal = value - 1.54f;
			float VALUES_LIST[ACCURACY] = { 32.46113891f, 1054.72554f, 34237.59225f, 1111742.813f, 36098850.43f };
			return totalTaylorSeries__DivisionPrecalculated(newVal, VALUES_LIST);
		}
		return PI / 2.f;
	}
	else {
		//AROUND -1.1. Between -1.2 to -0.95
		if (rangedValue > -1.2f) {

			float newVal = value + 1.1f;
			float VALUES_LIST[ACCURACY] = { -1.964759657f, 4.860280511f,-9.54928307f,20.38213964f, -43.22910004f };
			return totalTaylorSeries__DivisionPrecalculated(newVal, VALUES_LIST);
		}
		if (rangedValue > -1.4f) {

			float newVal = value + 1.3f;
			float VALUES_LIST[ACCURACY] = { -3.602102448f, 13.97514205f,-50.33989337f, 185.9878338f, -686.727196f };
			return totalTaylorSeries__DivisionPrecalculated(newVal, VALUES_LIST);
		}
		if (rangedValue > -1.48f) {

			float newVal = value + 1.45f;
			float VALUES_LIST[ACCURACY] = { -8.238092753f, 68.86617221f, -567.325914f, 4696.638893f, -38880.45547f };
			return totalTaylorSeries__DivisionPrecalculated(newVal, VALUES_LIST);
		}
		if (rangedValue > -1.52f) {

			float newVal = value + 1.5f;
			float VALUES_LIST[ACCURACY] = { -14.10141995f, 199.8500445f, -2818.169405f, 119420.4208f, -6747262.695f };
			return totalTaylorSeries__DivisionPrecalculated(newVal, VALUES_LIST);
		}
		//AROUND 1.54
		else if (rangedValue > -1.54f){
			float newVal = value + 1.54f;
			float VALUES_LIST[ACCURACY] = { -32.46113891f, 1054.72554f,-34237.59225f, 1111742.813f,-36098850.43f };
			return totalTaylorSeries__DivisionPrecalculated(newVal, VALUES_LIST);
		}
		return -PI / 2.f;
	}
	return 0.0f;
}
