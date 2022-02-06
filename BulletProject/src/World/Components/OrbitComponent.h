#pragma once
#include <World/Component.h>

/// <summary>
/// The component which orbits around the target parent entity
/// </summary>
class EXPORT OrbitComponent : public Component
{
public:
	OrbitComponent(Entity* targetEntity,float distance, float speed,float startAngle);

	virtual bool ShouldLogicTick() const override { return true; }

	/// <summary>
	/// Returns the orbit speed
	/// </summary>
	/// <returns></returns>
	FORCEINLINE float GetSpeed() const;

	/// <summary>
	/// Sets the orbit speed
	/// </summary>
	/// <param name="speed"></param>
	void SetSpeed(float speed);

	virtual void OnLogicTick() override;
private:
	Entity* m_TargetEntity;
	float m_Distance;
	float m_Speed;
	float m_CurrentAngle;
};

