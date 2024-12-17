#include "../../include/ShaderLoader.hpp"

std::string ShaderLoader::loadShader(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }

    std::string line;
    std::string shader;
    while (std::getline(file, line)) {
        shader += line + "\n";
    }

    return shader;
}
