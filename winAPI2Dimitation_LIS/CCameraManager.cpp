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
	Vec2 center = Vec2(WS_WIDTH /2, WS_HEIGHT / 2);

	diffPos = pos - center;
}

Vec2 CCameraManager::getRenderPos(Vec2 vec)
{
	return vec - diffPos;;
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
	calDiff();
}
