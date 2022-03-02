#include "pch.h"
#include "CBall.h"
#include "logger.h"
#include "CPlayer.h"
#include "CPlayer_Right.h"

CBall::CBall()
{
	scale = mScale;
	speed = mSpeed;
	name = L"Ball";

	createCollider();
	getCollider()->setColliderScale(Vec2(50, 50));
}

CBall::~CBall()
{

}

void CBall::update()
{
	if(speed < maxSpeed )
		speed += 50 * DT();
	if (this->pos.x < 0)
	{
		pos.x = WS_WIDTH/2;
		pos.y = WS_HEIGHT/2;
		angle = 0;
		speed = mSpeed;
	}
	else if( this->pos.x > WS_WIDTH)
	{
		pos.x = WS_WIDTH / 2;
		pos.y = WS_HEIGHT / 2;
		angle = 0;
		speed = mSpeed;
	}

	/*
	if (Vec2::distance(pos, leftPlayer->getPos()) < 50)
	{
		this->angle = rand() % 45;
	}
	if (Vec2::distance(pos, rightPlayer->getPos()) < 50)
	{
		this->angle = (rand() % 45) + 180;
	}
	*/
	if (this->pos.y < 30)
	{
		this->pos.y += 3;
		if (cos(angle*RADIAN) > 0)
		{
			angle += 85 + (double)(rand() % 10);
		}
		else
		{
			angle += -85 + (double)(rand() % 10);
		}
	}
	if (this->pos.y > WS_HEIGHT - 30)
	{
		this->pos.y += -3;
		if (cos(angle * RADIAN) > 0)
		{
			angle += -85 + (double)(rand() % 10);
		}
		else
		{
			angle += 85 + (double)(rand() % 10);
		}
	}
	Vec2 vec(cos(angle * RADIAN), sin(angle * RADIAN));
	Vec2::normalize(vec);
	this->pos.x += speed * DT() * vec.x;
	this->pos.y += speed * DT() * vec.y;
}

void CBall::render(HDC& hDC)
{
	HBRUSH myBrush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hDC, myBrush);

	Ellipse(hDC,
		pos.x - (scale.x / 2),
		pos.y - (scale.y / 2),
		pos.x + (scale.x / 2),
		pos.y + (scale.y / 2));

	SelectObject(hDC, oldBrush);
	DeleteObject(myBrush);

	component_render(hDC);
}

void CBall::onCollisionEnter(CCollider* other)
{
	Logger::debug(L"E1");
	if (other->getOwner()->getName() == L"Player")
	{
		this->angle = rand() % 45;
	}

	if (other->getOwner()->getName() == L"Enemy")
	{
		this->angle = (rand() % 45) + 180;
	}
}