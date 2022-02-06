
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
#include <World/Components/WeaponComponent.h>
#include <World/Components/ParentComponent.h>
#include <Graphics/Mesh/ExternalGenerator.h>
#include <PhySolver/PhySolver.h>
#include <World/World.h>
#include <GL/glew.h>
#include <GL/freeglut.h>


/*
* Application parameters
*/
#define SPHERE_MESH_SUBDIVISION 3
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
#define BULLET_SPEED 0.1f


/*
* Global state variables
*/
Window* g_Window = nullptr;

struct GeneratedSphereContent
{
	/// <summary>
	/// The vertexes of the generated sphere
	/// </summary>
	Array<MeshVertex> Vertexes;

	/// <summary>
	/// The indexes of the generated sphere
	/// </summary>
	Array<int> Indexes;
};

GeneratedSphereContent MakeSphere(unsigned int subdivisionCount)
{
	/*
	* Generate shpere
	*/
	Array<MeshVertex> vertexes;
	Array<int> indexes;
	NormalizedMesh normalizedMesh;
	NormalizedCube(5, normalizedMesh);

	/*
	* Create normals
	*/
	for (int i = 0; i < normalizedMesh.vertices.GetCursor(); i++)
	{
		vertexes.Add(MeshVertex(normalizedMesh.vertices[i], normalizedMesh.vertices[i], glm::vec2(0)));
	}
	for (int i = 0; i < normalizedMesh.triangles.GetCursor(); i++)
	{
		int vector = normalizedMesh.triangles[i];
		indexes.Add(vector);
	}

	/*
	* Create UVS ? 
	*/

	/*
	* Create content
	*/
	GeneratedSphereContent content;
	content.Vertexes = vertexes;
	content.Indexes = indexes;
	return content;
}

World* InitializeWorldAndResources(Window* window)
{
	/*
	* Create world
	*/
	World* world = new World(window);

	/*
	* Generate sphere mesh
	*/
	GeneratedSphereContent sphereContent = MakeSphere(SPHERE_MESH_SUBDIVISION);

	/*
	* Create sphere mesh
	*/
	Mesh* sphereMesh = new Mesh(sphereContent.Vertexes, sphereContent.Indexes);

	/*
	* Create shader program
	*/
	ShaderProgram* sphereProgram = new ShaderProgram(g_SphereVertexSource, g_SphereFragmentSource);

	/*
	* Generate single observer
	*/
	Entity* observerEntity = world->CreateEntity("Observer entity");
	ObserverComponent* observerComponent = observerEntity->AddComponent<ObserverComponent>();
	observerComponent->SetClearColor(glm::vec4(100 / 255.0f, 149 / 255.0f, 237 / 255.0f, 1.0f));
	observerEntity->GetSpatial()->SetPosition(glm::vec3(0.5f, 0, -55.0f));
	observerEntity->AddComponent<CameraMovement>(CAMERA_SPEED, CAMERA_ROTATION);
	observerEntity->AddComponent<WeaponComponent>(BULLET_SPEED, BULLET_SIZE, sphereMesh, sphereProgram, BULLET_COLOR);

	/*
	* Spawn sphere entities
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
			parentEntity->AddComponent<RenderableComponent>(sphereMesh, sphereProgram, PARENT_COLOR);
			parentEntity->AddComponent<SphereColliderComponent>(1.0f);
			parentEntity->GetSpatial()->SetPosition(offset);

			/*
			* Create child entites component
			*/
			Entity* childEntity0 = world->CreateEntity("ChildEntity0");
			childEntity0->GetSpatial()->SetPosition(offset + glm::vec3(1, 0, 0) * ORBIT_DISTANCE);
			childEntity0->GetSpatial()->SetScale(CHILD_SPHERE_SIZE);
			childEntity0->AddComponent<RenderableComponent>(sphereMesh, sphereProgram, CHILD_COLOR);
			OrbitComponent* child0 = childEntity0->AddComponent<OrbitComponent>(parentEntity, ORBIT_DISTANCE, ORBIT_SPEED, 0);

			Entity* childEntity1 = world->CreateEntity("ChildEntity1");
			childEntity1->GetSpatial()->SetPosition(offset - glm::vec3(1, 0, 0) * ORBIT_DISTANCE);
			childEntity1->GetSpatial()->SetScale(CHILD_SPHERE_SIZE);
			childEntity1->AddComponent<RenderableComponent>(sphereMesh, sphereProgram, CHILD_COLOR);
			OrbitComponent* child1 = childEntity1->AddComponent<OrbitComponent>(parentEntity, ORBIT_DISTANCE, ORBIT_SPEED, 180);

			/*
			* Create parent component
			*/
			parentEntity->AddComponent<ParentComponent>(child0, child1);

		}
	}

	return world;
}

//the main rendering function
void RenderObjects(const Window* window,const Array<RenderableComponent*>& renderableObjects,const Array<ObserverComponent*> observers)
{
	/*
	* Get window properties
	*/
	const unsigned int width = window->GetWidth();
	const unsigned int height = window->GetHeight();

	/*
	* Iterate observers
	*/
	for (unsigned int observerIndex = 0; observerIndex < observers.GetCursor(); observerIndex++)
	{
		/*
		* Get observer
		*/
		const ObserverComponent* observer = observers[observerIndex];

		/*
		* Get observer properties
		*/
		const glm::vec4 clearColor = observer->GetClearColor();
		const glm::mat4x4 projectionMatrix = observer->GetProjectionMatrix();
		const glm::mat4x4 viewMatrix = observer->GetViewMatrix();

		/*
		* Bind framebuffer
		*/
		glBindFramebuffer(GL_FRAMEBUFFER, 0);

		/*
		* Clear framebuffer
		*/
		glClearColor(clearColor.x, clearColor.y, clearColor.z, 1.0f);
		glClearDepth(1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		/*
		* Set viewport
		*/
		glViewport(0, 0, width, height);

		/*
		* Iterate renderables
		*/
		for (unsigned int renderableIndex = 0; renderableIndex < renderableObjects.GetCursor(); renderableIndex++)
		{
			/*
			* Get renderable
			*/
			const RenderableComponent* renderable = renderableObjects[renderableIndex];

			/*
			* Get renderable properties
			*/
			const Mesh* mesh = renderable->GetMesh();
			const ShaderProgram* program = renderable->GetProgram();
			const glm::mat4x4 modelMatrix = renderable->GetSpatial()->GetModelMatrix();
			const glm::mat4x4 mvpMatrix = projectionMatrix * viewMatrix * modelMatrix;
			const glm::vec4 customColor = renderable->GetColor();
			const unsigned int vertexArrayIndex = mesh->GetVertexArrayIndex();
			const unsigned int vertexBufferIndex = mesh->GetVertexBufferIndex();
			const unsigned int indexBufferIndex = mesh->GetIndexBufferIndex();
			const unsigned int indexCount = mesh->GetIndexCount();
			const unsigned int programIndex = program->GetProgramIndex();

			/*
			* Bind mesh
			*/
			glBindVertexArray(vertexArrayIndex);
			glBindBuffer(GL_ARRAY_BUFFER, vertexBufferIndex);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferIndex);

			/*
			* Use program
			*/
			glUseProgram(programIndex);

			/*
			* Set shader uniforms(if any)
			*/
			glUniformMatrix4fv(
				glGetUniformLocation(programIndex, "v_Mvp"),
				1,
				GL_FALSE,
				&mvpMatrix[0][0]);
			glUniform4fv(glGetUniformLocation(programIndex, "f_Color"), 1, &customColor.x);

			/*
			* Issue draw call
			*/
			glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
		}
	}
}

void LogicTickObjects(const Array<Component*>& objects)
{
	/*
	* Iterate and invoke logic tick calls
	*/
	for (unsigned int i = 0; i < objects.GetCursor(); i++)
	{
		/*
		* Call logic callback
		*/
		objects[i]->OnLogicTick();
	}
}


void PhySolveObjects(const Array<SphereColliderComponent*>& colliderObjects)
{
	/*
	* Create array for collision reports
	*/
	Array<CollisionReport> collisionReports;

	/*
	* Iterate in a double iteration
	*/
	for (unsigned int selfIndex = 0; selfIndex < colliderObjects.GetCursor(); selfIndex++)
	{
		/*
		* Get self collider
		*/
		SphereColliderComponent* selfComponent = colliderObjects[selfIndex];

		/*
		* Get self sphere properties
		*/
		const glm::vec3 selfPosition = selfComponent->GetSpatial()->GetPosition();
		const float selfRadius = selfComponent->GetRadiusWorld();

		/*
		* Search for others
		*/
		for (unsigned int otherIndex = 0; otherIndex < colliderObjects.GetCursor(); otherIndex++)
		{
			/*
			* Validate self-self
			*/
			if (selfIndex == otherIndex)
				continue;

			/*
			* Get other collider
			*/
			SphereColliderComponent* otherComponent = colliderObjects[otherIndex];

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

	/*
	* Invoke collision callbacks
	*/
	for (unsigned int reportIndex = 0; reportIndex < collisionReports.GetCursor(); reportIndex++)
	{
		/*
		* Get report
		*/
		CollisionReport& report = collisionReports[reportIndex];

		/*
		* Get components
		*/
		Array<Component*> components = report.Self->GetComponents();

		/*
		* Iterate self entity components
		*/
		for (unsigned int componentIndex = 0; componentIndex < components.GetCursor(); componentIndex++)
		{
			/*
			* Invoke callback
			*/
			components[componentIndex]->OnCollision(report.Other);
		}

	}
}

void g_OnDisplay()
{

}

void g_OnWindowResized(int width, int height)
{
	g_Window->OnWindowResized(width, height);
}

void g_OnKey(unsigned char key, int a, int b)
{
	g_Window->OnKeyPress(key);
}

void g_OnKeyUp(unsigned char key, int a, int b)
{
	g_Window->OnKeyUp(key);
}

void g_OnMouse(int button, int state, int x, int y)
{
	/*
	* Catch supported states
	*/
	if (state == GLUT_DOWN)
	{
		g_Window->OnMouseButtonDown(button);
	}
	else if (state == GLUT_UP)
	{
		g_Window->OnMouseButtonUp(button);
	}
	g_Window->OnMouseMove(x, y);
}

void g_OnMouseMove(int x, int y)
{
	g_Window->OnMouseMove(x, y);
}

void g_OnIdle()
{
	/*
	* While on idle state you must still set mouse move event callback
	*/
	const int x = g_Window->GetMouseX();
	const int y = g_Window->GetMouseY();
	g_Window->OnMouseMove(x, y);
}

int main(int argc, char** argv)
{
	/*
	* Create window (Initializes both glut window and glew context)
	*/
	Window* window = new Window("Sphere Lab", 0, 0, 1280, 720, WindowCmdArgs(argc, argv), false);
	g_Window = window;

	/*
	* Set glut event callback
	*/
	glutIdleFunc(g_OnIdle);
	glutDisplayFunc(g_OnDisplay);
	glutMouseFunc(g_OnMouse);
	glutPassiveMotionFunc(g_OnMouseMove);
	glutMotionFunc(g_OnMouseMove);

	glutKeyboardFunc(g_OnKey);
	glutKeyboardUpFunc(g_OnKeyUp);

	glutReshapeFunc(g_OnWindowResized);

	/*
	* Create resources
	*/
	World* world = InitializeWorldAndResources(window);

	while (!window->HasCloseRequest())
	{
		/*
		* Poll window events
		*/
		window->PollWindowEvents();

		/*
		* Run world procedures
		*/
		PhySolveObjects(world->GetCollisionObjects());
		LogicTickObjects(world->GetLogicTickableObjects());
		world->DeleteMarkedEntities();
		RenderObjects(window,world->GetRenderableObjects(),world->GetObserverObjects());

		/*
		* Swapbuffers
		*/
		window->Swapbuffers();
	}

	return 0;
}
