#include "../../include/Vao.hpp"

Vao::Vao() {
    glGenVertexArrays(1, &id);
}

Vao::~Vao() {
    destroy();
}

void Vao::bind() {
    glBindVertexArray(id);
}

void Vao::unbind() {
    glBindVertexArray(0);
}

void Vao::linkVbo2f(Vbo& vbo, GLuint layout) {
    bind();
    vbo.bind();
    glVertexAttribPointer(layout, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(layout);
    vbo.unbind();
    unbind();
}

void Vao::linkVbo3f(Vbo& vbo, GLuint layout) {
    bind();
    vbo.bind();
    glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(layout);
    vbo.unbind();
    unbind();
}

void Vao::linkVbo4f(Vbo& vbo, GLuint layout) {
    bind();
    vbo.bind();
    glVertexAttribPointer(layout, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(layout);
    vbo.unbind();
    unbind();
}

void Vao::linkVbo3f2f(Vbo& vbo) {
    bind();
    vbo.bind();
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    vbo.unbind();
    unbind();
}

void Vao::linkVbo3f3f(Vbo& vbo) {
    bind();
    vbo.bind();
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    vbo.unbind();
    unbind();
}

void Vao::destroy() {
    glDeleteVertexArrays(1, &id);
}
