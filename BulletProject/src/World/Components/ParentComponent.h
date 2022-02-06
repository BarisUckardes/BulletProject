#pragma once
#include <World/Component.h>

class OrbitComponent;

/// <summary>
/// The parent sphere for the other two child spheres
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

