#include "Spatial.h"
#include <glm/gtc/matrix_transform.hpp>
Spatial::Spatial()
{
    m_Position = glm::vec4(0);
    m_Rotation = glm::vec4(4);
    m_Scale = 1.0f;
}

glm::vec3 Spatial::GetPosition() const
{
    return m_Position;
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

    return
        glm::translate(glm::mat4x4(1), m_Position) *
        glm::scale(glm::mat4x4(1), glm::vec3(m_Scale, m_Scale, m_Scale)) *
        glm::rotate(glm::mat4x4(1), 45.0f, glm::vec3(1.0f, 0, 0))*
        glm::rotate(glm::mat4x4(1), 0.0f, glm::vec3(0, 0, 0))*
        glm::rotate(glm::mat4x4(1), 0.0f, glm::vec3(0, 0, 1.0f));
}
