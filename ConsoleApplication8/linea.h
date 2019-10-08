#pragma once
#include "figura.h"
class linea: public figura
{
public:
	linea();
	void dibujar(HDC hDC);
	~linea();
};

