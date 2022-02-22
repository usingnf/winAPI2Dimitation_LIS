#include "pch.h"
#include "CSceneManager.h"
#include "CScene_Start.h"
#include "CPlayer.h"

CSceneManager::CSceneManager()
{
	for (int i = 0; i < (UINT)Group_Scene::Size; i++)
	{
		arrScene[i] = nullptr;
	}
	curScene = nullptr;
}

CSceneManager::~CSceneManager()
{
	for (int i = 0; i < (UINT)Group_Scene::Size; i++)
	{
		if(arrScene[i] != nullptr)
			delete arrScene[i];
	}
}

void CSceneManager::init()
{
	arrScene[(UINT)Group_Scene::Start] = new CScene_Start();
	arrScene[(UINT)Group_Scene::Start]->setName(L"Start_Scene");

	CPlayer* leftP = new CPlayer();
	leftP->setPos(Vec2(0, WS_HEIGHT / 2));
	leftP->setScale(Vec2(50, 50));
	arrScene[(UINT)Group_Scene::Start]->AddObject(leftP, GROUP_GAMEOBJ::Default);
	CPlayer* rightP = new CPlayer();
	rightP->setPos(Vec2(WS_WIDTH, WS_HEIGHT / 2));
	rightP->setScale(Vec2(50, 50));
	arrScene[(UINT)Group_Scene::Start]->AddObject(rightP, GROUP_GAMEOBJ::Default);
	CGameObject* ballP = new CGameObject();
	ballP->setPos(Vec2(WS_WIDTH / 2, WS_HEIGHT / 2));
	ballP->setScale(Vec2(50, 50));
	arrScene[(UINT)Group_Scene::Start]->AddObject(ballP, GROUP_GAMEOBJ::Default);

	curScene = arrScene[(UINT)Group_Scene::Start];
}

void CSceneManager::changeScene(Group_Scene type)
{
	curScene = arrScene[(UINT)type];
}

void CSceneManager::update()
{
	/*for (int i = 0; i < (UINT)GROUP_GAMEOBJ::SIZE; i++)
	{
		for (int j = 0; j < curScene->getArrObj()[i].size(); j++)
		{
			curScene->getArrObj()[i][j]->update();
		}
	}*/
	curScene->update();
}

void CSceneManager::render(HDC& hDC)
{
	/*for (int i = 0; i < (UINT)GROUP_GAMEOBJ::SIZE; i++)
	{
		for (int j = 0; j < curScene->getArrObj()[i].size(); j++)
		{
			curScene->getArrObj()[i][j]->render(hDC);
		}
	}*/
	curScene->render(hDC);
}
