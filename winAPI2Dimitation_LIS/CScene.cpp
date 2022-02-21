#include "pch.h"
#include "CScene.h"

CScene::CScene()
{
}

CScene::~CScene()
{
	for (int i = 0; i < (UINT)GROUP_GAMEOBJ::SIZE; i++)
	{
		for (int j = 0; j < m_arrObj[i].size(); j++)
		{
			if (m_arrObj[i][j] != nullptr)
				delete m_arrObj[i][j];
		}
	}
}

void CScene::update()
{
	for (int i = 0; i < (UINT)GROUP_GAMEOBJ::SIZE; i++)
	{
		for (int j = 0; j < m_arrObj[i].size(); j++)
		{
			m_arrObj[i][j]->update();
		}
	}
}

void CScene::render(HDC& hDC)
{
	for (int i = 0; i < (UINT)GROUP_GAMEOBJ::SIZE; i++)
	{
		for (int j = 0; j < m_arrObj[i].size(); j++)
		{
			m_arrObj[i][j]->render(hDC);
		}
	}
}

void CScene::setName(wstring name)
{
	this->strName = name;
}

wstring CScene::getName()
{
	return strName;
}

void CScene::AddObject(CGameObject* pObj, GROUP_GAMEOBJ type)
{
	m_arrObj[(UINT)type].push_back(pObj);
}
