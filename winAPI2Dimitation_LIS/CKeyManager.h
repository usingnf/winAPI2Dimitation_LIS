#pragma once
#define VK_SIZE 255




class CKeyManager
{
	SINGLETON(CKeyManager);
private:
	bool m_arrPrevKey[VK_SIZE];
	int m_arrCurKey[VK_SIZE];
public:
	void update();
	void init();

	int getButtonState(const int& key);
};

