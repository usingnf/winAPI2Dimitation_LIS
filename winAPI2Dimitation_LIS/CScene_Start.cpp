#include "pch.h"
#include "CScene_Start.h"

CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{

}

void CScene_Start::update()
{
	for (int i = 0; i < (UINT)GROUP_GAMEOBJ::SIZE; i++)
	{
		for (int j = 0; j < getArrObj()[i].size(); j++)
		{
			getArrObj()[i][j]->update();
		}
	}
}

void CScene_Start::render(HDC& hDC)
{
	for (int i = 0; i < (UINT)GROUP_GAMEOBJ::SIZE; i++)
	{
		for (int j = 0; j < getArrObj()[i].size(); j++)
		{
			getArrObj()[i][j]->render(hDC);
		}
	}
}
