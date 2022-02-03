#pragma once
#include <Memory/String.h>

struct WindowCmdArgs
{
	WindowCmdArgs(int count,char** arguments) : Count(count),Arguments(arguments){}
	int Count;
	char** Arguments;
};

/// <summary>
/// Represents a physical window
/// </summary>
class EXPORT Window
{
public:
	Window(const String& title, int offsetX, int offsetY, int width, int height,WindowCmdArgs args);
	~Window();

	/// <summary>
	/// Returns the window title
	/// </summary>
	/// <returns></returns>
	FORCEINLINE String GetTitle() const;

	/// <summary>
	/// Returns the offset from the window's lower left corner
	/// </summary>
	/// <returns></returns>
	FORCEINLINE int GetOffsetX() const;

	/// <summary>
	/// Returns the offset from the window's lower left corner
	/// </summary>
	/// <returns></returns>
	FORCEINLINE int GetOffsetY() const;

	/// <summary>
	/// Returns the window width
	/// </summary>
	/// <returns></returns>
	FORCEINLINE int GetWidth() const;

	/// <summary>
	/// Returns the window height
	/// </summary>
	/// <returns></returns>
	FORCEINLINE int GetHeight() const;

	/// <summary>
	/// Returns whether this window should be closed or not
	/// </summary>
	/// <returns></returns>
	FORCEINLINE bool HasCloseRequest() const;

	/// <summary>
	/// Polls and submits window events
	/// </summary>
	void PollWindowEvents();

	/// <summary>
	/// Swaps the swapchain framebuffer
	/// </summary>
	void Swapbuffers();

	/// <summary>
	/// Called when resized
	/// </summary>
	/// <param name="width"></param>
	/// <param name="height"></param>
	void OnWindowResized(int width, int height);

	/// <summary>
	/// Called when key pressed
	/// </summary>
	/// <param name="key"></param>
	void OnKeyPress(unsigned char key);

	/// <summary>
	/// Called when key released
	/// </summary>
	/// <param name="key"></param>
	void OnKeyUp(unsigned int key);

	/// <summary>
	/// Returns the key state
	/// </summary>
	/// <returns></returns>
	FORCEINLINE const Array<bool>& GetKeyState() const;
private:
	Array<bool> m_Keys;
	String m_Title;
	int m_OffsetX;
	int m_OffsetY;
	int m_Width;
	int m_Height;
	bool m_bCloseRequest;
};

