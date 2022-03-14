#include "pch.h"
#include "CPlayer.h"
#include "CMissile.h"
#include "CMissile2.h"
#include "CScene.h"
#include "CCollider.h"


CPlayer::CPlayer()
{
	speed = pSpeed;
	scale = pScale;
	name = L"Player";

	createCollider();
	getCollider()->setColliderScale(Vec2(50, 50));
	//collider->setColliderScale(Vec2(50, 50));

	//texture = CResourceManager::getInstance()->loadTexture(L"Player", L"Animation_Player.bmp");

	/*
	createAnimator();
	getAnimator()->createAnimation(L"Stand", texture, Vec2(0, 0), Vec2(70, 70), Vec2(70, 0), 0.2, 3);
	getAnimator()->play(L"Stand");

	CAnimation* ani;
	ani = getAnimator()->findAnimation(L"Stand");
	ani->GetFrame(1).fptOffset = Vec2(10, 10);
	ani->GetFrame(1).duration = 1;
	ani->setLoop(true);
	*/
}

CPlayer* CPlayer::clone()
{
	return new CPlayer(*this);
}

CPlayer::~CPlayer()
{
}

void CPlayer::update()
{
	Vec2 vec(0,0);
	if (KEY('W') == (UINT)Key_State::Hold)
	{
		vec.y += -1;
	}
	if (KEY('S') == (UINT)Key_State::Hold)
	{
		vec.y += 1;
			
	}
	if (KEY('D') == (UINT)Key_State::Hold)
	{
		vec.x += 1;
	}
	if (KEY('A') == (UINT)Key_State::Hold)
	{
		vec.x += -1;
	}
	Vec2::normalize(vec);
	this->pos.x += speed * DT() * vec.x;
	this->pos.y += speed * DT() * vec.y;

	if (KEY(VK_SPACE) == (UINT)Key_State::Tap)
	{
		CreateMissile();
		CreateMissile2();
	}

	CAnimator* ani = getAnimator();
	if (ani != nullptr)
		ani->update();
}

void CPlayer::render(HDC& hDC)
{

	/*Ellipse(hDC,
		pos.x - (scale.x / 2),
		pos.y - (scale.y / 2),
		pos.x + (scale.x / 2),
		pos.y + (scale.y / 2));*/

	//int width = texture->getBitmapWidth();
	//int height = texture->getBitmapHeight();

	/*BitBlt(hDC, pos.x - (width / 2), pos.y - (height / 2), pos.x + (width / 2), pos.y + (height / 2)
		,texture->getDC(), 0, 0, SRCCOPY );*/
	/*
	TransparentBlt(hDC,
		(int)(pos.x - (double)(width / 2)),
		(int)(pos.y - (double)(height / 2)),
		width, height,
		texture->getDC(),
		0, 0, width, height,
		RGB(255, 0, 255));
	*/

	component_render(hDC);
}

void CPlayer::CreateMissile()
{
	Vec2 missilePos = pos;
	CMissile* missile = new CMissile();
	missile->setPos(missilePos);
	missile->setAngle(Vec2::getAngle(Vec2(0,0), Vec2(1, 0)));
	
	//CEventManager::getInstance()->createGameObject(missile);
	CREATEOBJECT(missile, Group_GameObj::Missile);
}

void CPlayer::CreateMissile2()
{
	Vec2 missilePos = pos;
	CMissile2* missile = new CMissile2();
	missile->setPos(missilePos);
	missile->addForce(Vec2(200, 200));
	CSceneManager::getInstance()->getCurScene()->AddObject(missile, Group_GameObj::Missile);

}
