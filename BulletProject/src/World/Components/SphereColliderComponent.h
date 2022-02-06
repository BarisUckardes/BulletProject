#pragma once
#include <World/Component.h>

/// <summary>
/// Basic physics component which is registered to world physical objects when created
/// </summary>
class EXPORT SphereColliderComponent : public Component
{
public:
	SphereColliderComponent(float radius);
	virtual bool ShouldLogicTick() const override final { return false; }
	virtual void OnInitialize() override;
	virtual void OnDestroyed() override;

	/// <summary>
	/// Returns the radius of the collider
	/// </summary>
	/// <returns></returns>
	FORCEINLINE float GetRadius() const;

	/// <summary>
	/// Returns the radius in world space
	/// </summary>
	/// <returns></returns>
	FORCEINLINE float GetRadiusWorld() const;
private:
	float m_Radius;
};

