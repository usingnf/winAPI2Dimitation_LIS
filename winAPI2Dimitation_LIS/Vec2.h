#pragma once
#include <math.h>

struct Vec2
{
	double x;
	double y;

	Vec2()
	{
		x = 0;
		y = 0;
	}

	Vec2(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
};

void normalize(Vec2& vec);
float distance(Vec2 left, Vec2 right);

