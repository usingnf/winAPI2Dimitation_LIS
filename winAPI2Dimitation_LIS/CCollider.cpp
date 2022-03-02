#include "pch.h"
#include "CCollider.h"

UINT CCollider::static_ID = 1;

CCollider::CCollider()
{
	colliderPos = Vec2(0,0);
	offSet = Vec2(0, 0);
	colliderScale = Vec2(0, 0);
	owner = nullptr;

	ID = static_ID++;
}

CCollider::CCollider(CGameObject* obj)
{
	this->owner = obj;
}

CCollider::CCollider(const CCollider& other)
{
	owner = nullptr;
	offSet = other.offSet;
	colliderPos = other.colliderPos;
	colliderScale = other.colliderScale;
	ID = static_ID;
}

CCollider::~CCollider()
{
}

void CCollider::finalupdate()
{
	Vec2 objPos = owner->getPos();
	colliderPos = objPos + offSet;
	//colliderPos = objPos;
	//충돌계산?
}

void CCollider::render(HDC& hDC)
{
	/*HPEN hGreenPen = CCore::getInstance()->getPen(Group_Pen::Green);
	HBRUSH hHollowBrush = CCore::getInstance()->getBrush(Group_Brush::Hollow);

	HPEN hOldPen = (HPEN)SelectObject(hDC, hGreenPen);
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, hHollowBrush);*/

	SelectGDI brush(hDC, Group_Brush::Hollow);
	SelectGDI pen(hDC, Group_Pen::Green);

	Rectangle(hDC,
		colliderPos.x - (colliderScale.x / 2),
		colliderPos.y - (colliderScale.y / 2),
		colliderPos.x + (colliderScale.x / 2),
		colliderPos.y + (colliderScale.y / 2));


	/*SelectObject(hDC, hOldPen);
	SelectObject(hDC, hHollowBrush);*/
}

Vec2 CCollider::getOffSet()
{
	return offSet;
}

Vec2 CCollider::getColliderPos()
{
	return colliderPos;
}

Vec2 CCollider::getColliderScale()
{
	return colliderScale;
}

CGameObject* CCollider::getOwner()
{
	return owner;
}

void CCollider::setOffSet(Vec2 vec)
{
	this->offSet = vec;
}

void CCollider::setColliderPos(Vec2 vec)
{
	this->colliderPos = vec;
}

void CCollider::setColliderScale(Vec2 vec)
{
	this->colliderScale = vec;
}

UINT CCollider::getID()
{
	return ID;
}

void CCollider::onCollisionEnter(CCollider* other)
{
	Logger::debug(L"Enter");
}

void CCollider::onCollisionStay(CCollider* other)
{
}

void CCollider::onCollisionExit(CCollider* other)
{
}
