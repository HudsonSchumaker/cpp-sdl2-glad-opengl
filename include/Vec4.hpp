/**
* @file Vec4.hpp
* @author Hudson Schumaker
* @brief Defines Vec4 class.
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
#include "Vec3.hpp"

class Vec2;
class Vec3;
class Vec4 final {
public:
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    float w = 1.0f;

    Vec4();
    Vec4(float value);
    Vec4(float x, float y, float z);
    Vec4(float x, float y, float z, float w);
    ~Vec4() = default;

    Vec2 toVec2() const;                   // a.toVec2()
    Vec3 toVec3() const;				   // a.toVec3()

    float dot(const Vec4& b) const;        // a.dot(b)
    float magnitude() const;			   // a.magnitude()
    Vec4& normalize();					   // a.normalize()

    Vec4 operator + (const Vec4& b) const; // a + b   
    Vec4 operator - (const Vec4& b) const; // a - b
    Vec4 operator * (float s) const;       // a * s   
    Vec4 operator / (float s) const;	   // a / s
    Vec4 operator - () const;              // -a

    Vec4& operator ++ ();                  // a.x++, a.y++, a.z++, a.w++      
    Vec4& operator -- ();                  // a.x--, a.y--, a.z--, a.w--
};
