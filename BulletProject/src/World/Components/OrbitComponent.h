#pragma once
#include <World/Component.h>

/// <summary>
/// Component class which behaves as a orbit around an another entity
/// </summary>
class OrbitComponent : public Component
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

