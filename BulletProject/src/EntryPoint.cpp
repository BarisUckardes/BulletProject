#include <World/World.h>
#include <World/Entity.h>
#include <Window/Window.h>
#include <Graphics/Shader/ShaderProgram.h>
#include <Resources/ShaderResources.h>
#include <World/Components/ObserverComponent.h>
#include <World/Components/RenderableComponent.h>
#include <World/Components/OrbitComponent.h>
#include <World/Components/SphereColliderComponent.h>
#include <World/Components/Spatial.h>
#define ORBIT_DISTANCE 30.0f
#define ORBIT_SPEED 5.0f
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
	* Create resources
	*/
	Array<MeshVertex> vertexes;
	vertexes.Reserve(4);
	vertexes.Add(MeshVertex(1.0f, -1.0f, 0,0,0,0, 0, 0));
	vertexes.Add(MeshVertex(-1.0f, -1.0f, 0,0,0,0, 1, 0));
	vertexes.Add(MeshVertex(-1.0f, 1.0f, 0,0,0,0, 1, 1));
	vertexes.Add(MeshVertex(1.0f, 1.0f, 0,0,0,0, 0, 1));
	Array<int> indexes;
	indexes.Add(0);
	indexes.Add(2);
	indexes.Add(1);
	indexes.Add(0);
	indexes.Add(2);
	indexes.Add(3);

	Mesh* sphereMesh = new Mesh(vertexes,indexes);
	ShaderProgram* sphereProgram = new ShaderProgram(g_SphereVertexSource, g_SphereFragmentSource);

	/*
	* Create world and its inhabitants
	*/
	World* world = new World(window);
	Entity* observerEntity = world->CreateEntity("Observer entity");
	ObserverComponent* observerComponent = observerEntity->AddComponent<ObserverComponent>();
	observerComponent->SetClearColor(glm::vec4(100/255.0f, 149/255.0f, 237 / 255.0f, 1.0f));
	observerEntity->GetSpatial()->SetPosition(glm::vec3(0.5f,0,-15.0f));
	

	Entity* sphereEntity = world->CreateEntity("Sphere entity");
	sphereEntity->GetSpatial()->SetScale(3.5f);
	sphereEntity->AddComponent<RenderableComponent>(sphereMesh, sphereProgram);

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
