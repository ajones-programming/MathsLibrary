#include "MathsLibrary.h"

float MathsLibrary::InverseLerp(float start, float end, float value)
{
	if (Approx(end - start, 0)) {
		return 0.f;
	}
	return (value - start)/(end - start);
}

float MathsLibrary::Lerp(float start, float end, float t)
{
	if (Approx(start, end)) {
		return start;
	}
	float newTime = Clamp01(t);

	return newTime * (end - start) + start;
}

float MathsLibrary::LerpAngle(float start, float end, float t, bool isRadians)
{
	if (Approx(start, end)) {
		return start;
	}
	//find shortest distance between them
	float startingValueInRange = start - (isRadians ? 2 * PI : 360.f) * (Floor(start / (isRadians ? 2 * PI : 360.f)));
	float endingValueInRange = end - (isRadians ? 2 * PI : 360.f) * (Floor(end / (isRadians ? 2 * PI : 360.f)));

	if (Abs(endingValueInRange - startingValueInRange) > (isRadians ? PI : 180.f)) {
		endingValueInRange -= (isRadians ? 2 * PI : 360.f);
	}

	float result = Lerp(startingValueInRange, endingValueInRange, t);

	return  result - (isRadians ? 2 * PI : 360.f) * (Floor(result / (isRadians ? 2 * PI : 360.f)));

}

float MathsLibrary::LerpUnclamped(float start, float end, float t)
{
	if (Approx(start, end)) {
		return start;
	}
	return t * (end - start) + start;
}

//replicated the actual implementation, as I did not know what the use of this function was
float MathsLibrary::MoveTowards(float current, float end, float maxDelta)
{
	if (Approx(current, end)) {
		return current;
	}
	float magnitude = Abs(end - current);
	if (maxDelta >= magnitude) {
		return end;
	}
	return current + ((end - current) / magnitude) * maxDelta;
}

float MathsLibrary::MoveTowardsAngle(float current, float end, float maxDelta, bool isRadians)
{
	if (Approx(current, end)) {
		return current;
	}
	//find shortest distance between them
	float startingValueInRange = current - (isRadians ? 2 * PI : 360.f) * (Floor(current / (isRadians ? 2 * PI : 360.f)));
	float endingValueInRange = end - (isRadians ? 2 * PI : 360.f) * (Floor(end / (isRadians ? 2 * PI : 360.f)));

	if (Abs(endingValueInRange - startingValueInRange) > (isRadians ? PI : 180.f)) {
		endingValueInRange -= (isRadians ? 2 * PI : 360.f);
	}

	float result = MoveTowards(startingValueInRange, endingValueInRange, maxDelta);

	return  result - (isRadians ? 2 * PI : 360.f) * (Floor(result / (isRadians ? 2 * PI : 360.f)));
}

//time taken to reach the target?
float MathsLibrary::SmoothDamp(const float current, const float target, float& velocity,
	const float time, const float maxSpeed, const float deltaTime)
{
	if (Approx(current, target)) {
		velocity = 0;
		return target;
	}
	if (Approx(time, 0)) {
		return target;
	}
	
	//whatever this means?
	if (Abs(velocity) > Abs((target - current) * 5.f / time)) {
		velocity -= (target - current) * 5.5f * deltaTime / time;
	}
	else {
		velocity += (target - current) * 1.f * deltaTime / time;
	}

	float returnVal = current + velocity * deltaTime;
	if (Sign(target - returnVal) != Sign(target - current)) {
		return target;
	}
	return returnVal;
}

float MathsLibrary::SmoothDampAngle(const float current, const float target, float& velocity, const float time, const bool isRadians, const float maxSpeed, const float deltaTime)
{
	if (Approx(current, target)) {
		return current;
	}
	//find shortest distance between them
	float startingValueInRange = current - (isRadians ? 2 * PI : 360.f) * (Floor(current / (isRadians ? 2 * PI : 360.f)));
	float endingValueInRange = target - (isRadians ? 2 * PI : 360.f) * (Floor(target / (isRadians ? 2 * PI : 360.f)));
	if (Abs(endingValueInRange - startingValueInRange) > (isRadians ? PI : 180.f)) {
		endingValueInRange -= (isRadians ? 2 * PI : 360.f);
	}

	float result = SmoothDamp(startingValueInRange, endingValueInRange, velocity,time,isRadians);

	return  result - (isRadians ? 2 * PI : 360.f) * (Floor(result / (isRadians ? 2 * PI : 360.f)));
}


float MathsLibrary::SmoothStep(const float min, const float max, const float t)
{
	if (Approx(min, max)) {
		return min;
	}
	if (t >= 1.f) {
		return max;
	}
	if (t <= 0.f) {
		return min;
	}
	float multiplyBy = max - min;


	return t*t*(3-2*t)*multiplyBy + min;
}




