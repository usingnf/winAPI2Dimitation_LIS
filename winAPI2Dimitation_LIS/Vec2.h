#pragma once
#include <math.h>

class Vec2
{
public:
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

	static void normalize(Vec2& vec);
	static double distance(Vec2 left, Vec2 right);
	static double getAngle(Vec2 vec);
	static double getAngle(Vec2 left, Vec2 right);
};

//void normalize(Vec2& vec);
//double distance(Vec2 left, Vec2 right);
//double getAngle(Vec2 vec);
//double getAngle(Vec2 left, Vec2 right);
