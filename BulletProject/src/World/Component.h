#pragma once
#include <Memory/String.h>
class Entity;
class Spatial;
class EXPORT Component
{
	friend class Entity;
public:
	
	/// <summary>
	/// Whether the logic of this component should tick or not
	/// </summary>
	/// <returns></returns>
	virtual bool ShouldLogicTick() const = 0;

	/// <summary>
	/// Logic routine of this component
	/// </summary>
	virtual void OnLogicTick() {}

	/// <summary>
	/// Called when first created, used for registering certain type of components to world view
	/// </summary>
	virtual void OnInitialize();

	/// <summary>
	/// Returns the spatial component of this component's entity
	/// </summary>
	/// <returns></returns>
	FORCEINLINE Spatial* GetSpatial() const;

	/// <summary>
	/// Returns the owning entity of this component
	/// </summary>
	/// <returns></returns>
	FORCEINLINE Entity* GetOwnerEntity() const;

	/// <summary>
	/// Returns whether the key is down or not
	/// </summary>
	/// <param name="key"></param>
	/// <returns></returns>
	FORCEINLINE bool IsKeyDown(unsigned int key) const;
protected:
	Component() = default;
	~Component() = default;

	/// <summary>
	/// Called when destroyed
	/// </summary>
	virtual void OnDestroyed();
private:
	

	/// <summary>
	/// Internal setter for owner entity
	/// </summary>
	/// <param name="entity"></param>
	void SetOwnerEntity(Entity* entity);

	Entity* m_OwnerEntity;
};

