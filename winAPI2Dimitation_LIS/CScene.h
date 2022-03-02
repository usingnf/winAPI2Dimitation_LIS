#pragma once



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

	const vector<CGameObject*>& getGroupObject(Group_GameObj type);

	virtual void update();
	virtual void finalupdate();
	virtual void render(HDC& hDC);

	virtual void Enter() = 0;
	virtual void Exit() = 0;

protected:
	void clearObject();

};

