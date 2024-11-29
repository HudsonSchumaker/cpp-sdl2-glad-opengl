#include "Pch.hpp"

enum class ShaderType {
    FRAGMENT,
    VERTEX
};

class Shader final {
public:
    GLuint id;

    Shader(ShaderType type);
    ~Shader();

    bool compile(const std::string& source);
    void destroy();
};
