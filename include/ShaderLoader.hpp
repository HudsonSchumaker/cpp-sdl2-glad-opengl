#include "Pch.hpp"

class ShaderLoader final {
public:
    ShaderLoader() = default;
    ~ShaderLoader() = default;

    static std::string loadShader(const std::string& filename); 
};
