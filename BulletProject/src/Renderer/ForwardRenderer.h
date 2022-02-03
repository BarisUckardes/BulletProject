#pragma once
#include <Renderer/Renderer.h>
class ForwardRenderer : public Renderer
{
public:
	ForwardRenderer() = default;
	~ForwardRenderer() = default;


	// Inherited via Renderer
	virtual void Render(const Array<RenderableComponent*>& renderables, const Array<ObserverComponent*>& observerComponents) override;

};

