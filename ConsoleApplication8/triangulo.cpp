#include "pch.h"
#include "triangulo.h"
#include <math.h>

triangulo::triangulo()
{
}

void triangulo::dibujar(HDC hDC)
{
	// el triangulo siempre sera rectangulo por lo que es una combinacion del rectangulo con el cuadrado 
	//se dibuja columna por columna hasta completar la anchura
	for (float a = 0; a < an; a++) {
		//i es el inicio de la columna y con la formula se calcula el pixel por donde entraria la linea a esa columna
		int i = floor(a / an * alt);		
		//si la linea pasa justo por dos pixeles se colorean ambos, a menos que sea el inicio de la linea
		if (a != 0 && fmod((a / an * alt), 1) == 0) {
			i -= 1;
		}
		//se colorea del inicio al fin de la columna
		for (int e = 0; e < alt - i; e++) {
			SetPixel(hDC, x + a, y + e + i, color);
		}
	}
}


triangulo::~triangulo()
{
}
