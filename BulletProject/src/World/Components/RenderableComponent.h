#pragma once
#include <World/Component.h>
#include <Graphics/Mesh/Mesh.h>
#include <Graphics/Shader/ShaderProgram.h>
/// <summary>
/// Represents a renderable component
/// </summary>
class EXPORT RenderableComponent : public Component
{
public:
	RenderableComponent(Mesh* mesh, ShaderProgram* program);
	

	/// <summary>
	/// Returns the mesh
	/// </summary>
	/// <returns></returns>
	FORCEINLINE Mesh* GetMesh() const;

	/// <summary>
	/// Returns the shader program
	/// </summary>
	/// <returns></returns>
	FORCEINLINE ShaderProgram* GetProgram() const;

	virtual bool ShouldLogicTick() const override { return false; }
	virtual void OnInitialize() override;
private:
	ShaderProgram* m_Program;
	Mesh* m_Mesh;
};

