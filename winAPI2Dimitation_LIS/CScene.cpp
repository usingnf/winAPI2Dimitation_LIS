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
