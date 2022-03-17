#pragma once

#include "common.h"
#include "mesh.h"
#include "object.h"
#include "scene.h"

class Render{
private:
    glm::mat4 view=glm::mat4(1.0f);
    glm::mat4 proj=glm::mat4(1.0f);
public:


    Render();
    void drawMesh(Mesh* mesh,glm::mat4 model);
    void drawObject(Object* obj);
    void drawScene(Scene* scene);
};


