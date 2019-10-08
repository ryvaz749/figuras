#include "pch.h"
#include "figura.h"
#include<Windows.h>
figura::figura()
{
}

void figura::setposi(int sx, int sy)
{
	x = sx;
	y = sy;
}

void figura::seta(int salt, int san)
{
	alt = salt;
	an = san;
}
void figura::dibujar(HDC hdc) {
	
}

figura::~figura()
{
}
