#include "WeaponComponent.h"
#include <World/Entity.h>
#include <World/World.h>
#include <World/Components/Spatial.h>
#include <World/Components/RenderableComponent.h>
#include <World/Components/BulletComponent.h>
#include <World/Components/SphereColliderComponent.h>
WeaponComponent::WeaponComponent(float bulletSpeed, float bulletSize, Mesh* bulletMesh, ShaderProgram* bulletProgram, const glm::vec4& color)
{
    m_BulletSpeed = bulletSpeed;
    m_BulletSize = bulletSize;
    m_Mesh = bulletMesh;
    m_Program = bulletProgram;
    m_Color = color;
    m_bHold = false;
}

bool WeaponComponent::ShouldLogicTick() const
{
    return true;
}

void WeaponComponent::OnLogicTick()
{
    /*
    * Check click
    */
    if (IsKeyDown(32) && !m_bHold)
    {
        /*
        * Create bullet entity
        */
        Entity* bulletEntity = GetOwnerEntity()->GetOwnerWorld()->CreateEntity("Bullet");
        bulletEntity->AddComponent<RenderableComponent>(m_Mesh,m_Program,m_Color);
        bulletEntity->AddComponent<BulletComponent>(GetSpatial()->GetForwardVector(), m_BulletSpeed);
        bulletEntity->AddComponent<SphereColliderComponent>(1.0f);
        bulletEntity->GetSpatial()->SetPosition(GetSpatial()->GetPosition());
        bulletEntity->GetSpatial()->SetScale(m_BulletSize);

        m_bHold = true;


    }
    else if(!IsKeyDown(32))
    {
        m_bHold = false;
    }
}
