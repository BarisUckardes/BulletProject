#pragma once
#include <World/Component.h>
class CameraMovement : public Component
{
public:
	CameraMovement(float movementSpeed, float rotateSpeed);
	~CameraMovement() = default;

	virtual void OnLogicTick() override;
	virtual bool ShouldLogicTick() const override;
private:
	float m_MovementSpeed;
	float m_RotateSpeed;
};

