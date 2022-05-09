#include <iostream>
#include "common.h"
#include <vector>
#include "mesh.h"
#include "render.h"
#include "object.h"
#include "scene.h"
#include "inputManager.h"
#include "spaceShip.h"
#include "system.h"
#include "background.h"

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

	GLFWwindow* window = glfwCreateWindow(640,480,"Prueba 1 GLFW",nullptr,nullptr);
	glfwMakeContextCurrent(window);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	
	int glewState=glewInit();
	
	if (glewState!=GLEW_OK)
		std::cout << "ERROR iniciando glew\n";

	InputManager::init(window);

    Object* background = new Background("background.trg");
    background->position.z = -5.0f;
//    background->scale=glm::vec3(15.0f,15.0f,15.0f);

	Object* player=new SpaceShip("triangle.trg");
	player->scale=glm::vec3(0.3f,0.3f,0.3f);
	player->position.y=-0.8f;


    Object* enemy = new Enemy("triangle.trg");
    enemy->scale=glm::vec3(0.3f,0.3f,0.3f);
    enemy->rotation.z=glm::radians(180.0f);
//    enemy->rotation.x=glm::radians(180.0f);
    enemy->position.y=0.8f;


	Render* render=new Render();
	Scene* scene=new Scene();

	System::scene=scene;
	scene->setCamera(new Camera(glm::vec3(0,0,1.0f),glm::vec3(0,0,0),perspective));

    scene->addObject(background);
    render->setupObject(background);

    scene->addObject(enemy);
    render->setupObject(enemy);

	scene->addObject(player);
	render->setupObject(player);



//CUBO
/*	Object* cube=new Cube("cube.trg");
	//cube->scale=glm::vec3(0.5f,0.5f,0.5f);
	cube->position.z=3.0f;

	render->setupObject(cube);
	scene->addObject(cube);*/

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
