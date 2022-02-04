#include "World.h"
#include <World/Entity.h>
#include <World/Component.h>
#include <Renderer/ForwardRenderer.h>
#include <PhySolver/IterativePhySolver.h>
World::World(Window* window)
{
	m_Window = window;

	/*
	* Create renderer
	*/
	m_Renderer = new ForwardRenderer();
	m_Renderer->SetWindow(m_Window);

	/*
	* Create physics solver
	*/
	m_PhySolver = new IterativePhySolver();
}

World::~World()
{
}

void World::TickWorld()
{
	SolvePhysics();
	TickLogic();
	TickRendering();
}

Entity* World::CreateEntity(const String& name)
{
	/*
	* Create entity
	*/
	Entity* entity = new Entity(this, name);

	/*
	* Register entity
	*/
	m_Entities.Add(entity);

	return entity;
}

void World::RegisterLogicComponent(Component* component)
{
	m_TickableComponents.Add(component);
}

void World::RemoveLogicComponent(Component* component)
{
	m_TickableComponents.Remove(component);
}

void World::RegisterRenderableComponent(RenderableComponent* component)
{
	m_Renderables.Add(component);
}

void World::RemoveRenderableComponent(RenderableComponent* component)
{
	m_Renderables.Remove(component);
}

void World::RegisterObserverComponent(ObserverComponent* component)
{
	m_Observers.Add(component);
}

void World::RemoveObserverComponent(ObserverComponent* component)
{
	m_Observers.Remove(component);
}

void World::RegisterColliderComponent(SphereColliderComponent* component)
{
	m_Colliders.Add(component);
}

void World::RemoveColliderComponent(SphereColliderComponent* component)
{
	m_Colliders.Remove(component);
}

void World::ShowCursor() const
{
	m_Window->ShowCursor();
}

void World::HideCursor() const
{
	m_Window->HideCursor();
}

void World::SetCursorPositionUndetected(int x, int y)
{
	m_Window->SetCursorPositionUndetected(x, y);
}

void World::FlushMouseDelta()
{
	m_Window->FlushMouseDelta();
}

int World::GetMouseX() const
{
	return m_Window->GetMouseX();
}

int World::GetMouseY() const
{
	return m_Window->GetMouseY();
}

bool World::IsKeyDown(unsigned int key) const
{
	return m_Window->GetKeyState()[key];
}

bool World::IsMouseButtonDown(unsigned int button) const
{
	return m_Window->GetMouseButtonState()[button];
}

int World::GetMouseDeltaX() const
{
	return m_Window->GetMouseDeltaX();
}

int World::GetMouseDeltaY() const
{
	return m_Window->GetMouseDeltaY();
}

void World::SolvePhysics()
{
	/*
	* Get collsion reprots
	*/
	Array<CollisionReport> reports;
	m_PhySolver->Solve(m_Colliders, reports);

	/*
	* Broadcast collision reports
	*/
	for (unsigned int reportIndex = 0; reportIndex < reports.GetCursor(); reportIndex++)
	{
		/*
		* Get report
		*/
		CollisionReport& report = reports[reportIndex];

		/*
		* Get components
		*/
		Array<Component*> components = report.Self->GetComponents();

		/*
		* Iterate self entity components
		*/
		for (unsigned int componentIndex = 0; componentIndex < components.GetCursor(); componentIndex++)
		{
			/*
			* Invoke callback
			*/
			components[componentIndex]->OnCollision(report.Other);
		}
		
	}
}

void World::TickLogic()
{
	/*
	* Iterate and tick each component
	*/
	for (unsigned int i = 0; i < m_TickableComponents.GetCursor(); i++)
	{
		m_TickableComponents[i]->OnLogicTick();
	}
}

void World::TickRendering()
{
	m_Renderer->Render(m_Renderables,m_Observers);
}
