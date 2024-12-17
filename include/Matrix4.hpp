/**
* @file Matrix4.hpp
* @author Hudson Schumaker
* @brief Defines the Matrix4 class.
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
#include "Vec4.hpp"

class Matrix4 final {
public:
    float m[4][4];

    Matrix4();
    ~Matrix4() = default;
    
    static Matrix4 identity();
    static Matrix4 scale(float sx, float sy, float sz);
    static Matrix4 translate(float tx, float ty, float tz);
    static Matrix4 rotateX(float angle);
    static Matrix4 rotateY(float angle);
    static Matrix4 rotateZ(float angle);
    
    static Matrix4 perspective(float fov, float aspect, float znear, float zfar);
    static Matrix4 lookAt(const Vec3& eye, const Vec3& target, const Vec3& up);

    static Vec4 mulVec4(const Matrix4& matrix, const Vec4& vector);
    static Matrix4 mulMat4(const Matrix4& a, const Matrix4& b);
    void toArray(float* array);
};
