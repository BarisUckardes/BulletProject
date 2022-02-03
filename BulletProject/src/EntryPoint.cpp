#include <World/World.h>
#include <World/Entity.h>
#include <Window/Window.h>
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
	* Create world and its inhabitants
	*/
	World* world = new World(window);

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
