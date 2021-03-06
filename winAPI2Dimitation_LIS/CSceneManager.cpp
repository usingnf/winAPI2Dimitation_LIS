#include "pch.h"
#include "CScene_Start.h"
#include "CScene_Stage01.h"
#include "CScene_Tile.h"

#include "CPlayer.h"
#include "CPlayer_Right.h"
#include "CBall.h"
#include "CText.h"
#include "CRemilia.h"

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
	arrScene[(UINT)Group_Scene::Stage_Tile] = new CScene_Tile();
	arrScene[(UINT)Group_Scene::Stage_Tile]->setName(L"Stage_Tile");

	arrScene[(UINT)Group_Scene::Start] = new CScene_Start();
	arrScene[(UINT)Group_Scene::Start]->setName(L"Start_Scene");

	arrScene[(UINT)Group_Scene::Stage_01] = new CScene_Stage01();
	arrScene[(UINT)Group_Scene::Stage_01]->setName(L"Start_Stage_01");
	
	CText* text = new CText();
	text->setText(L"R키를 눌러서 시작");
	text->setPos(Vec2(WS_WIDTH / 2, WS_HEIGHT / 2));
	arrScene[(UINT)Group_Scene::Start]->AddObject(text, Group_GameObj::Default);
	CText* text2 = new CText();
	text2->setPos(Vec2(WS_WIDTH / 2, (WS_HEIGHT / 2) + 30));
	text2->setText(L"키:WASD/SPACE/SHIFT");
	arrScene[(UINT)Group_Scene::Start]->AddObject(text2, Group_GameObj::Default);

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
	curScene->update();
	curScene->finalupdate();
}

void CSceneManager::render(HDC& hDC)
{
	curScene->render(hDC);
}

CScene* CSceneManager::getCurScene()
{
	return curScene;
}
