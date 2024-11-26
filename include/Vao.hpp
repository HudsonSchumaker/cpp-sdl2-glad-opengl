#pragma once
#include "Pch.hpp"
#include "Vbo.hpp"

// Vertex Array Object (VAO) abstraction.
class Vao final {
public:
    GLuint id;
    
    Vao();
    ~Vao();

    void bind();
    void unbind();
    void linkVbo2f(Vbo& vbo, GLuint layout);
    void linkVbo3f(Vbo& vbo, GLuint layout);
    void linkVbo4f(Vbo& vbo, GLuint layout);
    void linkVbo3f2f(Vbo& vbo);
    void linkVbo3f3f(Vbo& vbo);

    void destroy();
};
