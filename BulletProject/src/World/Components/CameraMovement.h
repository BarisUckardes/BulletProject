#pragma once
#include <World/Component.h>

/// <summary>
/// A component which is responsible for the camera movement
/// It listens to inputs and roams in the world.
/// To rotate your camera you must first clikc and hold right mouse button to unlock rotating
/// </summary>
class CameraMovement : public Component
{
public:
	CameraMovement(float movementSpeed, float rotateSpeed);
	~CameraMovement() = default;

	virtual void OnLogicTick() override;
	virtual bool ShouldLogicTick() const override;
private:
	int m_MouseClickPositionX;
	int m_MouseClickPositionY;
	int m_CurrentX;
	int m_CurrentY;
	float m_DeltaX;
	float m_DeltaY;
	float m_MovementSpeed;
	float m_RotateSpeed;
	bool m_bNavigating;
};

