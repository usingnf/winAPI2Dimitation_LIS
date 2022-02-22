#include "pch.h"
#include "CGameObject.h"

CGameObject::CGameObject()
{

}

CGameObject::~CGameObject()
{
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
