//
// Created by drew on 7/2/22.
//

#include "render.h"

Render::Render(){

}


void Render::setupObject(Object* obj){

    bufferObject_t bo;
    glGenVertexArrays(1,&bo.abo);
    glBindVertexArray(bo.abo);

    glGenBuffers(1, &bo.vbo);
    glGenBuffers(1, &bo.ibo);

    glBindBuffer(GL_ARRAY_BUFFER,bo.vbo);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertex_t)*obj->mesh->vertexList->size(),
                 obj->mesh->vertexList->data(),GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,bo.vbo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(vertex_t)*obj->mesh->vertexList->size(),
                 obj->mesh->vertexList->data(),GL_STATIC_DRAW);

    boList[obj->id]=bo;
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

void Render::drawObjectGL4(Object *obj) {
    obj->computeMatrix();
    bufferObject_t bo = boList[obj->id];

    glBindVertexArray(bo.abo);
    glBindBuffer(GL_ARRAY_BUFFER, bo.vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bo.ibo);

    glUseProgram(obj->shader->programID);
    unsigned int vpos =0;
    glEnableVertexAttribArray(vpos);
    glVertexAttribPointer(vpos,4,GL_FLOAT,GL_FALSE,sizeof(vertex_t),(void*)0);

    unsigned int vcolor =1;
    glEnableVertexAttribArray(vcolor);
    glVertexAttribPointer(vpos,4,GL_FLOAT,GL_FALSE,sizeof(vertex_t),(void*)(sizeof(glm::vec4)));

    glUniformMatrix4fv(0,1,GL_FALSE,obj->getMatrix()[0][0]);

    glDrawElements(GL_TRIANGLES, obj->mesh->faceList->size(),GL_UNSIGNED_INT, nullptr);
}

void Render::drawScene(Scene* scene) {

    Camera* cam = scene->getCamera();
    std::map<int, Object*> *addedObjectList=scene->addedObjectList;

    for (auto it = addedObjectList->begin(); it != addedObjectList->end(); it++){
        setupObject(it->second);
    }

    cam->computeMatrix();
    view=cam->getMatrix();
    proj=cam->getProjectionMatrix();
    std::map<int, Object*>* objList = scene->getObjList();

    for(auto it = objList->begin();
        it!=objList->end(); it++){
        drawObject(it->second);
    }
}