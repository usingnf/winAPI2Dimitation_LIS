#pragma once
#include "CSingleton.h"

using std::vector;

enum class Group_Scene
{
	Default,
	Start,
	Stage_01,
	Stage_02,
	End,
	Size,
};

class CScene;

class CSceneManager
{
	SINGLETON(CSceneManager);
private:
	CScene* arrScene[(UINT)Group_Scene::Size];
	CScene* curScene;
	
public:
	void init();
	void changeScene(Group_Scene type);
	void update();
	void render(HDC& hDC);

};

