#pragma once
#include <Memory/String.h>
#include <Memory/Array.h>

class RenderableComponent;
class ObserverComponent;
class SphereColliderComponent;
class Window;

/// <summary>
/// Represents a scene state with the collection of objects
/// </summary>
class World
{
public:
	World(const Window* window);
	~World();

	/// <summary>
	/// Ticks this world's physics,logic and rendering routines
	/// </summary>
	void TickWorld();
private:
	/// <summary>
	/// Solves the physical state of the world
	/// </summary>
	void SolvePhysics();

	/// <summary>
	/// Executes all the logic components
	/// </summary>
	void TickLogic();

	/// <summary>
	/// Renders the renderables from the view of the observers
	/// </summary>
	void TickRendering();

	Array<RenderableComponent*> m_Renderables;
	Array<ObserverComponent*> m_Observers;
	Array<SphereColliderComponent*> m_Colliders;

	Window* m_Window;
};

