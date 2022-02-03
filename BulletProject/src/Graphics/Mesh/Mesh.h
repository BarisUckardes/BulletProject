#pragma once
#include <Core/Symbols.h>
#include <Memory/Array.h>
#include <Graphics/Mesh/MeshVertex.h>
struct GeneratedSphereContent;

/// <summary>
/// Represents a mesh and its OpenGL handles
/// </summary>
class EXPORT Mesh
{
public:
	Mesh(const Array<MeshVertex>& vertexes,const Array<int>& indexes);
	~Mesh();

	/// <summary>
	/// Returns the vertex array handle
	/// </summary>
	/// <returns></returns>
	FORCEINLINE unsigned int GetVertexArrayIndex() const;

	/// <summary>
	/// Returns the vertex buffer handle
	/// </summary>
	/// <returns></returns>
	FORCEINLINE unsigned int GetVertexBufferIndex() const;

	/// <summary>
	/// Returns the index buffer handle
	/// </summary>
	/// <returns></returns>
	FORCEINLINE unsigned int GetIndexBufferIndex() const;
private:
	unsigned int m_VertexArrayIndex;
	unsigned int m_VertexBufferIndex;
	unsigned int m_IndexBufferIndex;
};

