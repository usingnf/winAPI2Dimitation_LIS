#include "pch.h"
#include "CMonster.h"

CMonster::CMonster()
{
	speed = mSpeed;
	scale = mScale;
}

CMonster* CMonster::clone()
{
	return new CMonster(*this);
}

CMonster::~CMonster()
{
}

void CMonster::setCenter(Vec2 vec)
{
	this->center = vec;
}

void CMonster::update()
{
	if (isUp == true)
	{
		this->pos.y += -speed * DT();
		if (center.y - this->pos.y > maxMove)
		{
			isUp = false;
		}
	}
	else
	{
		this->pos.y += speed * DT();
		if (this->pos.y - center.y > maxMove)
		{
			isUp = true;
		}
	}
}

void CMonster::render(HDC& hDC)
{
	Ellipse(hDC,
		pos.x - (scale.x / 2),
		pos.y - (scale.y / 2),
		pos.x + (scale.x / 2),
		pos.y + (scale.y / 2));
}
