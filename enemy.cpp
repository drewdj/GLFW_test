#include "enemy.h"
#include "system.h"
#include "bullet.h"

void Enemy::step() {

    this->position.x+=speed;

    float random = ((int) rand())%100;
    if (random==0){

        Bullet* bullet = new Bullet("bullet.trg",SPACESHIP_OBJ);
        bullet->direction=-1.0f;
        bullet->position.x= this->position.x;
        bullet->position.y= this->position.y-0.12;
        bullet->scale =glm::vec3(0.1f,0.1f,0.1f);
        System::scene->addObject(bullet);
    }

    if (this->position.x>1.3f){

        this->position.x=-1.3f;
    }else if(this->position.x<-1.3f){

        this->position.x=1.3f;
    }
}