#pragma once
#include "figura.h"
class rectangulo: public figura
{
public:
	rectangulo();
	void dibujar(HDC hDC);
	~rectangulo();
};

