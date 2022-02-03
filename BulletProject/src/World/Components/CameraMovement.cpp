#include "CameraMovement.h"
#include <World/World.h>
#include <World/Components/Spatial.h>
#define KEY(key) (unsigned int)#key

CameraMovement::CameraMovement(float movementSpeed, float rotateSpeed)
{
    m_MovementSpeed = movementSpeed;
    m_RotateSpeed = rotateSpeed;
}

void CameraMovement::OnLogicTick()
{

    /*
    * Catch keys
    */
    if (IsKeyDown((unsigned int)'w'))
    {
        GetSpatial()->SetPosition(GetSpatial()->GetPosition() + glm::vec3(0, 0, m_MovementSpeed));
    }
    else if (IsKeyDown((unsigned int)'s'))
    {
        GetSpatial()->SetPosition(GetSpatial()->GetPosition() + glm::vec3(0, 0, -m_MovementSpeed));
    }
    if (IsKeyDown((unsigned int)'a'))
    {
        GetSpatial()->SetPosition(GetSpatial()->GetPosition() + glm::vec3(m_MovementSpeed, 0, 0));
    }
    else if (IsKeyDown((unsigned int)'d'))
    {
        GetSpatial()->SetPosition(GetSpatial()->GetPosition() + glm::vec3(-m_MovementSpeed, 0, 0));
    }
    if (IsKeyDown((unsigned int)'e'))
    {
        GetSpatial()->SetPosition(GetSpatial()->GetPosition() + glm::vec3(0, m_MovementSpeed, 0));
    }
    else if (IsKeyDown((unsigned int)'q'))
    {
        GetSpatial()->SetPosition(GetSpatial()->GetPosition() + glm::vec3(0, -m_MovementSpeed, 0));
    }
}

bool CameraMovement::ShouldLogicTick() const
{
    return true;
}
