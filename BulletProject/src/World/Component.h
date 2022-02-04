#pragma once
#include <Memory/String.h>
class Entity;
class Spatial;
class SphereColliderComponent;
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
	/// Called when collision detected
	/// </summary>
	virtual void OnCollision(SphereColliderComponent* otherCollider) {}

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


	FORCEINLINE void ShowCursor() const;
	FORCEINLINE void HideCursor() const;
	FORCEINLINE void FlushMouseDelta() const;
	FORCEINLINE void SetCursorPosition(int x,int y) const;
	FORCEINLINE bool IsKeyDown(unsigned int key) const;
	FORCEINLINE bool IsButtonDown(unsigned int button) const;
	FORCEINLINE int GetMouseX() const;
	FORCEINLINE int GetMouseY() const;
	FORCEINLINE int GetMouseDeltaX() const;
	FORCEINLINE int GetMosueDeltaY() const;
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

