#include "Component.h"
#include <World/Entity.h>
Spatial* Component::GetSpatial() const
{
	return m_OwnerEntity->GetSpatial();
}

void Component::SetOwnerEntity(Entity* entity)
{
	m_OwnerEntity = entity;
}
