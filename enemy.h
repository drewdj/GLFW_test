#pragma once
#include "object.h"

class Enemy: public Object{

	
public:

    float movement = 0.01f;
	Enemy():Object(){};
	Enemy(std::string fileName):Object(fileName){typeObject=ENEMY_OBJ;movement=0.01f;};
	virtual void step() override;
};

