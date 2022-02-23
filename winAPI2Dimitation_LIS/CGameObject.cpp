#include "pch.h"

CGameObject::CGameObject()
{
	parent = nullptr;
	pos = Vec2(0,0);
	angle = 0;
	scale = Vec2(0,0);
	texture = nullptr;
	collider = nullptr;
	animator = nullptr;

	speed = 100;
	hp = 100;
	isDead = false;
}

CGameObject::~CGameObject()
{
	if(nullptr != texture)
		delete texture;
	if (nullptr != collider)
		delete collider;
	if (nullptr != animator)
		delete animator;
}

void CGameObject::update()
{
	
}

void CGameObject::render(HDC& hDC)
{
	Rectangle(hDC, 
		pos.x - (scale.x / 2), 
		pos.y - (scale.y / 2), 
		pos.x + (scale.x / 2), 
		pos.y + (scale.y / 2));
}

void CGameObject::setPos(Vec2 vec)
{
	this->pos = vec;
}

void CGameObject::setScale(Vec2 scale)
{
	this->scale = scale;
}

Vec2 CGameObject::getPos()
{
	return pos;
}

Vec2 CGameObject::getScale()
{
	return scale;
}
