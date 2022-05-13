    #include "enemy.h"
    #include "system.h"
    #include "bullet.h"

    #include "bulletZigZag.h"


    void Enemy::step()
    {;
        if (movingRight){
            this->position.x+=0.005f;
        } else{
            this->position.x+=-0.005f;

        }


        int random=((int)rand())%100;
        if(random==0)
        {
            BulletZigZag* bullet=new BulletZigZag("bullet.trg");
            bullet->direction=-1.0f;
            bullet->position.x=this->position.x;
            bullet->position.y=this->position.y-0.2f;
            bullet->position.z=this->position.z;
            bullet->scale=glm::vec3(0.1f,0.1f,0.1f);
            System::scene->addObject(bullet);
        }
        if(this->position.x>0.38f)
        {
            movingRight= false;
        } else if (this->position.x < -0.32f){
            movingRight = true;
        }

    }
