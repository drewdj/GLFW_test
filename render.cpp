//
// Created by drew on 7/2/22.
//

#include "render.h"

Render::Render(){

}

void Render::drawMesh(Mesh* mesh,glm::mat4 model){
    int numFaces = mesh->faceList->size()/3;
    for(int i=0;i<numFaces;i++) {

        glBegin(GL_TRIANGLES);
        glm::vec4 newPos;


        for (int idV=i*3; idV<i*3+3; idV++) {

            vertex_t v = mesh->vertexList->data()[mesh->faceList->data()[idV]];
            newPos = proj * view * model * v.posicion;
            glColor3f(v.color.r, v.color.g, v.color.b);
            glVertex3f(newPos.x, newPos.y, newPos.z);

        }

        glEnd();
    }
}

void Render::drawObject(Object *obj) {
    obj->computeMatrix();
    drawMesh(obj->mesh,obj->getMatrix());
}

void Render::drawScene(Scene* scene) {

    Camera* cam = scene->getCamera();

    cam->computeMatrix();
    view=cam->getMatrix();
    proj=cam->getProjectionMatrix();
    std::map<int, Object*>* objList = scene->getObjList();

    for(auto it = objList->begin();
        it!=objList->end(); it++){
        drawObject(it->second);
    }
}