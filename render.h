#pragma once

#include "common.h"
#include "mesh.h"
#include "object.h"
#include "scene.h"

typedef struct bufferObject_t{
    unsigned int abo; //array buffer obect ID
    unsigned int vbo; //vertex buffer obect
    unsigned int ibo; //idx bufferObject
}bufferObject_t;

class Render{
private:
    glm::mat4 view=glm::mat4(1.0f);
    glm::mat4 proj=glm::mat4(1.0f);
    std::map<int, bufferObject_t> boList; //TODO esto no reutiliza la malla cambiarlo para que la reutilice
public:


    Render();
    void setupObject(Object* obj);
    void drawMesh(Mesh* mesh,glm::mat4 model);
    void drawObject(Object* obj);
    void drawObjectGL4(Object *obj);
    void drawScene(Scene* scene);
};


