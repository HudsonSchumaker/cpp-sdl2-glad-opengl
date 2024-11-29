#include "../../include/Shader.hpp"
#include "../../include/ShaderLoader.hpp"

Shader::Shader(ShaderType type) {
    if (type == ShaderType::VERTEX) {
        id = glCreateShader(GL_FRAGMENT_SHADER);
    } else {
        id = glCreateShader(GL_FRAGMENT_SHADER);
    }
}

Shader::~Shader() {
    destroy();
}

bool Shader::compile(const std::string& source) {
    const std::string code = ShaderLoader::loadShader(source);
    const GLchar* codePtr = code.c_str();

    glShaderSource(id, 1, &codePtr, nullptr);
    glCompileShader(id);

    GLint success;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLint length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

        GLchar infoLog[length];
        glGetShaderInfoLog(id, length, nullptr, infoLog);
        std::cerr << "Shader compilation failed: " << infoLog << std::endl;

        return false;
    }

    return true;
}

void Shader::destroy() {
    glDeleteShader(id);
}
