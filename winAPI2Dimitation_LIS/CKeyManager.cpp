#include "pch.h"
#include "CKeyManager.h"


CKeyManager::CKeyManager()
{
	for (int i = 0; i < VK_SIZE; i++)
	{
		m_arrPrevKey[i] = false;
		m_arrCurKey[i] = (UINT)KEY_STATE::NONE;
	}
}

CKeyManager::~CKeyManager()
{

}

void CKeyManager::update()
{
	//창 비활성화시 키 입력 해제.
	HWND curWnd = GetFocus();
	if (hWnd != curWnd)
	{
		for (int i = 0; i < VK_SIZE; i++)
		{
			if (m_arrPrevKey[i] == true)
			{
				m_arrCurKey[i] = (UINT)KEY_STATE::OFF;
			}
			m_arrPrevKey[i] = false;
			m_arrCurKey[i] = (UINT)KEY_STATE::NONE;
		}
		
		return;
	}

	//모든 키의 입력 상태 확인
	for (int i = 0; i < VK_SIZE; i++)
	{
		if (GetAsyncKeyState(i) & 0x8000)
		{
			if (m_arrPrevKey[i] == true)
			{
				m_arrCurKey[i] = (UINT)KEY_STATE::HOLD;
			}
			else
			{
				m_arrCurKey[i] = (UINT)KEY_STATE::TAP;
			}
			m_arrPrevKey[i] = true;
		}
		else
		{
			if (m_arrPrevKey[i] == true)
			{
				m_arrCurKey[i] = (UINT)KEY_STATE::OFF;
			}
			else
			{
				m_arrCurKey[i] = (UINT)KEY_STATE::NONE;
			}
			m_arrPrevKey[i] = false;
		}
	}
	
}

void CKeyManager::init()
{
	
}

int CKeyManager::getButtonState(const int& key)
{
	return m_arrCurKey[key];
}