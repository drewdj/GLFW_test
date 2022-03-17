#include "scene.h"

Scene::Scene() {
    objList = new std::map<int, Object*>();
    addedObjList = new std::map<int, Object*>();
}

void Scene::setCamera(Camera* cam) {
    this->cam = cam;
}

Camera* Scene::getCamera() {
    return cam;
}

void Scene::addObject(Object* obj) {
    (*addedObjList)[obj->id] = obj;
    obj->computeMatrix();
}

void Scene::deleteObject(Object* obj) {
    auto it = objList->find(obj->id);
    it->second->markedDelete = true;
}

std::map<int, Object*> *Scene::getObjList() {
    return objList;
}

void Scene::step(double timeStep) {
    for (auto it = addedObjList->begin();
         it != addedObjList->end(); it++) {
        (*objList)[it->first] = it->second;
    }
    addedObjList->clear();

    for (auto it = objList->begin();
         it != objList->end(); it++) {
        it->second->updateCollider();
    }

    cam->step();
    for (auto it = objList->begin();
         it != objList->end(); it++) {
        //it->second->computeMatrix();
        it->second->step();
    }

    for (auto it = objList->begin();
         it != objList->end();) {
        if (it->second->markedDelete) {
            delete it->second;
            it = objList->erase(it);
        }
        else
        {
            it++;
        }
    }
}

Scene::~Scene() {
    for (auto it = objList->begin();
         it != objList->end(); it++) {
        delete it->second;
    }
    delete objList;
}

std::vector<Object*> *Scene::getCollisions(int idType, Object* obj) {
    std::vector<Object*>* objects = new std::vector<Object*>();
    for (auto it = objList->begin();
         it != objList->end(); it++) {
        if ((it->second->typeObject == idType) && (it->second->collider->collision(obj->collider))) {
            objects->push_back(it->second);
        }
    }
    return objects;
}