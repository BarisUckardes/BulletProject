#pragma once
#include <Core/Symbols.h>
#include <Memory/Array.h>
#include <Graphics/Mesh/MeshVertex.h>
struct GeneratedSphereContent;

/// <summary>
/// Contains the opengl handles for a mesh
/// Vertex Arrays,Vertex buffers and index buffers all bundled here
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

	/// <summary>
	/// Returns vertex count
	/// </summary>
	/// <returns></returns>
	FORCEINLINE unsigned int GetIndexCount() const;
private:
	unsigned int m_VertexArrayIndex;
	unsigned int m_VertexBufferIndex;
	unsigned int m_IndexBufferIndex;
	unsigned int m_IndexCount;
};

