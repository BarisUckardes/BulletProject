#include "Entity.h"
#include <World/Components/Spatial.h>
Spatial* Entity::GetSpatial() const
{
	return m_Spatial;
}
Array<Component*> Entity::GetComponents() const
{
	return m_Components;
}
World* Entity::GetOwnerWorld() const
{
	return m_OwnerWorld;
}
bool Entity::IsDestroyed() const
{
	return m_bDestroyed;
}
void Entity::DestroyEntity()
{
	/*
	* Unregister entity from the world
	*/

	/*
	* Destroy components
	*/
	for (unsigned int i = 0; i < m_Components.GetCursor(); i++)
	{
		/*
		* Get component
		*/
		DestroyComponent(m_Components[i]);

		/*
		* Destroy
		*/
		m_Components[i]->OnDestroyed();
	}

	m_Components.Clear();

	/*
	* Mark as destroyed
	*/
	m_bDestroyed = true;
}
void Entity::DestroyComponent(Component* component)
{


}
Entity::Entity(World* ownerWorld,const String& name)
{
	/*
	* Set owner world
	*/
	m_OwnerWorld = ownerWorld;

	/*
	* Set name
	*/
	SetName(name);

	/*
	* Create spatial component
	*/
	Component* spatial = new Spatial();

	/*
	* Register spatial
	*/
	spatial->SetOwnerEntity(this);
	m_Spatial = (Spatial*)spatial;
	m_Components.Add(spatial);
}

Entity::~Entity()
{
}
