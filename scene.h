#pragma once
#include "common.h"
#include "object.h"
#include "camera.h"

class Scene {
private:
    Camera* cam = nullptr;
    std::map<int ,Object*>* objList = nullptr;
    std::map<int, Object*>* addedObjList = nullptr;
public:
    Scene();
    void setCamera(Camera* cam);
    Camera* getCamera();
    void addObject(Object* obj);
    void deleteObject(Object* obj);
    std::map<int, Object*>* getObjList();
    void step(double timeStep);
    std::vector<Object*>* getCollisions(int idType,Object* obj);
    ~Scene();

};
