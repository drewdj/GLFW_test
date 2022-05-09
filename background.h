#include "object.h"

class Background: public Object{
public:
    Background(std::string fileName):Object(fileName){typeObject=BACKGROUND_OBJ;};
    glm::vec2 scroll;
    virtual void step() override;
};

