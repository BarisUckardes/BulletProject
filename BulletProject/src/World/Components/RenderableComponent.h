#pragma once
#include <World/Component.h>
#include <Graphics/Mesh/Mesh.h>
#include <Graphics/Shader/ShaderProgram.h>
#include <glm/vec4.hpp>

/// <summary>
/// Represents a renderable component
/// Registers itself to world's rendering objects once its created
/// </summary>
class EXPORT RenderableComponent : public Component
{
public:
	RenderableComponent(Mesh* mesh, ShaderProgram* program,const glm::vec4& color);
	

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

	/// <summary>
	/// Returns the custom color of this renderable
	/// </summary>
	/// <returns></returns>
	FORCEINLINE glm::vec4 GetColor() const;

	virtual bool ShouldLogicTick() const override { return false; }
	virtual void OnInitialize() override;
	virtual void OnDestroyed() override;

private:
	ShaderProgram* m_Program;
	Mesh* m_Mesh;
	glm::vec4 m_CustomColor;
};

