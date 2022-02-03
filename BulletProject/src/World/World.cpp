#include "World.h"

World::World(const Window* window)
{
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

void World::SolvePhysics()
{
}

void World::TickLogic()
{
}

void World::TickRendering()
{
}
