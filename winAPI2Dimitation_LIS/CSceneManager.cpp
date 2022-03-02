#include "pch.h"
#include "CScene_Start.h"
#include "CScene_Stage01.h"

#include "CPlayer.h"
#include "CPlayer_Right.h"
#include "CBall.h"
#include "CText.h"

int leftScore = 0;
int rightScore = 0;

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
	CPlayer* leftPlayer = new CPlayer();
	CPlayer_Right* rightPlayer = new CPlayer_Right();
	CBall* ball = new CBall();

	arrScene[(UINT)Group_Scene::Start] = new CScene_Start();
	arrScene[(UINT)Group_Scene::Start]->setName(L"Start_Scene");

	CText* text = new CText();
	text->setText(L"R키를 눌러서 시작");
	text->setPos(Vec2(WS_WIDTH / 2, WS_HEIGHT / 2));
	arrScene[(UINT)Group_Scene::Start]->AddObject(text, Group_GameObj::Default);
	CText* text2 = new CText();
	text2->setPos(Vec2(WS_WIDTH / 2, (WS_HEIGHT / 2) + 30));
	text2->setText(L"키:W/S/↑/↓");
	arrScene[(UINT)Group_Scene::Start]->AddObject(text2, Group_GameObj::Default);

	arrScene[(UINT)Group_Scene::Stage_01] = new CScene_Stage01();
	arrScene[(UINT)Group_Scene::Start]->setName(L"Start_Stage_01");
	
	leftPlayer->setPos(Vec2(0, WS_HEIGHT / 2));
	rightPlayer->setPos(Vec2(WS_WIDTH, WS_HEIGHT / 2));
	ball->setPos(Vec2(WS_WIDTH / 2, WS_HEIGHT / 2));

	arrScene[(UINT)Group_Scene::Stage_01]->AddObject(leftPlayer, Group_GameObj::Monster);
	arrScene[(UINT)Group_Scene::Stage_01]->AddObject(rightPlayer, Group_GameObj::Monster);
	arrScene[(UINT)Group_Scene::Stage_01]->AddObject(ball, Group_GameObj::Missile);

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
	curScene->finalupdate();
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
