#include "Renderer.h"

const Window* Renderer::GetWindow() const
{
	return m_Window;
}

void Renderer::SetWindow(const Window* window)
{
	m_Window = window;
}
