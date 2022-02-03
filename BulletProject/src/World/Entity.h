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
	/// Returns the spatial component of this entity
	/// </summary>
	/// <returns></returns>
	FORCEINLINE Spatial* GetSpatial() const;

	/// <summary>
	/// Returns the world which entity belongs to
	/// </summary>
	/// <returns></returns>
	FORCEINLINE World* GetOwnerWorld() const;

	//Returns whether this entity is destroyed
	FORCEINLINE bool IsDestroyed() const;

	/// <summary>
	/// Destroys this entity
	/// </summary>
	void DestroyEntity();

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
