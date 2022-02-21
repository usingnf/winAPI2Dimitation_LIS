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
		pos.x - (scale / 2), 
		pos.y - (scale / 2), 
		pos.x + (scale / 2), 
		pos.y + (scale / 2));
}

void CGameObject::setPos(Vec2 vec)
{
	this->pos = vec;
}

void CGameObject::setScale(double scale)
{
	this->scale = scale;
}

Vec2 CGameObject::getPos()
{
	return pos;
}

double CGameObject::getScale()
{
	return scale;
}
