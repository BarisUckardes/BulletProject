#pragma once
#include <Memory/String.h>

/// <summary>
/// Simple struct contains only the command line parameters
/// </summary>
struct WindowCmdArgs
{
	WindowCmdArgs(int count,char** arguments) : Count(count),Arguments(arguments){}

	/// <summary>
	/// The quantity of the parameters
	/// </summary>
	int Count;

	/// <summary>
	/// The parameters
	/// </summary>
	char** Arguments;
};

/// <summary>
/// Represents a physical window
/// </summary>
class EXPORT Window
{
public:
	Window(const String& title, int offsetX, int offsetY, int width, int height,WindowCmdArgs args,bool bSetInternalCallbacks);
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
	/// Called when mouse moved
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void OnMouseMove(int x, int y);

	/// <summary>
	/// Called when mouse button pressed down
	/// </summary>
	/// <param name="button"></param>
	void OnMouseButtonDown(int button);

	/// <summary>
	/// Called when mouse button is up
	/// </summary>
	/// <param name="button"></param>
	void OnMouseButtonUp(int button);

	/// <summary>
	/// Hides the cursor of this window
	/// </summary>
	FORCEINLINE void HideCursor() const;

	/// <summary>
	/// Shows the cursor of this window
	/// </summary>
	FORCEINLINE void ShowCursor() const;

	/// <summary>
	/// Sets the cursor
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	FORCEINLINE void SetCursorPositionUndetected(int x, int y);

	/// <summary>
	/// Refreshes the mouse delta 
	/// </summary>
	FORCEINLINE void FlushMouseDelta();

	/// <summary>
	/// Returns the mouse position x
	/// </summary>
	/// <returns></returns>
	FORCEINLINE int GetMouseX() const;

	/// <summary>
	/// Returns the mouse position y
	/// </summary>
	/// <returns></returns>
	FORCEINLINE int GetMouseY() const;
	/// <summary>
	/// Returns mouse displacement x
	/// </summary>
	/// <returns></returns>
	FORCEINLINE int GetMouseDeltaX() const;

	/// <summary>
	/// Returns mouse displacement y
	/// </summary>
	/// <returns></returns>
	FORCEINLINE int GetMouseDeltaY() const;

	/// <summary>
	/// Returns the key state
	/// </summary>
	/// <returns></returns>
	FORCEINLINE const Array<bool>& GetKeyState() const;

	/// <summary>
	/// Returns the mouse buttons state
	/// </summary>
	/// <returns></returns>
	FORCEINLINE const Array<bool>& GetMouseButtonState() const;
private:
	Array<bool> m_Keys;
	Array<bool> m_MouseButtons;
	String m_Title;
	int m_OffsetX;
	int m_OffsetY;
	int m_Width;
	int m_Height;
	int m_MouseX;
	int m_MouseY;
	int m_MouseDeltaX;
	int m_MouseDeltaY;
	bool m_bCloseRequest;
};

