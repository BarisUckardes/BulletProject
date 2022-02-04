#include "WeaponComponent.h"
#include <World/Entity.h>
#include <World/World.h>
#include <World/Components/Spatial.h>
WeaponComponent::WeaponComponent(float bulletSpeed, float bulletSize, Mesh* bulletMesh, ShaderProgram* bulletProgram, const glm::vec4& color)
{
    m_BulletSpeed = bulletSpeed;
    m_BulletSize = bulletSize;
    m_Mesh = bulletMesh;
    m_Program = bulletProgram;
    m_Color = color;
}

bool WeaponComponent::ShouldLogicTick() const
{
    return false;
}

void WeaponComponent::OnLogicTick()
{
    /*
    * Check click
    */
    if (IsKeyDown(0))
    {
        /*
        * Create bullet entity
        */

    }
}
