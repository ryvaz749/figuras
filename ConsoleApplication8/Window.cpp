#include "pch.h"
#include "Window.h"
#include "linea.h"
#include "rectangulo.h"
#include <typeinfo>
#include "facade.h"
#include <iostream>
#include "figura.h"
#include "triangulo.h"
using namespace std;
//Window* window=nullptr;
//la lista en donde se guardaran todas las figuras
list<figura*> figuras;
Window::Window()
{
	
}
void GamePaint(HDC hDC)
{
	//se recorre toda la lista de las figuras
	for (list<figura*>::iterator it = figuras.begin(); it != figuras.end(); it++) {
		//a cada figura se le ejecuta la funcion dibujar que sera diferente dependiendo de que tipo de figura es
		(*it)->dibujar(hDC);
	}
}
/*template <typename u>
void Window::dibujar(u* fig){
	u* figu = new u(*fig);
	figuras.push_back(figu);
}*/
//la funcion dibujar agrega la figura a la lista
void Window::dibujar(figura * a) {
	figuras.push_back(a);
}
void Window::run()
{
	if (init()) {
		while (isRun()) {
			broadcast();
		}
	}
}
LRESULT CALLBACK esta(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	//GetWindowLong(hwnd,)
	switch (msg)
	{
	case WM_CREATE:
	{
		// Event fired when the window is created
		// collected here..
		Window* window = (Window*)((LPCREATESTRUCT)lparam)->lpCreateParams;

		// .. and then stored for later lookup
		SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)window);
		window->onCreate();
		break;
	}
	case WM_PAINT:
		HDC hDC;
		PAINTSTRUCT ps;
		hDC = BeginPaint(hwnd, &ps);

		GamePaint(hDC);
		// Paint the game

		EndPaint(hwnd, &ps);
	case WM_DESTROY:
	{
		// Event fired when the window is destroyed
		Window* window = (Window*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
		window->onDestroy();
		::PostQuitMessage(0);
		break;
	}


	default:
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
	}

	return NULL;
}


bool Window::init()
{


	//Setting up WNDCLASSEX object
	WNDCLASSEX wc;
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = NULL;
	wc.lpszClassName = TEXT("MyWindowClass");
	wc.lpszMenuName = TEXT("");
	wc.style = NULL;
	wc.lpfnWndProc = esta;

	if (!::RegisterClassEx(&wc)) // If the registration of class will fail, the function will return false
		return false;

	/*if (!window)
		window = this;*/

		//Creation of the window
	m_hwnd = ::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, TEXT("MyWindowClass"), TEXT("DirectX Application"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768,
		NULL, NULL, NULL, this);

	//if the creation fail return false
	if (!m_hwnd)
		return false;

	//show up the window
	::UpdateWindow(m_hwnd);
	::ShowWindow(m_hwnd, SW_SHOW);
	::UpdateWindow(m_hwnd);




	//set this flag to true to indicate that the window is initialized and running
	m_is_run = true;



	return true;
}

bool Window::broadcast()
{
	MSG msg;


	while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	this->onUpdate();

	Sleep(1);

	return true;
}

/*void Window::crearlinea(int x, int y, int alt, int an)
{
	linea* lin = new linea();
	lin->setposi(x, y);
	lin->seta(alt, an);
	figuras.push_back(lin);
}

void Window::crearrectangulo(int x, int y, int alt, int an)
{
	rectangulo* rec = new rectangulo();
	rec->setposi(x, y);
	rec->seta(alt, an);
	figuras.push_back(rec);
}

void Window::creartriangulo(int x, int y, int alt, int an)
{
	triangulo* tri = new triangulo();
	tri->setposi(x, y);
	tri->seta(alt, an);
	figuras.push_back(tri);

}*/



bool Window::release()
{
	//Destroy the window
	if (!::DestroyWindow(m_hwnd))
		return false;

	return true;
}

bool Window::isRun()
{
	return m_is_run;
}

void Window::onCreate()
{
}

void Window::onUpdate()
{
}

void Window::onDestroy()
{
	m_is_run = false;
}

Window::~Window()
{
}