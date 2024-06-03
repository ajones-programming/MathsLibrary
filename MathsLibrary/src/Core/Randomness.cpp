#include "MathsLibrary.h"
#include <vector>
#include <iostream>
const std::vector <std::vector<std::pair<float, float>>> listOfPoints{
	{{0.7739,0.6333},{-0.5366,0.8439},{-0.9661,-0.2581}},
	{{0.9093,-0.4161},{-0.6636,-0.7481},{-0.7149,0.6993}},
	{{0.4677,-0.8839},{0.7958,-0.6056},{-0.9165,-0.4000}},

};

#define X_LIMIT 3.f
#define Y_LIMIT 3.f
#define SMOOTHVALUE (x) (x*x*(3-2.f*x))

float dotProduct(float x1, float y1, float x2, float y2) {
	return x1 * x2 + y1 * y2;
}
//lacking proper smoothing algorithm!
float MathsLibrary::PerlinNoise(const float x, const float y)
{

	float xValue = x;
	float yValue = y;
	xValue -= Floor(xValue / X_LIMIT) * X_LIMIT;
	yValue -= Floor(yValue / Y_LIMIT) * Y_LIMIT;

	int xCieling = (FloorToInt(xValue) + 1)%(FloorToInt(X_LIMIT));
	int yCieling = (FloorToInt(yValue) + 1) % (FloorToInt(Y_LIMIT));


	float xDifference = xValue - Floor(xValue);
	float yDifference = yValue - Floor(yValue);
	std::pair<float, float> allDirectionVectors[4] = {
	listOfPoints[Floor(xValue)][Floor(yValue)],
	listOfPoints[xCieling][Floor(yValue)],
	listOfPoints[Floor(xValue)][yCieling],
	listOfPoints[xCieling][yCieling] };

	float dotProducts[4];

	for (int Count = 0; Count < 4; Count++) {
		dotProducts[Count] = dotProduct(allDirectionVectors[Count].first, allDirectionVectors[Count].second,
			Count % 2 == 0 ? xDifference : xDifference - 1, Count / 2 == 0 ? yDifference : yDifference - 1);
	}

	return SmoothStep(SmoothStep(dotProducts[0],dotProducts[1],xDifference),
		SmoothStep(dotProducts[2], dotProducts[3], xDifference),
		yDifference) * 2.f + 0.4f;
}


#define TOTAL_TIME 10.f
float MathsLibrary::PingPong(const float time, const float length)
{
	float newTime = time - Floor(time / length) * length;
	if (newTime < TOTAL_TIME / 2.f) {
		return 2.f * newTime;
	}
	else {
		return 2.f * (length - newTime);
	}


}

float MathsLibrary::Repeat(const float time, const float length)
{
	float newTime = time - Floor(time / length) * length;
	return newTime;
}
