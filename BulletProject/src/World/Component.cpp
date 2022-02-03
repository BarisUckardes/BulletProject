#include "Component.h"
#include <World/Entity.h>
#include <World/World.h>
void Component::OnInitialize()
{
	if (ShouldLogicTick())
	{
		m_OwnerEntity->GetOwnerWorld()->RegisterLogicComponent(this);
	}
}
Spatial* Component::GetSpatial() const
{
	return m_OwnerEntity->GetSpatial();
}

Entity* Component::GetOwnerEntity() const
{
	return m_OwnerEntity;
}

void Component::SetOwnerEntity(Entity* entity)
{
	m_OwnerEntity = entity;
}
