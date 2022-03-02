#include "pch.h"
#include "CCollider.h"

CGameObject::CGameObject()
{
	parent = nullptr;
	name = L"Noname";
	pos = Vec2(0,0);
	angle = 0;
	scale = Vec2(0,0);
	velocity = Vec2(0, 0);
	gravity = 0;
	drag = 0;

	texture = nullptr;
	collider = nullptr;
	animator = nullptr;

	speed = 100;
	hp = 100;
	isDelete = false;
}

CGameObject::~CGameObject()
{
	if (nullptr != collider)
		delete collider;
	if (nullptr != animator)
		delete animator;
}

void CGameObject::update()
{
	
}

void CGameObject::finalupdate()
{
	if (collider != nullptr)
	{
		collider->finalupdate();
	}
}

void CGameObject::render(HDC& hDC)
{
	Rectangle(hDC, 
		pos.x - (scale.x / 2), 
		pos.y - (scale.y / 2), 
		pos.x + (scale.x / 2), 
		pos.y + (scale.y / 2));

	component_render(hDC);
}

void CGameObject::component_render(HDC& hDC)
{
	if(collider != nullptr)
		collider->render(hDC);
}

void CGameObject::setName(wstring _name)
{
	this->name = _name;
}

wstring CGameObject::getName()
{
	return name;
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

double CGameObject::getAngle()
{
	return this->angle;
}

bool CGameObject::getIsDelete()
{
	return isDelete;
}

void CGameObject::setIsDelete(bool dead)
{
	this->isDelete = dead;
}

void CGameObject::createCollider()
{
	collider = new CCollider();
	collider->owner = this;
}

CCollider* CGameObject::getCollider()
{
	return collider;
}

void CGameObject::addForce(Vec2 vec)
{
	this->velocity.x += vec.x;
	this->velocity.y += vec.y;
}


void CGameObject::setAngle(double ang)
{
	this->angle = ang;
}

void CGameObject::setAngle(Vec2 vec)
{
	this->angle = Vec2::getAngle(vec);
}

