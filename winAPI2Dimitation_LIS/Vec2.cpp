#include "pch.h"
#include "Vec2.h"

void normalize(Vec2& vec)
{
	if (abs(vec.x) + abs(vec.y) == 0)
		return;
	float x = vec.x / (abs(vec.x) + abs(vec.y));
	float y = vec.y / (abs(vec.x) + abs(vec.y));
	vec.x = x;
	vec.y = y;
}

float distance(Vec2 left, Vec2 right)
{
	return sqrt(abs((left.x - right.x) * (left.x - right.x)) + abs((left.y - right.y) * (left.y - right.y)));
}