#pragma once
#include <string>
using std::string;
using std::wstring;

enum class SceneCategory
{
	Default,
	Start,
	End
};

enum class GROUP_GAMEOBJ
{
	NONE,
	MISSILE,
	MONSTER,
	PLAYER,
	SIZE,
};

class CGameObject;

class CScene
{
private:
	std::vector<CGameObject*> m_arrObj[(UINT)GROUP_GAMEOBJ::SIZE];
	CScene* currentScene;
	wstring strName;

public:
	CScene();
	~CScene();

	virtual void update();
	virtual void render(HDC& hDC);

	void setName(wstring name);
	wstring getName();
	void AddObject(CGameObject* pObj, GROUP_GAMEOBJ type);
};

