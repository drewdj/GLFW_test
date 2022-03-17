#include "spaceShip.h"
#include "inputManager.h"
#include "scene.h"
#include "system.h"
#include "bullet.h"

bool canShoot = true;

void SpaceShip::step() {
    if (InputManager::keys['A']){
        position.x-=0.01f;

    }

    if (InputManager::keys['D']){
        position.x+=0.01f;

    }

    if (InputManager::keys[' ']==1){
        if (canShoot){
            Object* bullet = new Bullet("bullet.trg");
            bullet->position.x= this->position.x;
            bullet->position.y= this->position.y;
            bullet->scale =glm::vec3(0.1f,0.1f,0.1f);
            System::scene->addObject(bullet);
            canShoot = false;
        }
    } else {
        canShoot = true;
    }

}


