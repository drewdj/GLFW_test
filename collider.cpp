#include "collider.h"

#include "object.h"


Box2D::Box2D(){


}


bool Box2D::collision(BV* _b2){

    Box2D* b2=(Box2D*)_b2;



    if((xMin<b2->xMax && xMin>b2->xMin)&&(yMin<b2->yMax &&yMin>b2->yMin)) return true;

    if((xMin<b2->xMax && xMin>b2->xMin)&&(yMax<b2->yMax &&yMax>b2->yMin)) return true;

    if((xMax<b2->xMax && xMax>b2->xMin)&&(yMin<b2->yMax &&yMin>b2->yMin)) return true;

    if((xMax<b2->xMax && xMax>b2->xMin)&&(yMax<b2->yMax &&yMax>b2->yMin)) return true;



    return false;

}


void Box2D::init(Object* obj){

    this->obj=obj;

    update();

}



void Box2D::update(){



    std::vector<vertex_t>* vertexList=obj->mesh->vertexList;

    obj->computeMatrix();

    glm::mat4 m=obj->getMatrix();

    int numVertex=vertexList->size();

    glm::vec4 newPos;


    vertex_t v=vertexList->data()[0];

    newPos=m*v.posicion;


    xMin=xMax=newPos.x;

    yMin=yMax=newPos.y;


    for(int idV=1; idV<numVertex; idV++)

    {

        vertex_t v=vertexList->data()[idV];

        newPos=m*v.posicion;



        if(xMin>newPos.x)xMin=newPos.x;

        else if(xMax<newPos.x)xMax=newPos.x;



        if(yMin>newPos.y)yMin=newPos.y;

        else if(yMax<newPos.y)yMax=newPos.y;

    }

}




Collider::Collider(Object* obj)

{


    boxList=new std::vector<BV*>();

    BV* newBox=new Box2D();

    newBox->init(obj);

    boxList->push_back(newBox);



}



void Collider::update(){

    for(auto it=boxList->begin();it!=boxList->end();it++)

        (*it)->update();

}


bool Collider::collision(Collider* c2){

    auto it1=boxList->begin();


    bool collision=false;

    while(!collision && it1!=boxList->end())

    {

        auto it2=c2->boxList->begin();

        while(!collision && it2!=c2->boxList->end())

        {

            collision=(*it1)->collision(*it2)||(*it2)->collision(*it1) ;

            it2++;

        }

        it1++;



    }

    return collision;



}