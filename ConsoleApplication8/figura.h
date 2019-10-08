#pragma once
#include<Windows.h>
class figura
{
public:
	figura();
	void setposi(int sx,int sy);
	void seta(int salt,int san);
	virtual void dibujar(HDC hDC);
	~figura();
	int x, y, alt, an;
};

