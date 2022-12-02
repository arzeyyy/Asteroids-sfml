#include "Math.h"
#include <iostream>

Math::Math()
{
}

double Math::Deg2Rad(double degrees)
{
	//return degrees * 4.0 * atan(1.0) / 180.0;
	return degrees * (3.14159f / 180.0f);
}


float Math::Magnitude(float x, float y)
{
	return sqrt((x * x) + (y * y));
}

