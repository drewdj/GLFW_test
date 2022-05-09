    #include "enemy.h"
    #include "system.h"
    #include "bullet.h"


    void Enemy::step()
    {;
        if (movingRight){
            this->position.x+=0.01f;
        } else{
            this->position.x+=-0.01f;

        }


        int random=((int)rand())%100;
        if(random==0)
        {
            Bullet* bullet=new Bullet("bullet.trg");
            bullet->direction=-1.0f;
            bullet->position.x=this->position.x;
            bullet->position.y=this->position.y-0.21f;
            bullet->position.z = this->position.z - 0.1f;
            bullet->scale=glm::vec3(0.1f,0.1f,0.1f);
            System::scene->addObject(bullet);
        }
        if(this->position.x>1.0f)
        {
            movingRight= false;
        } else if (this->position.x < -1.0f){
            movingRight = true;
        }

    }
