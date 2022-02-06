#pragma once
#include <World/Component.h>
#include <glm/vec3.hpp>

/// <summary>
/// The bullet component for spawned bullets
/// Once spawned this component's only job to determine if its too far from the center and destroy itself and move itself into the direction every frame
/// </summary>
class BulletComponent : public Component
{
public:
	BulletComponent(const glm::vec3& direction, float speed);

	virtual bool ShouldLogicTick() const override;
	virtual void OnLogicTick() override;
	virtual void OnCollision(SphereColliderComponent* other) override;
private:
	glm::vec3 m_Direction;
	float m_Speed;
};

