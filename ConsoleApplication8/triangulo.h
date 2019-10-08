#pragma once
#include "figura.h"
class triangulo : public figura
{
public:
	triangulo();
	void dibujar(HDC hDC);
	~triangulo();
};

