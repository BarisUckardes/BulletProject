#pragma once
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

/// <summary>
/// Vertex data content for the sphere mesh
/// </summary>
struct MeshVertex
{
	MeshVertex(float positionX, float positionY, float positionZ, float normalX, float normalY, float normalZ, float uvX, float uvY)
	{
		Position = glm::vec3(positionX, positionY, positionZ);
		Normal = glm::vec3(normalX, normalY, normalZ);
		TextureCoordinate = glm::vec2(uvX, uvY);
	}
	MeshVertex(const glm::vec3& position,const glm::vec3& normal,const glm::vec2& textureCoordinate) : Position(position),Normal(normal),TextureCoordinate(textureCoordinate) {}

	MeshVertex() = default;

	/// <summary>
	/// Position of the vertex
	/// </summary>
	glm::vec3 Position;

	/// <summary>
	/// Normal direction to surface(Required for basic lighting)
	/// </summary>
	glm::vec3 Normal;

	/// <summary>
	/// Texture coordinate of the vertex(However this is not used in shaders)
	/// </summary>
	glm::vec2 TextureCoordinate;
};