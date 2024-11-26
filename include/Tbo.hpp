#pragma once
#include "Pch.hpp"

// Texture Buffer Object (TBO) abstraction.
class Tbo final {
public:
    GLuint id;
    GLint width;
    GLint height;
    GLuint channels;
    
    Tbo();
    ~Tbo();

    void bind();
    void unbind();
    bool load(const std::string& path);
    bool load(SDL_Surface* surface);
    void destroy();

private:
    void flipSurface(SDL_Surface* surface);
};
