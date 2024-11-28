/**
* @file Vec3.h
* @author Hudson Schumaker
* @brief Defines Vec3 class.
* @version 1.0.0
*
* 3d-Dodoi-Engine is a game engine developed by Dodoi-Lab.
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
#include "Vec2.hpp"
#include "Vec4.hpp"

class Vec2;
class Vec4;
class Vec3 final {
public:
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    Vec3();
    Vec3(float value);
    Vec3(float x, float y, float z);
    ~Vec3() = default;

    static float dot(const Vec3& a, const Vec3& b);   // Vec3::dot(a, b)
    static Vec3  cross(const Vec3& a, const Vec3& b); // Vec3::cross(a, b)

    Vec2 toVec2() const;                    // a.toVec2()
    Vec4 toVec4() const;			        // a.toVec4()

    void scale(const float n);			    // a.scale(n)
    Vec3 rotateX(const float angle);        // a.rotateX(angle)  radians
    Vec3 rotateY(const float angle);        // a.rotateY(angle)  radians
    Vec3 rotateZ(const float angle);        // a.rotateZ(angle)  radians
   
    Vec3 rotateXd(const float angle);       // a.rotateXd(angle) degrees
    Vec3 rotateYd(const float angle);       // a.rotateYd(angle) degrees
    Vec3 rotateZd(const float angle);       // a.rotateZd(angle) degrees

    float magnitude() const;                // a.magnitude()
    float magnitudeSquared() const;         // a.magnitudeSquared()

    Vec3& normalize();                      // a.normalize()
    Vec3 unitVector() const;                // a.unitVector()
    
    float dot(const Vec3& b) const;         // a.dot(b)
    Vec3 cross(const Vec3& b) const;        // a.cross(b)
    float distance(const Vec3& b) const;    // a.distance(b)
    float angle(const Vec3& b) const;       // a.angle(b)
    
    Vec3& operator = (const Vec3& b);       // a = b
    bool operator == (const Vec3& b) const; // a == b
    bool operator != (const Vec3& b) const; // a != b
   
    Vec3 operator + (const Vec3& b) const;  // a + b
    Vec3 operator - (const Vec3& b) const;  // a - b
    Vec3 operator * (const float s) const;  // a * s
    Vec3 operator / (const float s) const;  // a / s
    Vec3 operator - () const;               // -a

    Vec3& operator += (const Vec3& b);      // a += b
    Vec3& operator -= (const Vec3& b);      // a -= b
    Vec3& operator *= (const float s);      // a *= s
    Vec3& operator /= (const float s);      // a /= s

    Vec3& operator++();                     // a.x++, a.y++, a.z++     
    Vec3& operator--();                     // a.x--, a.y--, a.z--
};  
