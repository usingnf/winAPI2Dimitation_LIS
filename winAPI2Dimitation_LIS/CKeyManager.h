#pragma once
#define VK_SIZE 255

enum class KEY_STATE
{
	NONE,
	TAP,
	HOLD,
	OFF,
};


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

