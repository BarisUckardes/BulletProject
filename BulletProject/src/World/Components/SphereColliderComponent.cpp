#include "SphereColliderComponent.h"
#include <World/Components/Spatial.h>
float SphereColliderComponent::GetRadius() const
{
	return m_Radius;
}

float SphereColliderComponent::GetRadiusWorld() const
{
	return GetSpatial()->GetScale()*m_Radius;
}
