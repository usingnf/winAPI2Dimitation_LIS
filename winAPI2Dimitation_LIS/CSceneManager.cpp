#include "pch.h"
#include "CSceneManager.h"
#include "CScene_Start.h"
#include "CScene_Stage01.h"
#include "CPlayer.h"
#include "CMonster.h"

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
	arrScene[(UINT)Group_Scene::Start]->AddObject(leftP, Group_GameObj::Default);
	CPlayer* rightP = new CPlayer();
	rightP->setPos(Vec2(WS_WIDTH, WS_HEIGHT / 2));
	arrScene[(UINT)Group_Scene::Start]->AddObject(rightP, Group_GameObj::Default);
	CGameObject* ballP = new CGameObject();
	ballP->setPos(Vec2(WS_WIDTH / 2, WS_HEIGHT / 2));
	ballP->setScale(Vec2(50, 50));
	arrScene[(UINT)Group_Scene::Start]->AddObject(ballP, Group_GameObj::Default);

	arrScene[(UINT)Group_Scene::Stage_01] = new CScene_Stage01();
	arrScene[(UINT)Group_Scene::Start]->setName(L"Start_Stage_01");

	CPlayer* leftP2 = new CPlayer();
	leftP2->setPos(Vec2(0, WS_HEIGHT / 2));
	leftP2->setScale(Vec2(50, 50));
	arrScene[(UINT)Group_Scene::Stage_01]->AddObject(leftP2, Group_GameObj::Default);
	CPlayer* rightP2 = new CPlayer();
	rightP2->setPos(Vec2(WS_WIDTH, WS_HEIGHT / 2));
	rightP2->setScale(Vec2(50, 50));
	arrScene[(UINT)Group_Scene::Stage_01]->AddObject(rightP2, Group_GameObj::Default);
	CGameObject* ballP2 = new CGameObject();
	ballP2->setPos(Vec2(WS_WIDTH / 2, WS_HEIGHT / 2));
	ballP2->setScale(Vec2(50, 50));
	arrScene[(UINT)Group_Scene::Stage_01]->AddObject(ballP2, Group_GameObj::Default);

	CMonster* monster = new CMonster();
	monster->setPos(Vec2(WS_WIDTH / 2, WS_HEIGHT / 2));
	arrScene[(UINT)Group_Scene::Start]->AddObject(monster, Group_GameObj::Default);


	curScene = arrScene[(UINT)Group_Scene::Start];
	curScene->Enter();
}

void CSceneManager::changeScene(Group_Scene type)
{
	curScene->Exit();
	curScene = arrScene[(UINT)type];
	curScene->Enter();
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

CScene* CSceneManager::getCurScene()
{
	return curScene;
}
