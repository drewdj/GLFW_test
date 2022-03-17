#include "bullet.h"
#include "system.h"


void Bullet::step() {

    this->position.y+=direction*0.01;

    //test colisiones

    std::vector<Object*> *objects = System::scene->getCollisions(ENEMY_OBJ, this);

    if (objects->size()>0){
        System::scene->deleteObject(this);
        for(auto it=objects->begin();it!=objects->end();it++){
            System::scene->deleteObject(*it);
        }
    }
    if ((this->position.y>2.0f)||(this->position.y<-2.0f)){
        System::scene->deleteObject(this);
    }

    this->rotation.z+=0.7;

    //Aumento y disminucion de tamaño
//    tam += 0.05f;
//    float test = fabs(sinf(tam))/10;
//    this->scale.x=test;
//    this->scale.y=test;
//    this->scale.z=test;

}