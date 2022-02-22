#pragma once

enum class GROUP_GAMEOBJ
{
	Default,
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
	std::wstring strName;

public:
	CScene();
	virtual ~CScene();

	
	std::vector<CGameObject*>* getArrObj();
	void setName(std::wstring name);
	std::wstring getName();
	void AddObject(CGameObject* pObj, GROUP_GAMEOBJ type);

	virtual void update() = 0;
	virtual void render(HDC& hDC) = 0;

};

