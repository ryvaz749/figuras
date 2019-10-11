#pragma once
#include <Windows.h>
#include "figura.h"
#include <stdlib.h>
#include <list>
#include "facade.h"
#include "rectangulo.h"
using namespace std;
class Window
{
public:
	Window();
	//Initialize the window
	bool init();
	bool broadcast();
	void crearlinea(int x, int y, int alt, int an);
	void crearrectangulo(int x, int y, int alt, int an);
	void creartriangulo(int x, int y, int alt, int an);
//	template<typename u>
//	void dibujar(u* fig);
	void dibujar(figura * a);
	void run();
	//LRESULT CALLBACK esta(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

	//Release the window
	bool release();
	bool isRun();
	int tamaño;
	//EVENTS
	virtual void onCreate();
	virtual void onUpdate();
	virtual void onDestroy();
	
	~Window();
protected:
	HWND m_hwnd;
	bool m_is_run;
private:
	
};

