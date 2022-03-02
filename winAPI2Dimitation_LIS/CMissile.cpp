#include "pch.h"
#include "CMissile.h"
#include "CCollider.h"

CMissile::CMissile()
{
	speed = mSpeed;
	scale = mScale;

	createCollider();
	getCollider()->setColliderScale(Vec2(30, 30));
}

CMissile::~CMissile()
{

}

void CMissile::update()
{
	if (pos.x < 0 || pos.x > WS_WIDTH || pos.y < 0 || pos.y > WS_HEIGHT)
	{
		return;
		//object 파괴 작업 필요.
	}
	pos.x += speed * DT() * cos(angle * RADIAN);
	pos.y += speed * DT() * -sin(angle * RADIAN);
}

void CMissile::render(HDC& hDC)
{
	Ellipse(hDC,
		pos.x - (scale.x / 2),
		pos.y - (scale.y / 2),
		pos.x + (scale.x / 2),
		pos.y + (scale.y / 2));

	component_render(hDC);
}