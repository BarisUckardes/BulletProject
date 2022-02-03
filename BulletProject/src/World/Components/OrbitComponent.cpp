#include "OrbitComponent.h"

OrbitComponent::OrbitComponent(Entity* targetEntity, float distance, float speed)
{
    m_TargetEntity = targetEntity;
    m_Distance = distance;
    m_Speed = speed;
}

float OrbitComponent::GetSpeed() const
{
    return m_Speed;
}

void OrbitComponent::SetSpeed(float speed)
{
    m_Speed = speed;
}
