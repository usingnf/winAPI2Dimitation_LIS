#include "pch.h"
#include "CScene.h"

CScene::CScene()
{
	strName = L"Noname";
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

std::vector<CGameObject*>* CScene::getArrObj()
{
	return m_arrObj;
}

void CScene::setName(std::wstring name)
{
	this->strName = name;
}

std::wstring CScene::getName()
{
	return strName;
}

void CScene::AddObject(CGameObject* pObj, GROUP_GAMEOBJ type)
{
	m_arrObj[(UINT)type].push_back(pObj);
}
