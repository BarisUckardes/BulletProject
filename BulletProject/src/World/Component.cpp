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

void Component::ShowCursor() const
{
	m_OwnerEntity->GetOwnerWorld()->ShowCursor();
}

void Component::HideCursor() const
{
	m_OwnerEntity->GetOwnerWorld()->HideCursor();
}

void Component::FlushMouseDelta() const
{
	m_OwnerEntity->GetOwnerWorld()->FlushMouseDelta();
}

void Component::SetCursorPosition(int x, int y) const
{
	m_OwnerEntity->GetOwnerWorld()->SetCursorPositionUndetected(x, y);
}

bool Component::IsKeyDown(unsigned int key) const
{
	return m_OwnerEntity->GetOwnerWorld()->IsKeyDown(key);
}

bool Component::IsButtonDown(unsigned int button) const
{
	return m_OwnerEntity->GetOwnerWorld()->IsMouseButtonDown(button);
}

int Component::GetMouseX() const
{
	return m_OwnerEntity->GetOwnerWorld()->GetMouseX();
}

int Component::GetMouseY() const
{
	return m_OwnerEntity->GetOwnerWorld()->GetMouseY();
}

int Component::GetMouseDeltaX() const
{
	return m_OwnerEntity->GetOwnerWorld()->GetMouseDeltaX();
}

int Component::GetMosueDeltaY() const
{
	return m_OwnerEntity->GetOwnerWorld()->GetMouseDeltaY();
}

void Component::OnDestroyed()
{
	if (ShouldLogicTick())
	{
		m_OwnerEntity->GetOwnerWorld()->RemoveLogicComponent(this);
	}
}

void Component::SetOwnerEntity(Entity* entity)
{
	m_OwnerEntity = entity;
}
