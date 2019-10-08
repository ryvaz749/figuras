#include "pch.h"
#include "triangulo.h"


triangulo::triangulo()
{
}

void triangulo::dibujar(HDC hDC)
{
	for (int a = 0; a < an; a++) {
		for (int e = 0; e < alt; e++) {
			SetPixel(hDC, x + a, y + e, 000000);
}


triangulo::~triangulo()
{
}
