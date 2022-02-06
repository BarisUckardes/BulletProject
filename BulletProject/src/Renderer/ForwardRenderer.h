#pragma once
#include <Renderer/Renderer.h>

/// <summary>
/// The renderer of this applications.
/// Simple renderer which iterates the renderable objects in the scene and renders them
/// </summary>
class ForwardRenderer : public Renderer
{
public:
	ForwardRenderer() = default;
	~ForwardRenderer() = default;



	virtual void Render(const Array<RenderableComponent*>& renderables, const Array<ObserverComponent*>& observerComponents) override;

};

