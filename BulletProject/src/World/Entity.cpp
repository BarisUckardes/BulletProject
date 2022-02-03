#include "Entity.h"
#include <World/Components/Spatial.h>
Spatial* Entity::GetSpatial() const
{
	return m_Spatial;
}
World* Entity::GetOwnerWorld() const
{
	return m_OwnerWorld;
}
Entity::Entity(World* ownerWorld,const String& name)
{
	/*
	* Set owner world
	*/
	m_OwnerWorld = ownerWorld;

	/*
	* Set name
	*/
	SetName(name);

	/*
	* Create spatial component
	*/
	Component* spatial = new Spatial();

	/*
	* Register spatial
	*/
	spatial->SetOwnerEntity(this);
	m_Spatial = (Spatial*)spatial;
	m_Components.Add(spatial);
}

Entity::~Entity()
{
}
