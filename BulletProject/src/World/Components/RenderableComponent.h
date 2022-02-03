#pragma once
#include <World/Component.h>

class RenderableComponent : public Component
{
public:
	virtual bool ShouldLogicTick() const override { return false; }
};

