#pragma once

#include "common.h"
#include "vertex.h"
#include <vector>

class Mesh{
public:

    std::vector<vertex_t>* vertexList;
    std::vector<int>* faceList;

    Mesh();
    Mesh(std::string fileName);
    ~Mesh();
    void loadFromFile (std::string fileName);
    void setColor(int idxVertex, glm::vec4 color);
};
