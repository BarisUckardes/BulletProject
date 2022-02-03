#include "World.h"
#include <World/Entity.h>
#include <World/Component.h>
#include <Renderer/ForwardRenderer.h>
World::World(const Window* window)
{
	m_Window = window;

	/*
	* Create renderer
	*/
	m_Renderer = new ForwardRenderer();
	m_Renderer->SetWindow(m_Window);
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

void World::RegisterRenderableComponent(RenderableComponent* component)
{
	m_Renderables.Add(component);
}

void World::RegisterObserverComponent(ObserverComponent* component)
{
	m_Observers.Add(component);
}

void World::RegisterColliderComponent(SphereColliderComponent* component)
{
	m_Colliders.Add(component);
}

void World::SolvePhysics()
{

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
