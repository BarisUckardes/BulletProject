#include "ObserverComponent.h"
#include <World/World.h>
#include <World/Entity.h>
#include <World/Components/Spatial.h>
#include <glm/gtc/matrix_transform.hpp>

ObserverComponent::ObserverComponent()
{
    m_ClearColor = glm::vec4(1.0f, 0, 0, 0);
    m_FieldOfView = 60.0f;
    m_NearClip = 0.001f;
    m_FarClip = 1000.0f;
}
void ObserverComponent::OnInitialize()
{
    Component::OnInitialize();
    GetOwnerEntity()->GetOwnerWorld()->RegisterObserverComponent(this);
}

glm::mat4x4 ObserverComponent::GetProjectionMatrix() const
{
    /*
    * Prepare
    */
    const float fovInRadians = glm::radians(m_FieldOfView);
    const float aspectRatio = 1280.f / 720.0f;

    return glm::perspective(fovInRadians,aspectRatio,m_NearClip,m_FarClip);
}

glm::mat4x4 ObserverComponent::GetViewMatrix() const
{
    /*
    * Get position of this entity
    */
    const glm::vec3 position = GetSpatial()->GetPosition();

    /*
    * Get the look direction
    */
    const glm::vec3 lookDirection = glm::vec3(0, 0, 1);

    /*
    * Create position
    */
    const glm::vec3 lookPosition = position + lookDirection;

    /*
    * Get relative up
    */
    const glm::vec3 relativeUp = glm::vec3(0, 1, 0);

    return glm::lookAt(position, position + lookDirection, relativeUp);
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
