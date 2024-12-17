/**
* @file Program.hpp
* @author Hudson Schumaker
* @brief Defines the Program class.
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
#include "Shader.hpp"
#include "Matrix4.hpp"

class Program final {
public:
    GLuint id;

    Program();
    ~Program();

    void use();
    bool link(const Shader& vertexShader, const Shader& fragmentShader);
    GLint getUniformLocation(const std::string name) const;
    
    void setUniform(const GLint location, GLint value);
    void setUniform(const GLint location, GLfloat value);
    void setUniform(const GLint location, Vec2& vector);
    void setUniform(const GLint location, Vec3& vector);
    void setUniform(const GLint location, Vec4& vector);
    void setUniform(const GLint location, Matrix4& matrix);
    
    void detach(const Shader& shader);
    void unbind();
    void destroy();
};
