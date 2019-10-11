#include "pch.h"
#include "linea.h"
#include <math.h>
#include <iostream>
using namespace std;
linea::linea()
{
	
}

void linea::dibujar(HDC hDC)
{
	//se dibuja columna por columna hasta completar la anchura
	for (float a = 0; a < an; a++) {
		//i es el inicio de la columna y con la formula se calcula el pixel por donde entraria la linea a esa columna
		int i = floor(a / an * alt);
		//f es el final de la columna y la formula calcula el pixel en el que saldria la linea
		int f = ceil((a + 1) / an * alt);
		//si la linea pasa justo por dos pixeles se colorean ambos, a menos que sea el fin o inicio de la linea
		if (a != 0 && fmod((a / an * alt),1) == 0) {
			i -= 1;
		}
		if (a != an-1 && fmod(((a+1) / an * alt) , 1) == 0) {
			f += 1;
		}
		//se colorea del inicio al fin de la columna
		for (int e = 0; e < f-i; e++) {
			SetPixel(hDC, x + a, y + e+i, color);
			
		}
	}
}


linea::~linea()
{
}
