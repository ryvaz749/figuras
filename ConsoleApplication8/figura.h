#pragma once
#include<Windows.h>
#include <string>
#include<stdlib.h>
#include<iostream>
using namespace std;
//la plantilla de clase figura
class figura
{
public:
	figura();
	void setposi(int sx,int sy);
	void seta(int salt,int san);
	void setcolor(COLORREF scolor);
	virtual void dibujar(HDC hDC);
	~figura();
	int x, y, alt, an;
	COLORREF color;
};

