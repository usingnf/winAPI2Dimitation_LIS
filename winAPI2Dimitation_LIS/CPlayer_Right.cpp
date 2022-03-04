#include "pch.h"
#include "CPlayer_Right.h"
#include "CMissile.h"
#include "CScene.h"
#include "CCollider.h"

CPlayer_Right::CPlayer_Right()
{
	speed = pSpeed;
	scale = pScale;
	name = L"Enemy";

	createCollider();
	getCollider()->setColliderScale(Vec2(50, 50));
}

CPlayer_Right* CPlayer_Right::clone()
{
	return new CPlayer_Right(*this);
}

CPlayer_Right::~CPlayer_Right()
{
}

void CPlayer_Right::update()
{
	Vec2 vec(0, 0);
	if (KEY(VK_UP) == (UINT)Key_State::Hold)
	{
		if (this->pos.y > 0)
			vec.y += -1;
	}
	if (KEY(VK_DOWN) == (UINT)Key_State::Hold)
	{
		if (this->pos.y < WS_HEIGHT)
			vec.y += 1;
	}
	Vec2::normalize(vec);
	this->pos.x += speed * DT() * vec.x;
	this->pos.y += speed * DT() * vec.y;

	if (KEY(VK_NUMPAD0) == (UINT)Key_State::Tap)
	{
		//CreateMissile();
	}
}

void CPlayer_Right::render(HDC& hDC)
{
	Vec2 camPos = CCameraManager::getInstance()->getRenderPos(pos);
	Ellipse(hDC,
		camPos.x - (scale.x / 2),
		camPos.y - (scale.y / 2),
		camPos.x + (scale.x / 2),
		camPos.y + (scale.y / 2));

	component_render(hDC);
}

void CPlayer_Right::CreateMissile()
{
	Vec2 missilePos = pos;
	CMissile* missile = new CMissile();
	missile->setPos(missilePos);
	missile->setAngle(180);
	CSceneManager::getInstance()->getCurScene()->AddObject(missile, Group_GameObj::Missile);
}
