#pragma once
#include "pch.h"

struct Vec2
{
public:
	int x;
	int y;
	Vec2() : x{0}, y{0}
	{

	}
	Vec2(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

class CObject
{
private:
	Vec2 pos;

public:
	CObject();
	virtual ~CObject();
};