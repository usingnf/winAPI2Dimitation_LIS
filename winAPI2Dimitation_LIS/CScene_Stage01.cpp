#include "pch.h"
#include "CScene_Stage01.h"
#include "CWall.h"
#include "CMario.h"
#include "CMonster.h"
#include "CTile.h"


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
			if (getArrObj()[i][j]->getIsDelete() == false)
				getArrObj()[i][j]->update();
		}
	}

	if (KEY('R') == (UINT)Key_State::Tap)
	{
		CHANGESCENE(Group_Scene::Start);
	}
}

void CScene_Stage01::render(HDC& hDC)
{
	for (int i = 0; i < (UINT)Group_GameObj::Size; i++)
	{
		for (vector<CGameObject*>::iterator iter = getArrObj()[i].begin(); iter != getArrObj()[i].end(); )
		{
			if ((*iter)->getIsDelete() == false)
			{
				(*iter)->render(hDC);
				iter++;
			}
			else
			{
				iter = getArrObj()[i].erase(iter);
			}
		}
	}
}


void CScene_Stage01::Enter()
{
	//loadTile(L"test.tile");
	CCameraManager::getInstance()->setLookAt(Vec2(WS_WIDTH / 2, WS_HEIGHT / 2));

	CMario* mario = new CMario();
	mario->setPos(Vec2(100, WS_HEIGHT - 36 - mario->getScale().y));
	AddObject(mario, Group_GameObj::Player);
	for (int i = 0; i < 20; i++)
	{
		if (i < 8 || i > 10)
		{
			CWall* wall = new CWall();
			wall->setPos(Vec2(i * 64, WS_HEIGHT - 36));
			AddObject(wall, Group_GameObj::Wall);
		}
		
	}

	for (int i = 0; i < 5; i++)
	{
		CWall* wall = new CWall();
		wall->setPos(Vec2(i * 64, WS_HEIGHT - 200));
		AddObject(wall, Group_GameObj::Wall);
	}
	CMonster* monster = new CMonster();
	monster->setPos(Vec2(1000, WS_HEIGHT - 36 - monster->getScale().y));
	AddObject(monster, Group_GameObj::Monster);
	
}

void CScene_Stage01::Exit()
{
	/*for (int i = 0; i < (UINT)Group_GameObj::Size; i++)
	{
		for (vector<CGameObject*>::iterator iter = getArrObj()[i].begin(); iter != getArrObj()[i].end(); )
		{
			iter = getArrObj()[i].erase(iter);
		}
	}*/
	this->clearObject();
}