#pragma once
#include <Memory/Array.h>
class SphereColliderComponent;
class Entity;

/// <summary>
/// A report which consists of an entity which gets hit and the other entity which hit it
/// </summary>
struct CollisionReport
{
	/// <summary>
	/// The entity which gets hit
	/// </summary>
	Entity* Self;

	/// <summary>
	/// The entity which hit the entity
	/// </summary>
	SphereColliderComponent* Other;
};

/// <summary>
/// Basic interface class for creation more than one phySolver implemntations
/// </summary>
class PhySolver
{
	friend class World;
public:

	/// <summary>
	/// Calls the derived class phySolve implementaions
	/// </summary>
	/// <param name="components"></param>
	/// <param name="collisionReports"></param>
	virtual void Solve(const Array<SphereColliderComponent*>& components, Array<CollisionReport>& collisionReports) = 0;
protected:
	PhySolver() = default;
	~PhySolver() = default;
};

