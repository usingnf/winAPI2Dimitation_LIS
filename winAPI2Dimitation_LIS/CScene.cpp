#include "pch.h"
#include "CScene.h"

CScene::CScene()
{
	strName = L"Noname";
}

CScene::~CScene()
{
	for (int i = 0; i < (UINT)Group_GameObj::Size; i++)
	{
		for (int j = 0; j < m_arrObj[i].size(); j++)
		{
			if (m_arrObj[i][j] != nullptr)
				delete m_arrObj[i][j];
		}
	}
}

vector<CGameObject*>* CScene::getArrObj()
{
	return m_arrObj;
}

void CScene::setName(wstring name)
{
	this->strName = name;
}

wstring CScene::getName()
{
	return strName;
}

void CScene::AddObject(CGameObject* pObj, Group_GameObj type)
{
	m_arrObj[(UINT)type].push_back(pObj);
}

const vector<CGameObject*>& CScene::getGroupObject(Group_GameObj type)
{
	return m_arrObj[(UINT)type];
}


void CScene::update()
{
	for (int i = 0; i < (UINT)Group_GameObj::Size; i++)
	{
		for (int j = 0; j < getArrObj()[i].size(); j++)
		{
			if (getArrObj()[i][j]->getIsDelete() == false)
				getArrObj()[i][j]->update();
		}
	}
}

void CScene::finalupdate()
{
	for (int i = 0; i < (UINT)Group_GameObj::Size; i++)
	{
		for (int j = 0; j < getArrObj()[i].size(); j++)
		{
			getArrObj()[i][j]->finalupdate();
		}
	}
}

void CScene::render(HDC& hDC)
{
	for (int i = 0; i < (UINT)Group_GameObj::Size; i++)
	{
		/*for (int j = 0; j < getArrObj()[i].size(); j++)
		{
			getArrObj()[i][j]->render(hDC);
		}*/

		for (vector<CGameObject*>::iterator iter = m_arrObj[i].begin(); iter != m_arrObj[i].end(); )
		{
			if ((*iter)->getIsDelete() == false)
			{
				(*iter)->render(hDC);
				iter++;
			}
			else
			{
				iter = m_arrObj[i].erase(iter);
			}
		}
	}
}

void CScene::clearObject()
{
	for (int i = 0; i < (UINT)Group_GameObj::Size; i++)
	{
		while (!m_arrObj[i].empty())
		{
			delete m_arrObj[i][m_arrObj[i].size() - 1];
			m_arrObj[i].pop_back();
		}
	}
}
