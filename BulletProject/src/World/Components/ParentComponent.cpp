#include "ParentComponent.h"
#include <World/Components/OrbitComponent.h>
#include <World/Entity.h>
ParentComponent::ParentComponent(OrbitComponent* child0, OrbitComponent* child1)
{
    m_Childs.Add(child0);
    m_Childs.Add(child1);
}

bool ParentComponent::ShouldLogicTick() const
{
    return false;
}

void ParentComponent::DestoryChildOrSelf()
{
    /*
    * Destroy one of the childs
    */
    m_Childs[0]->GetOwnerEntity()->DestroyEntity();
    m_Childs.RemoveIndex(0);

    /*
    * Speed of the other
    */
    m_Childs[0]->SetSpeed(m_Childs[0]->GetSpeed() * 2.0f);

    /*
    * Validate if any left
    */
    if (m_Childs.GetCursor() <= 0)
    {
        GetOwnerEntity()->DestroyEntity();
    }
}
