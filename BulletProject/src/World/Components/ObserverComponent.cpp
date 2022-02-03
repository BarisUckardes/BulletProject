#include "ObserverComponent.h"

glm::mat4x4 ObserverComponent::GetProjectionMatrix() const
{
    return glm::mat4x4();
}

glm::mat4x4 ObserverComponent::GetViewMatrix() const
{
    return glm::mat4x4();
}

glm::vec4 ObserverComponent::GetClearColor() const
{
    return m_ClearColor;
}

float ObserverComponent::GetNearClip() const
{
    return m_NearClip;
}

float ObserverComponent::GetFarClip() const
{
    return m_FarClip;
}

float ObserverComponent::GetFieldForView() const
{
    return m_FieldOfView;
}


void ObserverComponent::SetNearClip(float value)
{
    m_NearClip = value;
}

void ObserverComponent::SetFarClip(float value)
{
    m_FarClip = value;
}

void ObserverComponent::SetFieldOfView(float angles)
{
    m_FieldOfView = angles;
}

void ObserverComponent::SetClearColor(const glm::vec4& color)
{
    m_ClearColor = color;
}
