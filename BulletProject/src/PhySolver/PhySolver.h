#pragma once
#include <Memory/Array.h>
class SphereColliderComponent;
class Entity;
struct CollisionReport
{
	Entity* Self;
	SphereColliderComponent* Other;
};
class PhySolver
{
	friend class World;
public:
	virtual void Solve(const Array<SphereColliderComponent*>& components, Array<CollisionReport>& collisionReports) = 0;
protected:
	PhySolver() = default;
	~PhySolver() = default;
};

