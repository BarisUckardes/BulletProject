#pragma once
#include <World/Component.h>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

/// <summary>
/// A component which holds the camera information
/// </summary>
class ObserverComponent : public Component
{
public:
	virtual bool ShouldLogicTick() const override  { return false; }

	/// <summary>
	/// Returns the projection matrix
	/// </summary>
	/// <returns></returns>
	FORCEINLINE glm::mat4x4 GetProjectionMatrix() const;

	/// <summary>
	/// Returns the view matrix
	/// </summary>
	/// <returns></returns>
	FORCEINLINE glm::mat4x4 GetViewMatrix() const;

	/// <summary>
	/// Returns the clear color
	/// </summary>
	/// <returns></returns>
	FORCEINLINE glm::vec4 GetClearColor() const;

	/// <summary>
	/// Returns the near clip
	/// </summary>
	/// <returns></returns>
	FORCEINLINE float GetNearClip() const;

	/// <summary>
	/// Returns the far clip
	/// </summary>
	/// <returns></returns>
	FORCEINLINE float GetFarClip() const;

	/// <summary>
	/// Returns the fieldofview
	/// </summary>
	/// <returns></returns>
	FORCEINLINE float GetFieldForView() const;
	

	/// <summary>
	/// Sets the near clip
	/// </summary>
	/// <param name="value"></param>
	void SetNearClip(float value);

	/// <summary>
	/// Sets the far clip
	/// </summary>
	/// <param name="value"></param>
	void SetFarClip(float value);

	/// <summary>
	/// Sets the field of view in angles
	/// </summary>
	/// <param name="value"></param>
	void SetFieldOfView(float angles);

	/// <summary>
	/// Sets the clear color
	/// </summary>
	/// <param name="color"></param>
	void SetClearColor(const glm::vec4& color);
private:
	glm::vec4 m_ClearColor;
	float m_NearClip;
	float m_FarClip;
	float m_FieldOfView; // in angles
};

