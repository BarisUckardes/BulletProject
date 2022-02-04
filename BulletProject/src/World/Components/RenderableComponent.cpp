#include "RenderableComponent.h"
#include <World/World.h>
#include <World/Entity.h>
RenderableComponent::RenderableComponent(Mesh* mesh, ShaderProgram* program,const glm::vec4& color)
{
    m_Mesh = mesh;
    m_Program = program;
    m_CustomColor = color;
}

Mesh* RenderableComponent::GetMesh() const
{
    return m_Mesh;
}

ShaderProgram* RenderableComponent::GetProgram() const
{
    return m_Program;
}

glm::vec4 RenderableComponent::GetColor() const
{
    return m_CustomColor;
}

void RenderableComponent::OnInitialize()
{
    Component::OnInitialize();
    GetOwnerEntity()->GetOwnerWorld()->RegisterRenderableComponent(this);
}

void RenderableComponent::OnDestroyed()
{
    GetOwnerEntity()->GetOwnerWorld()->RemoveRenderableComponent(this);
}

