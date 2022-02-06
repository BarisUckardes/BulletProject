#include "BulletComponent.h"
#include <World/Entity.h>
#include <World/Components/Spatial.h>
#include <World/Entity.h>
#include <World/Components/SphereColliderComponent.h>
#include <World/Components/ParentComponent.h>
BulletComponent::BulletComponent(const glm::vec3& direction, float speed)
{
    m_Direction = direction;
    m_Speed = speed;
}

bool BulletComponent::ShouldLogicTick() const
{
    return true;
}

void BulletComponent::OnLogicTick()
{
    /*
    * Go to direction
    */
    GetSpatial()->SetPosition(GetSpatial()->GetPosition() + m_Direction * m_Speed);

    /*
    * validate and destroy
    */
    if (glm::distance(GetSpatial()->GetPosition(), glm::vec3(0)) > 150.0f) // destroy
    {
        GetOwnerEntity()->MarkEntityDestroyed();
    }
}

void BulletComponent::OnCollision(SphereColliderComponent* other)
{

    /*
    * Validate if its a main sphere
    */
    Entity* otherEntity = other->GetOwnerEntity();
   
    if (otherEntity->GetName() == "ParentEntity")
    {
        other->GetOwnerEntity()->GetComponent<ParentComponent>()->DestoryChildOrSelf();
        this->GetOwnerEntity()->MarkEntityDestroyed();
    }
}
