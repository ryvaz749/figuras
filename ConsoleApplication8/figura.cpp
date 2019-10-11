#include "pch.h"
#include "figura.h"
#include<Windows.h>
#include <string>
figura::figura()
{
}
//se agrega su posision en x y y
void figura::setposi(int sx, int sy)
{
	x = sx;
	y = sy;
}
// se agrega su altura y anchura
void figura::seta(int salt, int san)
{
	alt = salt;
	an = san;
}
//se agreaga el color como una variable colorref
void figura::setcolor(COLORREF scolor)
{
	color = scolor;
}
//la funcion virtual de dibujar 
void figura::dibujar(HDC hdc) {
	
}

figura::~figura()
{
}
