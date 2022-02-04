#include "Window.h"
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>

Window* s_Window = nullptr;
void g_OnDisplay();
void g_OnWindowResized(int width, int height);
void g_OnKey(unsigned char c,int,int);
void g_OnKeyUp(unsigned char c, int, int);
void g_OnMouse(int button, int key, int x, int y);
void g_OnMouseMove(int x, int y);
void g_OnIdle();
Window::Window(const String& title, int offsetX, int offsetY, int width, int height,WindowCmdArgs args)
{
	/*
	* Create key map
	*/
	for (int i = 0; i < 360; i++)
		m_Keys.Add(false);
	for (int i = 0; i < 10; i++)
		m_MouseButtons.Add(false);

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
	glutInitContextFlags(GLUT_FORWARD_COMPATIBLE | GLUT_DEPTH | GLUT_DEBUG);
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

	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);

	/*
	* Set event callbacks
	*/
	glutDisplayFunc(g_OnDisplay); //apperently this is mandatory
	glutReshapeFunc(g_OnWindowResized);
	glutKeyboardFunc(g_OnKey);
	glutKeyboardUpFunc(g_OnKeyUp);
	glutMouseFunc(g_OnMouse);
	glutPassiveMotionFunc(g_OnMouseMove);
	glutMotionFunc(g_OnMouseMove);
	glutIdleFunc(g_OnIdle);
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
		LOG("Glew ýnitialization failed!");
	}
	glEnable(GL_DEPTH_TEST);

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

void Window::OnKeyPress(unsigned char key)
{
	m_Keys[key] = true;
}

void Window::OnKeyUp(unsigned int key)
{
	m_Keys[key] = false;
}
unsigned long long a = 0;
void Window::OnMouseMove(int x, int y)
{
	a++;
	/*
	* Generate new mouse delta
	*/
	m_MouseDeltaX = x - m_MouseX;
	m_MouseDeltaY = y - m_MouseY;

	/*
	* Set new mouse position
	*/
	m_MouseX = x;
	m_MouseY = y;
}

void Window::OnMouseButtonDown(int button)
{
	m_MouseButtons[button] = true;
}

void Window::OnMouseButtonUp(int button)
{
	m_MouseButtons[button] = false;
}

void Window::HideCursor() const
{
	glutSetCursor(GLUT_CURSOR_NONE);
}

void Window::ShowCursor() const
{
	glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
}

void Window::SetCursorPositionUndetected(int x, int y)
{
	glutWarpPointer(x, y);
	m_MouseX = x;
	m_MouseY = y;
}

void Window::FlushMouseDelta() 
{
	m_MouseDeltaX = 0;
	m_MouseDeltaY = 0;
}

int Window::GetMouseX() const
{
	return m_MouseX;
}

int Window::GetMouseY() const
{
	return m_MouseY;
}

int Window::GetMouseDeltaX() const
{
	return m_MouseDeltaX;
}

int Window::GetMouseDeltaY() const
{
	return m_MouseDeltaY;
}

const Array<bool>& Window::GetKeyState() const
{
	return m_Keys;
}

const Array<bool>& Window::GetMouseButtonState() const
{
	return m_MouseButtons;
}

unsigned long long d = 0;
void g_OnDisplay()
{
	d++;
}
void g_OnWindowResized(int width, int height)
{
	s_Window->OnWindowResized(width, height);
}
void g_OnKey(unsigned char key, int a, int b)
{
	s_Window->OnKeyPress(key);
}
void g_OnKeyUp(unsigned char key, int a, int b)
{
	s_Window->OnKeyUp(key);
}
void g_OnMouse(int button, int state, int x, int y)
{
	/*
	* Catch supported states
	*/
	if (state == GLUT_DOWN)
	{
		s_Window->OnMouseButtonDown(button);
	}
	else if(state == GLUT_UP)
	{
		s_Window->OnMouseButtonUp(button);
	}
	s_Window->OnMouseMove(x, y);
}
void g_OnMouseMove(int x, int y)
{
	s_Window->OnMouseMove(x, y);
}
void g_OnIdle()
{
	const int x = s_Window->GetMouseX();
	const int y = s_Window->GetMouseY();
	s_Window->OnMouseMove(x, y);
	LOG("IDLE");
}