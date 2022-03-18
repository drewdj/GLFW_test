#pragma once
#include "object.h"


class Bullet: public Object{

public:
    float direction=1.0f;
    int owner;
    Bullet():Object(){};
    Bullet(std::string fileName,int newOwner):Object(fileName){typeObject=BULLET_OBJ;owner=newOwner;};
    float tam = 0.0f;
    virtual void step() override;
};