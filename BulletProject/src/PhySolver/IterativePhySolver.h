#pragma once
#include <PhySolver/PhySolver.h>

class IterativePhySolver : public PhySolver
{
public:
	IterativePhySolver() = default;
	~IterativePhySolver() = default;

	virtual void Solve(const Array<SphereColliderComponent*>& components, Array<CollisionReport>& collisionReports) override;
}; 

