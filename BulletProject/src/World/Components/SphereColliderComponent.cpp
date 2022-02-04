#include "SphereColliderComponent.h"
#include <World/Components/Spatial.h>
#include <World/Entity.h>
#include <World/World.h>
SphereColliderComponent::SphereColliderComponent(float radius)
{
	m_Radius = radius;
}
void SphereColliderComponent::OnInitialize()
{
	GetOwnerEntity()->GetOwnerWorld()->RegisterColliderComponent(this);
}
void SphereColliderComponent::OnDestroyed()
{
	GetOwnerEntity()->GetOwnerWorld()->RemoveColliderComponent(this);
}
float SphereColliderComponent::GetRadius() const
{
	return m_Radius;
}

float SphereColliderComponent::GetRadiusWorld() const
{
	return GetSpatial()->GetScale()*m_Radius;
}
