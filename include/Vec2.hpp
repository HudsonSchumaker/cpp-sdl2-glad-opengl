/**
* @file Vec2.hpp
* @author Hudson Schumaker
* @brief Defines Vec2 class.
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
#include "Vec3.hpp"

class Vec3;
class Vec2 final {
public:
    float x = 0.0f;
    float y = 0.0f;

    Vec2();
    Vec2(float value);
    Vec2(float x, float y);
    ~Vec2()= default;

    Vec3 toVec3() const;                    // a.toVec3()

    void add(const Vec2& b);                // a.add(b)
    void sub(const Vec2& b);                // a.sub(b)

    void scale(const float s);              // a.scale(s)
    Vec2 rotate(const float angle) const;   // a.rotate(angle) radians
    Vec2 rotateD(const float angle) const;  // a.rotate(angle) in degrees

    float magnitude() const;                // a.magnitude()
    float magnitudeSquared() const;         // a.magnitudeSquared()

    Vec2 normal() const;                    // a.normal()
    Vec2& normalize();                      // a.normalize()
    Vec2 unitVector() const;                // a.unitVector()
   
    float dot(const Vec2& v) const;         // a.dot(b)
    float cross(const Vec2& v) const;       // a.cross(b)
    float distance(const Vec2& b) const;    // a.distance(b)

    Vec2& operator = (const Vec2& v);       // a = b
    bool operator == (const Vec2& v) const; // a == b
    bool operator != (const Vec2& v) const; // a != b
   
    Vec2 operator + (const Vec2& v) const;  // a + b
    Vec2 operator - (const Vec2& v) const;  // a - b
    Vec2 operator * (const float n) const;  // a * n
    Vec2 operator / (const float n) const;  // a / n

    Vec2 operator - () const;               // -a
    
    Vec2& operator += (const Vec2& v);      // a += b
    Vec2& operator -= (const Vec2& v);      // a -= b
    Vec2& operator *= (const float s);      // a *= s
    Vec2& operator /= (const float s);      // a /= 
    
    Vec2& operator ++ (); 				    // a.x++, a.y++      
    Vec2& operator -- (); 				    // a.x--, a.y--
};
