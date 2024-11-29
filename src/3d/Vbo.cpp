#include "../../include/Vbo.hpp"

Vbo::Vbo() {
    glGenBuffers(1, &id);
}

Vbo::~Vbo() {
    destroy();
}

void Vbo::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, id);
}

void Vbo::unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Vbo::setData(const std::vector<GLfloat>& vertices) {
    bind();
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);
    unbind();
}

void Vbo::destroy() {
    glDeleteBuffers(1, &id);
}
