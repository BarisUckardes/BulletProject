#pragma once
#include <Memory/String.h>
class Entity;
class Spatial;
class SphereColliderComponent;

/// <summary>
/// Simple unit for scripting
/// They are only and only attached to entity
/// </summary>
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

	/// <summary>
	/// Enables the window's cursor
	/// </summary>
	FORCEINLINE void ShowCursor() const;

	/// <summary>
	/// Disables the window's cursor
	/// </summary>
	FORCEINLINE void HideCursor() const;

	/// <summary>
	/// Refreshes to mouse delta
	/// </summary>
	FORCEINLINE void FlushMouseDelta() const;

	/// <summary>
	/// Sets the mouse position in pixels
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	FORCEINLINE void SetCursorPosition(int x,int y) const;

	/// <summary>
	/// Returns whether the is down or not
	/// </summary>
	/// <param name="key"></param>
	/// <returns></returns>
	FORCEINLINE bool IsKeyDown(unsigned int key) const;

	/// <summary>
	/// Returns whether the mouse button is down or not
	/// </summary>
	/// <param name="button"></param>
	/// <returns></returns>
	FORCEINLINE bool IsButtonDown(unsigned int button) const;

	/// <summary>
	/// Returns the position x in pixels
	/// </summary>
	/// <returns></returns>
	FORCEINLINE int GetMouseX() const;

	/// <summary>
	/// Returns the position y in pixels
	/// </summary>
	/// <returns></returns>
	FORCEINLINE int GetMouseY() const;

	/// <summary>
	/// Returns the mouse delta x
	/// </summary>
	/// <returns></returns>
	FORCEINLINE int GetMouseDeltaX() const;

	/// <summary>
	/// Returns the mouse delta y
	/// </summary>
	/// <returns></returns>
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

