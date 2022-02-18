#pragma once
#include <math.h>

struct Vec2
{
	float x;
	float y;

	Vec2()
	{
		x = 0;
		y = 0;
	}

	Vec2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
};

void vnormalize(Vec2& vec);
float vdistance(Vec2 left, Vec2 right);

