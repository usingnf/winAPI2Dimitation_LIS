#pragma once
#include "CUI.h"
class CUIManager
{
	SINGLETON(CUIManager);

private:
	CUI* focusedUI;
public:
	void update();

private:
	CUI* getTargetUI(CUI* parentUI);
	CUI* getFocusedUI();
	void setFocusedUI(CUI* ui);
};

