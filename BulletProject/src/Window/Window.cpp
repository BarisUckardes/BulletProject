#include "Window.h"
#include <GLUT/freeglut.h>
#include <stdio.h>

Window* s_Window = nullptr;

void OnDisplay();
Window::Window(const String& title, int offsetX, int offsetY, int width, int height,WindowCmdArgs args)
{
	/*
	* Initialize glut library
	*/
	glutInit(&args.Count, args.Arguments);

	/*
	* Initialize glut swapchain frambuffer mode
	*/
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	/*
	* Initialize window properties
	*/
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1280, 720);

	
	/*
	* Create window
	*/
	glutCreateWindow("Bullet Application");

	/*
	* Set event callbacks
	*/
	glutDisplayFunc(OnDisplay); //apperently this is mandatory

	/*
	* Set window global
	*/
	s_Window = this;
}

Window::~Window()
{

}

String Window::GetTitle() const
{
    return m_Title;
}

int Window::GetOffsetX() const
{
    return m_OffsetX;
}

int Window::GetOffsetY() const
{
    return m_OffsetY;
}

int Window::GetWidth() const
{
    return m_Width;
}

int Window::GetHeight() const
{
    return m_Height;
}

bool Window::HasCloseRequest() const
{
	return m_bCloseRequest;
}

void Window::PollWindowEvents()
{
	glutMainLoopEvent();
}

void Window::Swapbuffers()
{
	glutSwapBuffers();
}

int d = 0;
void OnDisplay()
{
	printf("Display %d\n",d);
	d++;
}