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
    * Listen to the keys
    */
    if (IsKeyDown((unsigned int)'w'))
    {
        GetSpatial()->SetPosition(GetSpatial()->GetPosition() + m_MovementSpeed*GetSpatial()->GetForwardVector());
    }
    else if (IsKeyDown((unsigned int)'s'))
    {
        GetSpatial()->SetPosition(GetSpatial()->GetPosition() + -m_MovementSpeed * GetSpatial()->GetForwardVector());
    }
    if (IsKeyDown((unsigned int)'a'))
    {
        GetSpatial()->SetPosition(GetSpatial()->GetPosition() + m_MovementSpeed * GetSpatial()->GetRightVector());
    }
    else if (IsKeyDown((unsigned int)'d'))
    {
        GetSpatial()->SetPosition(GetSpatial()->GetPosition() + -m_MovementSpeed * GetSpatial()->GetRightVector());
    }
    if (IsKeyDown((unsigned int)'e'))
    {
        GetSpatial()->SetPosition(GetSpatial()->GetPosition() + glm::vec3(0, m_MovementSpeed, 0));
    }
    else if (IsKeyDown((unsigned int)'q'))
    {
        GetSpatial()->SetPosition(GetSpatial()->GetPosition() + glm::vec3(0, -m_MovementSpeed, 0));
    }

    /*
    * Catch mouse
    */
    if (IsButtonDown(2))
    {
        /*
        * Hide cursor
        */
        HideCursor();

        /*
        * Get mouse position
        */
        if (!m_bNavigating)
        {
            m_MouseClickPositionX = GetMouseX();
            m_MouseClickPositionY = GetMouseY();
            m_CurrentX = GetMouseX();
            m_CurrentY = GetMouseY();
            m_bNavigating = true;
        }

        /*
        * Catch delta
        */
        const int x = GetMouseX();
        const int y = GetMouseY();
        m_DeltaX = ((float)x - (float)m_MouseClickPositionX);
        m_DeltaY = ((float)y - (float)m_MouseClickPositionY);
        const float deltaX = m_DeltaX*0.1f;
        const float deltaY = m_DeltaY *0.1f;
        SetCursorPosition(m_MouseClickPositionX, m_MouseClickPositionY);
        GetSpatial()->SetRotation(GetSpatial()->GetRotation() + glm::vec3(-deltaY,deltaX,0 ));
    }
    else if(!IsButtonDown(2) && m_bNavigating)
    {
        /*
        * Set navigating to false
        */
        m_bNavigating = false;

        /*
        * Set cursor position back 
        */
        SetCursorPosition(m_MouseClickPositionX, m_MouseClickPositionY);
        //FlushMouseDelta();

        /*
        * Show cursor
        */
        ShowCursor();
    }

    //LOG("%d,%d", GetMouseDeltaX(), GetMosueDeltaY());
}

bool CameraMovement::ShouldLogicTick() const
{
    return true;
}
