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

	/*
	* Mark entity destroyed
	*/
	void MarkEntityDestroyed(Entity* entity);

	/// <summary>
	/// Makes cursor visible
	/// </summary>
	FORCEINLINE void ShowCursor() const;

	/// <summary>
	/// Hides the cursor
	/// </summary>
	FORCEINLINE void HideCursor() const;

	/// <summary>
	/// Sets the cursor position
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	FORCEINLINE void SetCursorPositionUndetected(int x, int y);

	/// <summary>
	/// Resets the mouse delta state
	/// </summary>
	FORCEINLINE void FlushMouseDelta();

	/// <summary>
	/// Returns the mouse x
	/// </summary>
	/// <returns></returns>
	FORCEINLINE int GetMouseX() const;

	/// <summary>
	/// Returns the mouse y
	/// </summary>
	/// <returns></returns>
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

	/// <summary>
	/// Returns the observer objects
	/// </summary>
	/// <returns></returns>
	FORCEINLINE const Array<ObserverComponent*>& GetObserverObjects() const;

	/// <summary>
	/// Returns the renderable objects of this world
	/// </summary>
	/// <returns></returns>
	FORCEINLINE const Array<RenderableComponent*>& GetRenderableObjects() const;

	/// <summary>
	/// Returns the logic tickable objects of this world
	/// </summary>
	/// <returns></returns>
	FORCEINLINE const Array<Component*>& GetLogicTickableObjects() const;

	/// <summary>
	/// Returns the collision objects
	/// </summary>
	/// <returns></returns>
	FORCEINLINE const Array<SphereColliderComponent*> GetCollisionObjects() const;

	/// <summary>
	/// Frees the heap objects of the marked entities
	/// </summary>
	void DeleteMarkedEntities();
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

	Array<Entity*> m_MarkedEntities;
	Array<RenderableComponent*> m_Renderables;
	Array<ObserverComponent*> m_Observers;
	Array<SphereColliderComponent*> m_Colliders;
	Array<Component*> m_TickableComponents;
	Array<Entity*> m_Entities;
	Renderer* m_Renderer;
	PhySolver* m_PhySolver;
	Window* m_Window;
};

