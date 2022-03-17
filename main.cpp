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
#include "enemy.h"


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
    Object* triangle = new SpaceShip("triangle.trg");
    triangle->scale=glm::vec3(0.1,0.1,0.1);
    triangle->position.y=-0.35;

    Object* enemy = new Enemy("triangle.trg");
    enemy->scale=glm::vec3(0.1,0.1,0.1);
    enemy->position.y=0.35;

    Render* render = new Render();
    Scene* scene = new Scene();
    System::scene=scene;
    scene->setCamera(new Camera(glm::vec3(0,0,0.25f),glm::vec3(0,0,0),perspective));
    scene->addObject(triangle);
    scene->addObject(enemy);

    while(!glfwWindowShouldClose(window))

    {
        scene->step(0.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        render->drawScene(scene);
        glfwSwapBuffers(window);
        glfwPollEvents();

    }


    delete triangle;

    return 0;


}
