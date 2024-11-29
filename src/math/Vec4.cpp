/**
* @file Vec4.cpp
* @author Hudson Schumaker
* @brief Implements the Vec4 class.
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
#include "../../include/Vec4.hpp"
#include "../../include/Pch.hpp"

Vec4::Vec4() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}
Vec4::Vec4(float value) : x(value), y(value), z(value), w(value) {}
Vec4::Vec4(float x, float y, float z) : x(x), y(y), z(z), w(1.0f) {}
Vec4::Vec4(float x, float y, float z, float w) : x(x), y(y), z(z) , w(w) {}

Vec2 Vec4::toVec2() const {
    return Vec2(x, y);
}

Vec3 Vec4::toVec3() const {
	return Vec3(x, y, z);
}

float Vec4::dot(const Vec4& v) const {
    return x * v.x + y * v.y + z * v.z + w * v.w;
}

float Vec4::magnitude() const {
    return std::sqrtf(x * x + y * y + z * z + w * w);
}

Vec4& Vec4::normalize() {
    float mag = magnitude();
    if (mag > 0.0f) {
        x /= mag;
        y /= mag;
        z /= mag;
        w /= mag;
    }
    return *this;
}

Vec4 Vec4::operator + (const Vec4& v) const {
    return Vec4(x + v.x, y + v.y, z + v.z, w + v.w);
}

Vec4 Vec4::operator - (const Vec4& v) const {
    return Vec4(x - v.x, y - v.y, z - v.z, w - v.w);
}

Vec4 Vec4::operator * (float s) const {
    return Vec4(x * s, y * s, z * s, w * s);
}

Vec4 Vec4::operator / (float s) const {
    return Vec4(x / s, y / s, z / s, w / s);
}

Vec4 Vec4::operator - () const {
    return Vec4(-x, -y, -z, -w);
}

Vec4& Vec4::operator ++ () {
    ++x;
    ++y;
    ++z;
    ++w;
    return *this;
}

Vec4& Vec4::operator -- () {
    --x;
    --y;
    --z;
    --w;
    return *this;
}
