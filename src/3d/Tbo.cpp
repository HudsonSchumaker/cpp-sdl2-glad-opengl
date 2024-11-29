#include "../../include/Tbo.hpp"

Tbo::Tbo() {
    glGenTextures(1, &id);
}

Tbo::~Tbo() {
    destroy();
}

void Tbo::bind() {
    glBindTexture(GL_TEXTURE_2D, id);
}

void Tbo::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

bool Tbo::load(const std::string& path) {
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (surface == nullptr) {
        std::cerr << "Error loading texture: " << path << std::endl;
        return false;
    }

    return load(surface);
}

bool Tbo::load(SDL_Surface* surface) {
    flipSurface(surface);
    bind();

    GLenum format = GL_RGB;
    if (surface->format->BytesPerPixel == 4) {
        format = GL_RGBA;
    }

    width = surface->w;
    height = surface->h;
    channels = surface->format->BytesPerPixel;

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glGenerateMipmap(GL_TEXTURE_2D);

    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, surface->pixels);

    unbind();

    SDL_FreeSurface(surface);
    return true;
}

void Tbo::destroy() {
    glDeleteTextures(1, &id);
}

// TODO: make it C++
void Tbo::flipSurface(SDL_Surface* surface) {
    if (SDL_LockSurface(surface) < 0) {
        return; // Failed to lock surface
    }

    int pitch = surface->pitch; // row size
    char* temp = (char*)malloc(pitch); // intermediate buffer
    if (temp == NULL) {
        SDL_UnlockSurface(surface);
        return; // Memory allocation failed
    }

    char* pixels = (char*)surface->pixels;

    for (int i = 0; i < surface->h / 2; ++i) {
        // get pointers to the two rows to swap
        char* row1 = pixels + i * pitch;
        char* row2 = pixels + (surface->h - i - 1) * pitch;

        // swap rows
        memcpy(temp, row1, pitch);
        memcpy(row1, row2, pitch);
        memcpy(row2, temp, pitch);
    }

    free(temp);
    SDL_UnlockSurface(surface);
}
