#include "Spatial.h"

Spatial::Spatial()
{
    m_Position = glm::vec4(0);
    m_Rotation = glm::vec4(4);
    m_Scale = 1.0f;
}

glm::vec3 Spatial::GetPosition() const
{
    return glm::vec3();
}

glm::vec3 Spatial::GetRotation() const
{
    return m_Rotation;
}

float Spatial::GetScale() const
{
    return m_Scale;
}

void Spatial::SetPosition(const glm::vec3& position)
{
    m_Position = position;
}

void Spatial::SetRotation(const glm::vec3& rotation)
{
    m_Rotation = rotation;
}

void Spatial::SetScale(float scale)
{
    m_Scale = scale;
}

bool Spatial::ShouldLogicTick() const
{
    return false;
}

glm::mat4x4 Spatial::GetModelMatrix() const
{
    return glm::mat4x4();
}
