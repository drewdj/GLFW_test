#pragma once
#include "common.h"
#include <iostream>


class GLShader {
public:
    unsigned int programID=0xFFFFFFFF;
    std::string vshader;
    std::string fshader;

    GLShader(std::string vshader, std::string fshader);
    void checkCompileError(unsigned int program);

    std::string readFile(std::string fileName);
    void compileShaders();
    void checkLinkError(unsigned int program);
};

