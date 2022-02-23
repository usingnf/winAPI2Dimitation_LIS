#include "pch.h"
#include "CScene_Stage01.h"


CScene_Stage01::CScene_Stage01()
{
}

CScene_Stage01::~CScene_Stage01()
{
}

void CScene_Stage01::update()
{
	for (int i = 0; i < (UINT)Group_GameObj::Size; i++)
	{
		for (int j = 0; j < getArrObj()[i].size(); j++)
		{
			getArrObj()[i][j]->update();
		}
	}

	if (KEY('R') == (UINT)Key_State::Tap)
	{
		CSceneManager::getInstance()->changeScene(Group_Scene::Start);
	}
}

void CScene_Stage01::render(HDC& hDC)
{
	for (int i = 0; i < (UINT)Group_GameObj::Size; i++)
	{
		for (int j = 0; j < getArrObj()[i].size(); j++)
		{
			getArrObj()[i][j]->render(hDC);
		}
	}
}


void CScene_Stage01::Enter()
{

}

void CScene_Stage01::Exit()
{

}