#include "pch.h"
#include "CCameraManager.h"

CCameraManager::CCameraManager()
{
	pos = Vec2(WS_WIDTH / 2, WS_HEIGHT / 2);
	targetObj = nullptr;
}

CCameraManager::~CCameraManager()
{

}

void CCameraManager::setLookAt(Vec2 vec)
{
	pos = vec;
}

void CCameraManager::setTargetObj(CGameObject* obj)
{
	targetObj = obj;
}

void CCameraManager::calDiff()
{
	Vec2 center = Vec2(WS_WIDTH / 2, WS_HEIGHT / 2);

	diffPos = pos - center;
}

Vec2 CCameraManager::getPos()
{
	return pos;
}

Vec2 CCameraManager::getRenderPos(Vec2 vec)
{
	return vec - diffPos;
}

Vec2 CCameraManager::getRealPos(Vec2 vec)
{
	return vec + diffPos;
}

void CCameraManager::update()
{
	if (targetObj != nullptr)
	{
		if (targetObj->getIsDelete() == true)
		{
			targetObj = nullptr;
		}
		else
		{
			pos = targetObj->getPos();
		}
	}
	else
	{
		if (Vec2::distance(pos, destPos) < 1)
		{
			pos = destPos;
		}
		else
		{
			pos = pos + (destPos - pos).normalized() * speed * DT();
			speed += maxSpeed * -DT();
		}
	}
	calDiff();
}

void CCameraManager::timeMove(Vec2 dest, double t)
{
	destPos = dest;
	maxSpeed = (destPos - pos).length() / t;
	speed = maxSpeed * 2;
}
