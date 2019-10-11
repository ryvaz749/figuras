#include "pch.h"
#include "rectangulo.h"
#include <iostream>
using namespace std;
rectangulo::rectangulo()
{
}

void rectangulo::dibujar(HDC hDC)
{
	//se dibuja pixel por pixel del color predeterminado empezando en la coordenada de la posision, de hay se va pintando columna por columna del tamaño de la altura hasta completar toda la anchura
	for (int a = 0; a < an; a++) {
		for (int e = 0; e < alt; e++) {
			SetPixel(hDC, x + a, y + e, color);
		}
	}
}


rectangulo::~rectangulo()
{
}
