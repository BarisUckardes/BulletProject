#include "IterativePhySolver.h"
#include <World/Components/SphereColliderComponent.h>
#include <World/Entity.h>
#include <World/Components/Spatial.h>
void IterativePhySolver::Solve(const Array<SphereColliderComponent*>& components, Array<CollisionReport>& collisionReports)
{
	/*
	* Iterate in a double iteration
	*/
	for (unsigned int selfIndex = 0; selfIndex < components.GetCursor(); selfIndex++)
	{
		/*
		* Get self collider
		*/
		SphereColliderComponent* selfComponent = components[selfIndex];

		/*
		* Get self sphere properties
		*/
		const glm::vec3 selfPosition = selfComponent->GetSpatial()->GetPosition();
		const float selfRadius = selfComponent->GetRadiusWorld();

		/*
		* Search for others
		*/
		for (unsigned int otherIndex = 0; otherIndex < components.GetCursor(); otherIndex++)
		{
			/*
			* Validate self-self
			*/
			if (selfIndex == otherIndex)
				continue;

			/*
			* Get other collider
			*/
			SphereColliderComponent* otherComponent = components[otherIndex];

			/*
			* Get other sphere properties
			*/
			const glm::vec3 otherPosition = otherComponent->GetSpatial()->GetPosition();
			const float otherRadius = otherComponent->GetRadiusWorld();

			/*
			* Get collision properties
			*/
			const float checkDiameter = selfRadius + otherRadius;
			const float distance = glm::distance(otherPosition, selfPosition);

			/*
			* Check if there is a collision
			*/
			if (distance <= checkDiameter)
			{
				CollisionReport report;
				report.Self = selfComponent->GetOwnerEntity();
				report.Other = otherComponent;
				collisionReports.Add(report);
			}
		}
	}
}
