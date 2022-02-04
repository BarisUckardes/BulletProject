#pragma once
#include <World/Component.h>
#include <glm/vec3.hpp>
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

