#pragma once
#include <Memory/Array.h>
#include <World/Components/RenderableComponent.h>
#include <World/Components/ObserverComponent.h>
#include <Window/Window.h>

/// <summary>
/// Basic interface class for creating more than one renderer implemntations
/// </summary>
class EXPORT Renderer
{
	friend class World;
public:
	/// <summary>
	/// Calls the derived class render implementations
	/// </summary>
	/// <param name="renderables"></param>
	/// <param name="observerComponents"></param>
	virtual void Render(const Array<RenderableComponent*>& renderables, const Array<ObserverComponent*>& observerComponents) = 0;

protected:
	Renderer() = default;
	~Renderer() = default;

	/// <summary>
	/// Returns the window
	/// </summary>
	/// <returns></returns>
	FORCEINLINE const Window* GetWindow() const;

	/// <summary>
	/// An internal setter for window
	/// </summary>
	/// <param name="window"></param>
	void SetWindow(const Window* window);
private:
	const Window* m_Window;
};