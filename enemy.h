#pragma once
#include "object.h"


class Enemy: public Object{

public:
    float speed = 0.01f;
    float direccion=1.0f;
    Enemy():Object(){};
    Enemy(std::string fileName,float newSpeed):Object(fileName){typeObject=ENEMY_OBJ;speed=newSpeed;};
    float tam = 0.0f;
    virtual void step() override;
};

