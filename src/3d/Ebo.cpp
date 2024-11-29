#include "../../include/Ebo.hpp"

Ebo::Ebo() {
    glGenBuffers(1, &id);
}

Ebo::~Ebo() {
    destroy();
}

void Ebo::bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void Ebo::unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Ebo::setData(const std::vector<GLuint>& indices) {
    bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
    unbind();
}

void Ebo::destroy() {
    glDeleteBuffers(1, &id);
}
