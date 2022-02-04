#pragma once
#include <World/Component.h>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
/// <summary>
/// A component which holds spatial information
/// </summary>
class EXPORT Spatial : public Component
{
public:
	Spatial();
	~Spatial() = default;

	/// <summary>
	/// Returns the position of the entity
	/// </summary>
	/// <returns></returns>
	FORCEINLINE glm::vec3 GetPosition() const;

	/// <summary>
	/// Returns the rotation of the entity
	/// </summary>
	/// <returns></returns>
	FORCEINLINE glm::vec3 GetRotation() const;

	/// <summary>
	/// Returns the scale of the entity
	/// </summary>
	/// <returns></returns>
	FORCEINLINE float GetScale() const;

	/// <summary>
	/// Returns the forward vector for this entity
	/// </summary>
	/// <returns></returns>
	FORCEINLINE glm::vec3 GetForwardVector() const;

	/// <summary>
	/// Returns the right vector for this entity
	/// </summary>
	/// <returns></returns>
	FORCEINLINE glm::vec3 GetRightVector() const;

	/// <summary>
	/// Sets the position of the entity
	/// </summary>
	/// <param name="position"></param>
	void SetPosition(const glm::vec3& position);

	/// <summary>
	/// Sets the rotation of the entity
	/// </summary>
	/// <param name="rotation"></param>
	void SetRotation(const glm::vec3& rotation);

	/// <summary>
	/// Sets the scale of the entity
	/// </summary>
	/// <param name="scale"></param>
	void SetScale(float scale);

	virtual bool ShouldLogicTick() const override;

	/// <summary>
	/// Returns the model matrix for the entity
	/// </summary>
	/// <returns></returns>
	FORCEINLINE glm::mat4x4 GetModelMatrix() const;
private:
	glm::vec3 m_Position;
	glm::vec3 m_Rotation;
    float m_Scale;
};

