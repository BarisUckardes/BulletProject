#pragma once
#include <Memory/Array.h>
#include <Graphics/Mesh/MeshVertex.h>

struct GeneratedSphereContent
{
	/// <summary>
	/// The vertexes of the generated sphere
	/// </summary>
	Array<MeshVertex> Vertexes;

	/// <summary>
	/// The indexes of the generated sphere
	/// </summary>
	Array<int> Indexes;
};

/// <summary>
/// Simple utility class which only generates a sphere mesh
/// </summary>
class SphereGenerator
{
public:
	SphereGenerator() = delete;
	~SphereGenerator() = delete;

	/// <summary>
	/// Generates an sphere mesh
	/// </summary>
	/// <param name="subdivisionCount"></param>
	/// <returns></returns>
	static GeneratedSphereContent GenerateSphere(unsigned int subdivisionCount);
};

