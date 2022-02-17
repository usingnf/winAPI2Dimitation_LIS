#pragma once
#include "pch.h"
#include "CSingleton.h"

class CCore
{
	SINGLETON(CCore);
public:
	void update();
	void render();
};

