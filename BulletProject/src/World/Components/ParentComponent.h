#pragma once
#include <World/Component.h>

class OrbitComponent;

/// <summary>
/// Parent component for managing the child components
/// </summary>
class ParentComponent : public Component
{
public:
	ParentComponent(OrbitComponent* child0, OrbitComponent* child1);
	virtual bool ShouldLogicTick() const override;

	/// <summary>
	/// Called when get thits by a bullet
	/// </summary>
	void DestoryChildOrSelf();
private:
	Array<OrbitComponent*> m_Childs;
};

