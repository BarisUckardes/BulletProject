#include "OrbitComponent.h"
#include <glm/trigonometric.hpp>
#include <glm/vec3.hpp>
#include <World/Components/Spatial.h>
#include <World/Entity.h>
OrbitComponent::OrbitComponent(Entity* targetEntity, float distance, float speed,float startAngle)
{
    m_TargetEntity = targetEntity;
    m_Distance = distance;
    m_Speed = speed;
    m_CurrentAngle = startAngle;
}

float OrbitComponent::GetSpeed() const
{
    return m_Speed;
}

void OrbitComponent::SetSpeed(float speed)
{
    m_Speed = speed;
}

void OrbitComponent::OnLogicTick()
{
    
    /*
    * Current angle to direction
    */
    const float cos = glm::cos(glm::radians(m_CurrentAngle));
    const float sin = glm::sin(glm::radians(m_CurrentAngle));

    /*
    * Create direction vector
    */
    const glm::vec3 directionVector(cos,0.0f,sin);

    /*
    * Set orbit
    */
    GetSpatial()->SetPosition(m_TargetEntity->GetSpatial()->GetPosition() + directionVector*m_Distance);

    /*
    * Increment angle
    */
    m_CurrentAngle += m_Speed;
}
