/**
* @file Tbo.hpp
* @author Hudson Schumaker
* @brief Defines the Tbo class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
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
