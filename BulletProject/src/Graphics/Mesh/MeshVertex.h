#pragma once
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

struct MeshVertex
{
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