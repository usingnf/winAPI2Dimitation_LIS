#include "pch.h"
#include "CScene.h"


CUIManager::CUIManager()
{
	focusedUI = nullptr;
}

CUIManager::~CUIManager()
{

}

void CUIManager::update()
{
	/*
	CScene* curScene = CSceneManager::getInstance()->getCurScene();
	const vector<CGameObject*>& vecUI = curScene->getGroupObject(Group_GameObj::UI);

	for (int i = 0; i < vecUI.size(); i++)
	{
		CUI* ui = (CUI*)vecUI[i];
		ui = getTargetUI(ui);

		if (ui != nullptr)
		{
			ui->mouseOn();

			if (KEY(VK_LBUTTON) == (UINT)Key_State::Tap)
			{
				ui->mouseLbtnDown();
				ui->bLbtnDown = true;
			}
			else if (KEY(VK_LBUTTON) == (UINT)Key_State::Off)
			{
				ui->mouseLbtnUp();
				if (ui->bLbtnDown == true)
				{
					ui->mouseLbtnClicked();
				}
				ui->bLbtnDown = false;
			}
		}
	}*/
	
	CUI* focusedUI = getFocusedUI();

	if (focusedUI == nullptr)
	{
		return;
	}

	CUI* pTargetUI = getTargetUI(focusedUI);

	if (nullptr != pTargetUI)
	{
		pTargetUI->mouseOn();

		if (KEY(VK_LBUTTON) == (UINT)Key_State::Tap)
		{
			pTargetUI->mouseLbtnDown();
			pTargetUI->bLbtnDown = true;
		}
		else if (KEY(VK_LBUTTON) == (UINT)Key_State::Off)
		{
			pTargetUI->mouseLbtnUp();

			if (pTargetUI->bLbtnDown)
			{
				pTargetUI->mouseLbtnClicked();
			}
			pTargetUI->bLbtnDown = false;
		}
	}
	
}


void CUIManager::setFocusedUI(CUI* UI)
{
	// �̹� ��Ŀ�̵� UI �̰ų� ������ ��Ŀ�̵� UI�� ������ ���
	if (focusedUI == UI || nullptr == focusedUI)
	{
		focusedUI = UI;
		return;
	}

	focusedUI = UI;

	CScene* pCurScene = CSceneManager::getInstance()->getCurScene();
	vector<CGameObject*>& vecUI = pCurScene->getArrObj()[(UINT)Group_GameObj::UI];

	vector<CGameObject*>::iterator iter = vecUI.begin();
	for (; iter != vecUI.end(); iter++)
	{
		if (focusedUI == *iter)
		{
			break;
		}
	}

	vecUI.erase(iter);
	vecUI.push_back(focusedUI);
}

CUI* CUIManager::getTargetUI(CUI* parentUI)
{
	static list<CUI*> queue;
	static vector<CUI*> vecNoneTarget;
	CUI* targetUI = nullptr;
	queue.push_back(parentUI);

	while (!queue.empty())
	{
		CUI* ui = queue.front();
		queue.pop_front();
		if (ui->isMouseOn())
		{
			if (targetUI != nullptr)
			{
				vecNoneTarget.push_back(targetUI);
			}
			targetUI = ui;
		}
		else
		{
			vecNoneTarget.push_back(ui);
		}
		const vector<CUI*> vecChild = ui->getChild();
		for (int i = 0; i < vecChild.size(); i++)
		{
			queue.push_back(vecChild[i]);
		}
	}

	if (KEY(VK_LBUTTON) == (UINT)Key_State::Off)
	{
		for (int i = 0; i < vecNoneTarget.size(); i++)
		{
			vecNoneTarget[i]->bLbtnDown = false;
		}
	}
	vecNoneTarget.clear();

	return targetUI;
}

CUI* CUIManager::getFocusedUI()
{
	//�ڵ� ���縸 �س���.
	CScene* pCurScene = CSceneManager::getInstance()->getCurScene();
	vector<CGameObject*>& vecUI = pCurScene->getArrObj()[(UINT)Group_GameObj::UI];

	CUI* pFocusedUI = focusedUI;

	if (KEY(VK_LBUTTON) != (UINT)Key_State::Tap)
	{
		return pFocusedUI;	// Ŭ���� �������� ��Ŀ�� ��ȯ ����
	}

	vector<CGameObject*>::iterator targetIter = vecUI.end();
	vector<CGameObject*>::iterator iter = vecUI.begin();
	for (; iter != vecUI.end(); iter++)
	{
		if (((CUI*)*iter)->isMouseOn())
		{
			targetIter = iter;
		}
	}
	if (vecUI.end() == targetIter)
	{
		return nullptr;		// targetIter�� end iterator��� ���� ���콺�� �÷��� ��Ŀ���� UI�� ���ٴ� �ǹ�
	}

	pFocusedUI = (CUI*)*targetIter;

	vecUI.erase(targetIter);
	vecUI.push_back(pFocusedUI);
	focusedUI = pFocusedUI;

	return pFocusedUI;
}
