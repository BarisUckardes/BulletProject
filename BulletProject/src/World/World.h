#pragma once
#include <Memory/String.h>
#include <Memory/Array.h>

class RenderableComponent;
class ObserverComponent;
class SphereColliderComponent;
class Window;
class Entity;
class Component;
class Renderer;
class PhySolver;
/// <summary>
/// Represents a scene state with the collection of objects
/// </summary>
class EXPORT World
{
public:
	World(Window* window);
	~World();

	/// <summary>
	/// Ticks this world's physics,logic and rendering routines
	/// </summary>
	void TickWorld();

	/// <summary>
	/// Creates new entity into this world
	/// </summary>
	/// <param name="name"></param>
	/// <returns></returns>
	Entity* CreateEntity(const String& name);

	/// <summary>
	/// Registers a logic tickable component
	/// </summary>
	/// <param name="component"></param>
	void RegisterLogicComponent(Component* component);

	/// <summary>
	/// Removes the logic tickable component
	/// </summary>
	/// <param name="component"></param>
	void RemoveLogicComponent(Component* component);

	/// <summary>
	/// Registers a renderable component
	/// </summary>
	/// <param name="component"></param>
	void RegisterRenderableComponent(RenderableComponent* component);

	/// <summary>
	/// Removes the renderable component
	/// </summary>
	/// <param name="component"></param>
	void RemoveRenderableComponent(RenderableComponent* component);

	/// <summary>
	/// Registers an observer component
	/// </summary>
	/// <param name="component"></param>
	void RegisterObserverComponent(ObserverComponent* component);

	/// <summary>
	/// Removes the observer component
	/// </summary>
	/// <param name="component"></param>
	void RemoveObserverComponent(ObserverComponent* component);

	/// <summary>
	/// Registers a collider component
	/// </summary>
	/// <param name="component"></param>
	void RegisterColliderComponent(SphereColliderComponent* component);

	/// <summary>
	/// Removes the collider component
	/// </summary>
	/// <param name="component"></param>
	void RemoveColliderComponent(SphereColliderComponent* component);


	FORCEINLINE void ShowCursor() const;
	FORCEINLINE void HideCursor() const;
	FORCEINLINE void SetCursorPositionUndetected(int x, int y);
	FORCEINLINE void FlushMouseDelta();
	FORCEINLINE int GetMouseX() const;
	FORCEINLINE int GetMouseY() const;

	/// <summary>
	/// Returns whether the key specified is down or not
	/// </summary>
	/// <param name="key"></param>
	/// <returns></returns>
	FORCEINLINE bool IsKeyDown(unsigned int key) const;

	/// <summary>
	/// Returns whether the mouse button is down or not
	/// </summary>
	/// <param name="button"></param>
	/// <returns></returns>
	FORCEINLINE bool IsMouseButtonDown(unsigned int button) const;

	/// <summary>
	/// Returns the amount of mouse displacement for one frame x
	/// </summary>
	/// <returns></returns>
	FORCEINLINE int GetMouseDeltaX() const;

	/// <summary>
	/// Returns the amount of mouse displacement for one frame y
	/// </summary>
	/// <returns></returns>
	FORCEINLINE int GetMouseDeltaY() const;

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

	/// <summary>
	/// Refreshes the input state
	/// </summary>
	void TickInput();

	Array<RenderableComponent*> m_Renderables;
	Array<ObserverComponent*> m_Observers;
	Array<SphereColliderComponent*> m_Colliders;
	Array<Component*> m_TickableComponents;
	Array<Entity*> m_Entities;
	Renderer* m_Renderer;
	PhySolver* m_PhySolver;
	Window* m_Window;
};

