#include "pch.h"
#include "rectangulo.h"


rectangulo::rectangulo()
{
}

void rectangulo::dibujar(HDC hDC)
{
	for (int a = 0; a < an; a++) {
		for (int e = 0; e < alt; e++) {
			SetPixel(hDC, x + a, y + e, 000000);
		}
	}
}


rectangulo::~rectangulo()
{
}
