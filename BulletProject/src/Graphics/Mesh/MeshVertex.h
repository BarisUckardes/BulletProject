#pragma once
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

struct MeshVertex
{
	MeshVertex(float positionX, float positionY, float positionZ, float normalX, float normalY, float normalZ, float uvX, float uvY)
	{
		Position = glm::vec3(positionX, positionY, positionZ);
		Normal = glm::vec3(normalX, normalY, normalZ);
		TextureCoordinate = glm::vec2(uvX, uvY);
	}
	MeshVertex() = default;
	/// <summary>
	/// Position of the vertex
	/// </summary>
	glm::vec3 Position;

	/// <summary>
	/// Normal direction to surface
	/// </summary>
	glm::vec3 Normal;

	/// <summary>
	/// Texture coordinate of the vertex
	/// </summary>
	glm::vec2 TextureCoordinate;
};