#include "object.h"

int Object::idCounter = 0;

Object::Object() {

    this->id = idCounter;
    idCounter++;
    this->mesh = new Mesh();
    this->position = glm::vec3(0.0f, 0.0f, 0.0f);
    this->modelMatrix = glm::mat4(1.0f);
    this->mesh->setColor(0,glm::vec4(1.0f,0.0f,0.0f,1.0f));
    this->mesh->setColor(1,glm::vec4(0.0f,1.0f,0.0f,1.0f));
    this->mesh->setColor(2,glm::vec4(0.0f,0.0f,1.0f,1.0f));
    this->collider = new Collider(this);


}

Object::Object(std::string fileName) {

    this->id = idCounter;
    idCounter++;
    this->mesh = new Mesh(fileName);
    this->position = glm::vec3(0.0f, 0.0f, 0.0f);
    this->modelMatrix = glm::mat4(1.0f);

    this->collider = new Collider(this);
}
    glm::mat4 Object::getMatrix(){
        return modelMatrix;
    }

    void Object::computeMatrix() {
        modelMatrix[3][0] = position.x;
        modelMatrix[3][1] = position.y;
        modelMatrix[3][2] = position.z;

        glm::mat4 matT=glm::translate(glm::mat4(1.0f), this->position);
        matT=glm::rotate(matT, this->rotation.x,glm::vec3(1.0f,0,0));
        matT=glm::rotate(matT, this->rotation.y,glm::vec3(0,1.0f,0));
        matT=glm::rotate(matT, this->rotation.z,glm::vec3(0,0,1.0f));
        matT=glm::scale(matT, this->scale);

        this->modelMatrix=matT;


    }

    void Object::updateCollider() {
        collider->update();
}

    void Object::step() {
//        rotation.x +=0.01;
//        rotation.y +=0.01;
//        rotation.z +=0.01;
//        position.x += 0.01;
//        if  (position.x>1.0f)
//            position.x=-1.0f;
    }

