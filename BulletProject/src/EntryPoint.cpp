#include <World/World.h>
#include <World/Entity.h>
#include <Window/Window.h>
#include <Graphics/Shader/ShaderProgram.h>
#include <Resources/ShaderResources.h>
#include <World/Components/ObserverComponent.h>
#include <World/Components/RenderableComponent.h>
#include <World/Components/OrbitComponent.h>
#include <World/Components/SphereColliderComponent.h>
#include <World/Components/CameraMovement.h>
#include <World/Components/Spatial.h>
#include <Graphics/Mesh/SphereGenerator.h>
#include <World/Components/WeaponComponent.h>
#include <World/Components/ParentComponent.h>
#define CAMERA_SPEED 1
#define CAMERA_ROTATION 60
#define ORBIT_DISTANCE 3.0f
#define ORBIT_SPEED 1.0f
#define ROW_COUNT 5
#define COLUMN_COUNT 5
#define PARENT_PARENT_GAP 15.0f
#define CHILD_SPHERE_SIZE 1.1f
#define PARENT_SPHERE_SIZE 2
#define PARENT_COLOR glm::vec4(0.3f,0.8f,0.2f,1.0f)
#define CHILD_COLOR glm::vec4(0.2f,0.4f,0.9f,1.0f)
#define BULLET_COLOR glm::vec4(0.9,0.1f,0.1f,1.0f)
#define BULLET_SIZE 0.6f
#define BULLET_SPEED 3.0f

void GenerateSceneLayout(World* world)
{
	/*
	* Create resources
	*/
	GeneratedSphereContent sphereContent = SphereGenerator::GenerateSphere(3);
	Mesh* sphereMesh = new Mesh(sphereContent.Vertexes, sphereContent.Indexes);
	ShaderProgram* sphereProgram = new ShaderProgram(g_SphereVertexSource, g_SphereFragmentSource);

	/*
	* Generate single observer
	*/
	Entity* observerEntity = world->CreateEntity("Observer entity");
	ObserverComponent* observerComponent = observerEntity->AddComponent<ObserverComponent>();
	observerComponent->SetClearColor(glm::vec4(100 / 255.0f, 149 / 255.0f, 237 / 255.0f, 1.0f));
	observerEntity->GetSpatial()->SetPosition(glm::vec3(0.5f, 0, -55.0f));
	observerEntity->AddComponent<CameraMovement>(CAMERA_SPEED, CAMERA_ROTATION);
	observerEntity->AddComponent<WeaponComponent>(BULLET_SPEED,BULLET_SIZE,sphereMesh,sphereProgram,BULLET_COLOR);

	/*
	* Generate spheres
	*/
	for (unsigned int y = 0; y < COLUMN_COUNT; y++)
	{
		for (unsigned int x = 0; x < ROW_COUNT; x++)
		{
			/*
			* Generate offset
			*/
			const glm::vec3 offset = glm::vec3(x, 0, y) * PARENT_PARENT_GAP;

			/*
			* Create parent shpere entity
			*/
			Entity* parentEntity = world->CreateEntity("ParentEntity");
			parentEntity->GetSpatial()->SetScale(PARENT_SPHERE_SIZE);
			parentEntity->AddComponent<RenderableComponent>(sphereMesh, sphereProgram,PARENT_COLOR);
			parentEntity->AddComponent<SphereColliderComponent>(1.0f);
			parentEntity->GetSpatial()->SetPosition(offset);

			/*
			* Create child entites component
			*/
			Entity* childEntity0 = world->CreateEntity("ChildEntity0");
			childEntity0->GetSpatial()->SetPosition(offset + glm::vec3(1, 0, 0)*ORBIT_DISTANCE);
			childEntity0->GetSpatial()->SetScale(CHILD_SPHERE_SIZE);
			childEntity0->AddComponent<RenderableComponent>(sphereMesh, sphereProgram,CHILD_COLOR);
			OrbitComponent* child0 = childEntity0->AddComponent<OrbitComponent>(parentEntity,ORBIT_DISTANCE,ORBIT_SPEED,0);

			Entity* childEntity1 = world->CreateEntity("ChildEntity1");
			childEntity1->GetSpatial()->SetPosition(offset - glm::vec3(1, 0, 0) * ORBIT_DISTANCE);
			childEntity1->GetSpatial()->SetScale(CHILD_SPHERE_SIZE);
			childEntity1->AddComponent<RenderableComponent>(sphereMesh, sphereProgram, CHILD_COLOR);
			OrbitComponent* child1 = childEntity1->AddComponent<OrbitComponent>(parentEntity, ORBIT_DISTANCE, ORBIT_SPEED,180);

			/*
			* Create parent component
			*/
			parentEntity->AddComponent<ParentComponent>(child0,child1);

		}
	}
}
int main(int argumentCount, char** arguments)
{
	/*
	* Create window
	*/
	Window* window = new Window("Glut Application",
		100, 100,
		1280, 720,
		WindowCmdArgs(argumentCount,arguments));

	
	/*
	* Generate world
	*/
	World* world = new World(window);
	GenerateSceneLayout(world);
	

	/*
	* Application loop
	*/
	while (!window->HasCloseRequest())
	{
		/*
		* Update window events
		*/
		window->PollWindowEvents();

		/*
		* Execute world
		*/
		world->TickWorld();

		/*
		* Swapbuffers
		*/
		window->Swapbuffers();
	}
}
