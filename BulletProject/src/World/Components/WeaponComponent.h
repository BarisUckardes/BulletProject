#pragma once
#include <World/Component.h>
#include <glm/vec4.hpp>
class Mesh;
class ShaderProgram;

/// <summary>
/// A scripting component which behaves like a weapon
/// It listens the inputs and fires projectes on click
/// </summary>
class WeaponComponent : public Component
{
public:
	WeaponComponent(float bulletSpeed, float bulletSize, Mesh* bulletMesh, ShaderProgram* bulletProgram,const glm::vec4& color);

	virtual bool ShouldLogicTick() const override;
	virtual void OnLogicTick() override;
private:
	glm::vec4 m_Color;
	float m_BulletSpeed;
	float m_BulletSize;
	bool m_bHold;
	Mesh* m_Mesh;
	ShaderProgram* m_Program;
};

