#include "pch.h"
#include "CPlayer.h"
#include "CMissile.h"
#include "CScene.h"

CPlayer::CPlayer()
{
	speed = pSpeed;
	scale = pScale;
}

CPlayer::~CPlayer()
{
}

void CPlayer::update()
{
	Vec2 vec(0,0);
	if (KEY('W') == (UINT)Key_State::Hold)
	{
		if (this->pos.y > 0)
			vec.y += -1;
	}
	if (KEY('S') == (UINT)Key_State::Hold)
	{
		if (this->pos.y < WS_HEIGHT)
			vec.y += 1;
	}
	Vec2::normalize(vec);
	this->pos.x += speed * DT() * vec.x;
	this->pos.y += speed * DT() * vec.y;

	if (KEY(VK_SPACE) == (UINT)Key_State::Tap)
	{
		//CreateMissile();
	}
}

void CPlayer::render(HDC& hDC)
{
	Ellipse(hDC,
		pos.x - (scale.x / 2),
		pos.y - (scale.y / 2),
		pos.x + (scale.x / 2),
		pos.y + (scale.y / 2));
}

void CPlayer::CreateMissile()
{
	Vec2 missilePos = pos;
	CMissile* missile = new CMissile();
	missile->setPos(missilePos);
	missile->setAngle(Vec2::getAngle(Vec2(1,1), Vec2(2, 2)));
	CSceneManager::getInstance()->getCurScene()->AddObject(missile, Group_GameObj::Missile);

	CMissile* missile2 = new CMissile();
	missile2->setPos(missilePos);
	missile2->setAngle(Vec2::getAngle(Vec2(1, 1)));
	CSceneManager::getInstance()->getCurScene()->AddObject(missile2, Group_GameObj::Missile);
}
