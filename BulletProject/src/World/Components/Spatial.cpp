#include "Spatial.h"
#include <glm/gtc/matrix_transform.hpp>
Spatial::Spatial()
{
    m_Position = glm::vec4(0);
    m_Rotation = glm::vec4(0);
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

glm::vec3 Spatial::GetForwardVector() const
{
    glm::mat4x4 rot = glm::mat4x4(1.0f);
    rot = glm::rotate(rot, glm::radians(m_Rotation.x), glm::vec3(1.0f, 0, 0));
    rot = glm::rotate(rot, glm::radians(m_Rotation.y), glm::vec3(0, 1.0f, 0));
    rot = glm::rotate(rot, glm::radians(m_Rotation.z), glm::vec3(0, 0, 1.0f));
    glm::vec4 v4 = glm::vec4(0,0,1,0) * rot;
    return glm::vec3(v4.x,v4.y,v4.z);
}

glm::vec3 Spatial::GetRightVector() const
{
    const glm::vec3 forwardVector = GetForwardVector();
    return glm::cross(glm::vec3(0, 1, 0), forwardVector);
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
    glm::mat4x4 model(1.0f);
    model = glm::translate(model, m_Position);
    model = glm::scale(model, glm::vec3(m_Scale));
    model = glm::rotate(model, glm::radians(m_Rotation.x), glm::vec3(1.0f, 0, 0));
    model = glm::rotate(model, glm::radians(m_Rotation.y), glm::vec3(0.0f, 1.0f, 0));
    model = glm::rotate(model, glm::radians(m_Rotation.z), glm::vec3(0.0f, 0, 1.0f));
    return model;

}
