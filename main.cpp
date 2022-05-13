#include <iostream>
#include "common.h"
#include <vector>
#include "mesh.h"
#include "render.h"
#include "object.h"
#include "scene.h"
#include "inputManager.h"
#include "spaceShip.h"
#include "health.h"
#include "system.h"
#include "background.h"
#include "moveBackground.h"

#include "enemy.h"
#include "cube.h"




bool renderfps(double framerate)
{
	static double currentTime = 0;
	static double lastTime=0;

	currentTime = glfwGetTime();
	if(currentTime - lastTime >= 1.0 / framerate)
	{
		lastTime = currentTime;
		return true;
	}
	return false;
}


int main(int argc, char** argv)
{

	int glfwState=glfwInit();
	if (!glfwState)
		std::cout << "ERROR iniciando glfw\n";

	GLFWwindow* window = glfwCreateWindow(1920,1080,"Prueba 1 GLFW",glfwGetPrimaryMonitor(),nullptr);
	glfwMakeContextCurrent(window);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);


	int glewState=glewInit();

	if (glewState!=GLEW_OK)
		std::cout << "ERROR iniciando glew\n";

	InputManager::init(window);


    Object* background = new Background("background.trg");
    background->position.z = -9.0f;
    background->rotation.z = glm::radians(180.0f);
    background->rotation.y = glm::radians(180.0f);
    background->scale=glm::vec3(11.0f,11.0f,11.0f);

    Object* machine = new Background("machine.trg");
    machine->position.y = -0.25f;
    machine->position.x = 0.1f;
    machine->rotation.z = glm::radians(180.0f);
    machine->rotation.y = glm::radians(180.0f);
    machine->scale=glm::vec3(0.9f,0.9f,0.9f);

    Object* people = new MoveBackground("people.trg");
    people->position.z = -5.0f;
    people->position.y = 0.0f;
    people->rotation.z = glm::radians(180.0f);
    people->rotation.y = glm::radians(180.0f);
    people->scale=glm::vec3(11.0f,11.0f,11.0f);

    Object* machineBack = new Background("machineBack.trg");
    machineBack->position.z = -0.1;
    machineBack->position.y = -0.3f;
    machineBack->position.x = 0.105f;
    machineBack->rotation.z = glm::radians(180.0f);
    machineBack->rotation.y = glm::radians(180.0f);
//    machineBack->scale=glm::vec3(0.9f,0.9f,0.9f);


    Object* enemy = new Enemy("hook.trg");  //TODO la bala sale detras del enemigo y delande del jugador ajustar
    enemy->position.z = -0.05f;
    enemy->scale=glm::vec3(0.1f,0.1f,0.1f);
    enemy->rotation.z=glm::radians(180.0f);
    enemy->position.y=0.57f;

	Object* player=new SpaceShip("triangle.trg");
	player->scale=glm::vec3(0.1f,0.1f,0.1f);
    player->position.z = -0.05f;
	player->position.y=-0.335f;

    Object* health=new Health("health.trg");
    health->scale=glm::vec3(0.3f,0.3f,0.3f);
//    health->position.z=-0.10f;
    health->position.x=1.1f;
    health->position.y=-0.8f;


	Render* render=new Render();
	Scene* scene=new Scene();

	System::scene=scene;
	scene->setCamera(new Camera(glm::vec3(0,0,1.0f),glm::vec3(0,0,0),perspective));


    scene->addObject(background);
    render->setupObject(background);

    scene->addObject(machine);
    render->setupObject(machine);


    scene->addObject(machineBack);
    render->setupObject(machineBack);

    scene->addObject(enemy);
    render->setupObject(enemy);

	scene->addObject(player);
	render->setupObject(player);

    scene->addObject(health);
    render->setupObject(health);

    scene->addObject(people);
    render->setupObject(people);


//CUBO
//	Object* cube=new Cube("cube.trg");
//	cube->scale=glm::vec3(0.5f,0.5f,0.5f);
//	cube->position.z=-1.0f;
//
//	render->setupObject(cube);
//	scene->addObject(cube);

	while(!glfwWindowShouldClose(window))
	{

		if(renderfps(60.0f)){
			scene->step(0.0);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				render->drawScene(scene);
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}

//	delete triangle;
	return 0;

}
