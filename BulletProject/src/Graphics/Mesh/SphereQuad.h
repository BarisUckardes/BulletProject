#pragma once

#include<glm/vec3.hpp>

/// <summary>
/// Represents a minimal information to generate a quad face
/// </summary>
struct SphereQuad
{
	SphereQuad(const glm::vec3& center, const glm::vec3& upVector, const glm::vec3& rightVector, float halfExtent) : Center(center),UpVector(upVector),RightVector(rightVector),HalfExtent(halfExtent) {}
	SphereQuad() = default;
	/// <summary>
	/// Center of the quad
	/// </summary>
	glm::vec3 Center;

	/// <summary>
	/// Up direction of the quad
	/// </summary>
	glm::vec3 UpVector;

	/// <summary>
	/// Right direction of the quad
	/// </summary>
	glm::vec3 RightVector;

	/// <summary>
	/// The extent from the center to vertexes
	/// </summary>
	float HalfExtent;
};