#include "RenderableComponent.h"
#include <World/World.h>
#include <World/Entity.h>
RenderableComponent::RenderableComponent(Mesh* mesh, ShaderProgram* program)
{
    m_Mesh = mesh;
    m_Program = program;
}

Mesh* RenderableComponent::GetMesh() const
{
    return m_Mesh;
}

ShaderProgram* RenderableComponent::GetProgram() const
{
    return m_Program;
}

void RenderableComponent::OnInitialize()
{
    Component::OnInitialize();
    GetOwnerEntity()->GetOwnerWorld()->RegisterRenderableComponent(this);
}

