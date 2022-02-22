#pragma once

enum class Group_GameObj
{
	Default,
	Missle,
	Monster,
	Player,

	Size,
};

class CGameObject;

class CScene
{
private:
	vector<CGameObject*> m_arrObj[(UINT)Group_GameObj::Size];
	wstring strName;

public:
	CScene();
	virtual ~CScene();

	
	vector<CGameObject*>* getArrObj();
	void setName(std::wstring name);
	wstring getName();
	void AddObject(CGameObject* pObj, Group_GameObj type);

	virtual void update() = 0;
	virtual void render(HDC& hDC) = 0;

	virtual void Enter() = 0;
	virtual void Exit() = 0;

	void ClearObject();

};

