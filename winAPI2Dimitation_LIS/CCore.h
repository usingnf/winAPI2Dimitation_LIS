#pragma once
#include "CSingleton.h"
#include "CTimeManager.h"

enum class Group_Pen
{
	Red,
	Green,
	Blue,
	White,
	Black,

	Size,
};

enum class Group_Brush
{
	Hollow,
	Red,
	Green,
	Blue,
	White,
	Black,
	

	Size,
};


class CCore
{
	SINGLETON(CCore);
private:
	HDC m_hDC;
	HDC m_hMemDC;
	HBITMAP m_hBMP;

	HPEN m_arrPen[(UINT)Group_Pen::Size];
	HBRUSH m_arrBrush[(UINT)Group_Brush::Size];

public:
	void update();
	//void finalupdate();
	void render();
	void init();
	HDC getMainDC();

	void createBrushPen();
	HPEN getPen(Group_Pen pen);
	HBRUSH getBrush(Group_Brush brush);
};

