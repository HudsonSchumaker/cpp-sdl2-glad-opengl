#pragma once
#include "Pch.hpp"

// Vertex Buffer Object (VBO) abstraction.
class Vbo final {
public:
    GLuint id;
    
    Vbo();
    ~Vbo();

    void bind();
    void unbind();
    void setData(const std::vector<GLfloat>& indices);
    void destroy();
};
 