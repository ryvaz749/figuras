// ConsoleApplication8.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "Window.h"
#include "AppWindow.h"
#include "figura.h"
#include "linea.h"
#include "rectangulo.h"
#include "triangulo.h"
int main()
{
	//para crear la ventana es con Window, para que se muestre es con la funcion run y para que dibujar algo en ella es con la funcion dibujar. se pueden crear lineas, rectangulos y triangulos, con setposi se pone la posision en x,y y con seta se pone la altura y anchura, y con set color se pone el color en vase 8
	Window ventana;
	triangulo tri;
	tri.setposi(100, 100);
	tri.seta(300, 500);
	tri.setcolor(007700);
	//ventana.dibujar(&rec);
	ventana.dibujar(new triangulo(tri));
	ventana.run();
}



