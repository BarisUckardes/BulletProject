#include "Window.h"
#include <GL/glew.h>
#include <GLUT/freeglut.h>
#include <stdio.h>

Window* s_Window = nullptr;
void g_OnDisplay();
void g_OnWindowResized(int width, int height);
Window::Window(const String& title, int offsetX, int offsetY, int width, int height,WindowCmdArgs args)
{
	/*
	* Set properties
	*/
	m_OffsetX = offsetX;
	m_OffsetY = offsetY;
	m_Width = width;
	m_Height = height;

	/*
	* Initialize glut library
	*/
	glutInit(&args.Count, args.Arguments);

	
#ifdef DEBUG_MODE
	glutInitContextFlags(GLUT_FORWARD_COMPATIBLE | GLUT_DEBUG);
	glewExperimental = true;
#else
	glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
#endif
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutInitContextVersion(4, 5);

	/*
	* Initialize glut swapchain frambuffer mode
	*/
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);

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
	glutDisplayFunc(g_OnDisplay); //apperently this is mandatory
	glutReshapeFunc(g_OnWindowResized);

	/*
	* Set window global
	*/
	s_Window = this;

	/*
	* Initialize glew
	*/
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		LOG("Glew żnitialization failed!");
	}

#ifdef DEBUG_MODE
	glDebugMessageCallback(
		[](GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
		{
				LOG("OPENGL ERROR: %s", message);
		}
	, nullptr);
#endif
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

void Window::OnWindowResized(int width, int height)
{
	m_Width = width;
	m_Height = height;
}

unsigned long long d = 0;
void g_OnDisplay()
{
	LOG("Frame %ld",d);
	d++;
}
void g_OnWindowResized(int width, int height)
{
	s_Window->OnWindowResized(width, height);
}