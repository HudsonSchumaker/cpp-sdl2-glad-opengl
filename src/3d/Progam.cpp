#include "../../include/Program.hpp"

Program::Program() {
    id = glCreateProgram();
}

Program::~Program() {
    destroy();
}

void Program::use() {
    glUseProgram(id);
}

bool Program::link(const Shader& vertexShader, const Shader& fragmentShader) {
    glAttachShader(id, vertexShader.id);
    glAttachShader(id, fragmentShader.id);
    glLinkProgram(id);
    
    GLint success;
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success) {
        GLint length;
        glGetProgramiv(id, GL_INFO_LOG_LENGTH, &length);

        GLchar infoLog[length];
        glGetProgramInfoLog(id, length, nullptr, infoLog);
        std::cerr << "Program linking failed: " << infoLog << std::endl;

        detach(vertexShader);
        detach(fragmentShader);
        return false;
    }
    
    return true;
}

GLint Program::getUniformLocation(const std::string name) const {
    return glGetUniformLocation(id, name.c_str());
}

void Program::setUniform(const GLint location, GLint value) {
    glUniform1i(location, value);
}

void Program::setUniform(const GLint location, GLfloat value) {
    glUniform1f(location, value);
}

void Program::setUniform(const GLint location, Vec2& vector) {
    glUniform2f(location, vector.x, vector.y);
}

void Program::setUniform(const GLint location, Vec3& vector) {
    glUniform3f(location, vector.x, vector.y, vector.z);
}

void Program::setUniform(const GLint location, Vec4& vector) {
    glUniform4f(location, vector.x, vector.y, vector.z, vector.w);
}

void Program::setUniform(const GLint location, Matrix4& matrix) {
    float data[16];
    matrix.toArray(data);
    glUniformMatrix4fv(location, 1, GL_FALSE, data);
}

void Program::detach(const Shader& shader) {
    glDetachShader(id, shader.id);
}

void Program::unbind() {
    glUseProgram(0);
}

void Program::destroy() {
    glDeleteProgram(id);
}
