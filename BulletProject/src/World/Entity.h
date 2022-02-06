#pragma once
#include <Core/Object.h>
#include <Memory/String.h>
#include <Memory/Array.h>
#include <World/Component.h>
class World;
class Component;
class Spatial;

/// <summary>
/// Most basic unit in world
/// It contains components which are the real scrips to be executed everyframe
/// You can consider the entities are like a pointer to the collection of components but with more functionality along the way
/// </summary>
class EXPORT Entity : public Object
{
	friend class World;
public:
	/// <summary>
	/// Adds a new component to this entity
	/// </summary>
	/// <typeparam name="TComponent"></typeparam>
	/// <typeparam name="...TParameters"></typeparam>
	/// <param name="...parameters"></param>
	/// <returns></returns>
	template<typename TComponent,typename ... TParameters>
	TComponent* AddComponent(TParameters... parameters);

	/// <summary>
	/// Returns the component by type
	/// </summary>
	/// <typeparam name="TComponent"></typeparam>
	/// <returns></returns>
	template<typename TComponent>
	TComponent* GetComponent() const
	{
		/*
		* ITereate
		*/
		for (unsigned int i = 0; i < m_Components.GetCursor(); i++)
		{
			Component* component = dynamic_cast<TComponent*>(m_Components[i]);
			if (component != nullptr)
				return (TComponent*)component;
		}
		return nullptr;
	}

	/// <summary>
	/// Returns the spatial component of this entity
	/// </summary>
	/// <returns></returns>
	FORCEINLINE Spatial* GetSpatial() const;

	/// <summary>
	/// Returns the components of this entity
	/// </summary>
	/// <returns></returns>
	FORCEINLINE Array<Component*> GetComponents() const;

	/// <summary>
	/// Returns the world which entity belongs to
	/// </summary>
	/// <returns></returns>
	FORCEINLINE World* GetOwnerWorld() const;

	/// <summary>
	/// Destroys this entity
	/// </summary>
	void MarkEntityDestroyed();

	/// <summary>
	/// Frees the entity components
	/// </summary>
	void FreeEntityComponents();

	/// <summary>
	/// Destroys a child component
	/// </summary>
	/// <param name="component"></param>
	void DestroyComponent(Component* component);
private:
	Entity(World* ownerWorld,const String& name = "Undefined name");
	~Entity();

	Array<Component*> m_Components;
	World* m_OwnerWorld;
	Spatial* m_Spatial;
	bool m_bDestroyed;
	
};

template<typename TComponent, typename ...TParameters>
inline TComponent* Entity::AddComponent(TParameters ...parameters)
{
	/*
	* Create component
	*/
	TComponent* component = new TComponent(parameters...);

	/*
	* Set entity
	*/
	component->SetOwnerEntity(this);

	/*
	* Call on register
	*/
	component->OnInitialize();

	/*
	* Register
	*/
	m_Components.Add(component);

	return component;
}
