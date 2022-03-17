#pragma once
#include "object.h"


class Enemy: public Object{

public:
    float direccion=1.0f;

    Enemy():Object(){};
    Enemy(std::string fileName):Object(fileName){typeObject=ENEMY_OBJ;};
    float tam = 0.0f;
    virtual void step() override;
};

