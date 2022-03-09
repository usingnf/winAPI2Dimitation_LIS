#include "pch.h"
#include "CUI.h"

CUI::CUI()
{
	texture = CResourceManager::getInstance()->loadTexture(L"Star", L"Mario_Item2.bmp");
	parent = nullptr;
	bCameraAffected = false;
	bMouseOn = false;
	bLbtnDown = false;
}


CUI::CUI(const CUI& other) : CGameObject(other)
{
	parent = nullptr;
	bCameraAffected = other.bCameraAffected;
	bMouseOn = false;
	bLbtnDown = false;

	vecChild.clear();
	for (UINT i = 0; i < other.vecChild.size(); i++)
	{
		AddChild(other.vecChild[i]->clone());
	}
}

CUI* CUI::clone()
{
	CUI* ui = new CUI(*this);
	ui->vecChild.clear();
	for (UINT i = 0; i < vecChild.size(); i++)
	{
		ui->vecChild.push_back(new CUI(*vecChild[i]));
		ui->vecChild[i]->parent = ui;
	}
	
	return ui;
}

CUI::~CUI()
{
	for (UINT i = 0; i < vecChild.size(); i++)
	{
		if(vecChild[i] != nullptr)
			delete vecChild[i];
	}
}

void CUI::update()
{
	update_child();
}

void CUI::finalupdate()
{
	CGameObject::finalupdate();

	finalPos = getPos();
	if (getParent() != nullptr)
	{
		Vec2 parentPos = getParent()->getPos();
		finalPos += parentPos;
	}
	mouseOnCheck();

	finalupdate_child();
}

void CUI::render(HDC& hDC)
{
	Vec2 p = getFinalPos();
	Vec2 s = getScale();

	if (bCameraAffected == true)
	{
		p = CCameraManager::getInstance()->getRenderPos(p);
	}

	

	if (texture == nullptr)
	{
		if (bLbtnDown == true)
		{
			SelectGDI pen = SelectGDI(hDC, Group_Pen::Green);
			Rectangle(hDC, p.x, p.y, p.x + s.x, p.y + s.y);
		}
		else
		{
			Rectangle(hDC, p.x, p.y, p.x + s.x, p.y + s.y);
		}
	}
	else
	{
		int width = texture->getBitmapWidth();
		int height = texture->getBitmapHeight();

		TransparentBlt(hDC,
			p.x,
			p.y,
			s.x, s.y,
			texture->getDC(),
			0, 0, width, height,
			RGB(255, 0, 255));
	}
	

	render_child(hDC);
}

void CUI::update_child()
{
	for (UINT i = 0; i < vecChild.size(); i++)
	{
		vecChild[i]->update();
	}
}

void CUI::finalupdate_child()
{
	for (UINT i = 0; i < vecChild.size(); i++)
	{
		vecChild[i]->finalupdate();
	}
}

void CUI::render_child(HDC& hDC)
{
	for (UINT i = 0; i < vecChild.size(); i++)
	{
		vecChild[i]->render(hDC);
	}
}

void CUI::mouseOn()
{

}

void CUI::mouseLbtnDown()
{

}

void CUI::mouseLbtnUp()
{

}

void CUI::mouseLbtnClicked()
{
}

bool CUI::isLbtnDown()
{
	return bLbtnDown;
}

bool CUI::isCameraAffected()
{
	return bCameraAffected;
}

bool CUI::isMouseOn()
{
	return bMouseOn;
}

void CUI::setCameraAffected(bool b)
{
	bCameraAffected = true;
	for (UINT i = 0; i < vecChild.size(); i++)
	{
		vecChild[i]->setCameraAffected(b);
	}
}

Vec2 CUI::getFinalPos()
{
	return finalPos;
}

CUI* CUI::getParent()
{
	return parent;
}

const vector<CUI*>& CUI::getChild()
{
	return vecChild;
}

void CUI::AddChild(CUI* ui)
{
	vecChild.push_back(ui);
	ui->parent = this;
	ui->bCameraAffected = this->bCameraAffected;
}

void CUI::mouseOnCheck()
{
	//ī�޶� �̵��� ��ġ�� ����� ������ ����.
	Vec2 mousePos = GETMOUSEPOS();
	Vec2 fPos = getFinalPos();
	Vec2 s = getScale();
	if (bCameraAffected == true)
	{
		mousePos = CCameraManager::getInstance()->getRealPos(mousePos);
	}

	if (fPos.x <= mousePos.x && mousePos.x <= fPos.x + s.x &&
		fPos.y <= mousePos.y && mousePos.y <= fPos.y + s.y)
	{
		bMouseOn = true;
	}
	else
	{
		bMouseOn = false;
	}
}
