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
/// <summary>
/// Represents a scene state with the collection of objects
/// </summary>
class EXPORT World
{
public:
	World(const Window* window);
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

	FORCEINLINE bool IsKeyDown(unsigned int key);
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
	const Window* m_Window;
};

