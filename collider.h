#pragma once
#include "common.h"

class Object;

class BV {
public:
    virtual bool collision(BV* b2) = 0;
    virtual void init(Object* obj) = 0;
    virtual void update() = 0;
};

class Box2D :public BV{
public:
    //glm::vec3 position = glm::vec3(0, 0, 0);
    float xMax = 0;
    float yMax = 0;
    float yMin = 0;
    float xMin = 0;
    Object* obj = nullptr;
    Box2D();
    bool collision(BV* b2);
    void init(Object* obj);
    void update();
};

class Collider {
public:
    std:: vector<BV*> *boxList;
    Collider(Object* obj);
    bool collision(Collider* c2);
    void update();
};