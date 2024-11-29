/**
* @file Vec3.cpp
* @author Hudson Schumaker
* @brief Implements the Vec3 class.
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
#include "../../include/Vec3.hpp"
#include "../../include/Pch.hpp"
#include "../../include/DeMath.hpp"

Vec3::Vec3() : x(0.0f), y(0.0f), z(0.0f) {}
Vec3::Vec3(float value) : x(value), y(value), z(value) {}
Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

float Vec3::dot(const Vec3& a, const Vec3& b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vec3 Vec3::cross(const Vec3& a, const Vec3& b) {
	return Vec3(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	);
}

Vec2 Vec3::toVec2() const {
	return Vec2(x, y);
}

Vec4 Vec3::toVec4() const {
	return Vec4(x, y, z, 1.0f);
}

void Vec3::scale(const float s) {
    x *= s;
    y *= s;
    z *= s;
}

Vec3 Vec3::rotateXd(const float angle) {
    float rad = DeMath::deg2Rad(angle);
    return rotateX(rad);
}

Vec3 Vec3::rotateYd(const float angle) {
	float rad = DeMath::deg2Rad(angle);
	return rotateY(rad);
}

Vec3 Vec3::rotateZd(const float angle) {
	float rad = DeMath::deg2Rad(angle);
	return rotateZ(rad);
}

Vec3 Vec3::rotateX(const float angle) {
	float sine = std::sinf(angle);
	float cosine = std::cosf(angle);

	return Vec3(x, y * cosine - z * sine, y * sine + z * cosine);
}

Vec3 Vec3::rotateY(const float angle) {
	float sine   = std::sinf(angle);
	float cosine = std::cosf(angle);

	return Vec3(x * cosine + z * sine, y, -x * sine + z * cosine);
}

Vec3 Vec3::rotateZ(const float angle) {
	float sine   = std::sinf(angle);
	float cosine = std::cosf(angle);
	
	return Vec3(x * cosine - y * sine, x * sine + y * cosine, z);
}

float Vec3::magnitude() const {
    return std::sqrtf(x * x + y * y + z * z);
}

float Vec3::magnitudeSquared() const {
    return x * x + y * y + z * z;
}

Vec3& Vec3::normalize() {
    float mag = magnitude();
    if (mag != 0.0f) {
        x /= mag;
        y /= mag;
        z /= mag;
    }
    return *this;
}

Vec3 Vec3::unitVector() const {
    float mag = magnitude();
    return Vec3(x/mag, y/mag, z/mag);
}

float Vec3::dot(const Vec3& b) const {
    return x * b.x + y * b.y + z * b.z;
}

Vec3 Vec3::cross(const Vec3& b) const {
    return Vec3(
        y * b.z - z * b.y,
        z * b.x - x * b.z,
        x * b.y - y * b.x
    );
}

float Vec3::distance(const Vec3& b) const {
	float dx = x - b.x;
	float dy = y - b.y;
	float dz = z - b.z;
	return std::sqrtf(dx * dx + dy * dy + dz * dz);
}

float Vec3::angle(const Vec3& b) const {
    float dotProduct = dot(b);
    float magProduct = magnitude() * b.magnitude();
    return std::acos(dotProduct / magProduct);
}

Vec3& Vec3::operator = (const Vec3& b) {
	x = b.x;
	y = b.y;
	z = b.z;
	return *this;
}

bool Vec3::operator == (const Vec3& b) const {
	return x == b.x && y == b.y && z == b.z;
}

bool Vec3::operator != (const Vec3& b) const {
	return !(*this == b);
}

Vec3 Vec3::operator + (const Vec3& b) const {
	return Vec3(x + b.x, y + b.y, z + b.z);
}

Vec3 Vec3::operator - (const Vec3& b) const {
	return Vec3(x - b.x, y - b.y, z - b.z);
}

Vec3 Vec3::operator * (const float s) const {
	return Vec3(x * s, y * s, z * s);
}

Vec3 Vec3::operator / (const float s) const {
	return Vec3(x/s, y/s, z/s);
}

Vec3& Vec3::operator += (const Vec3& b) {
	x += b.x;
	y += b.y;
	z += b.z;
	return *this;
}

Vec3& Vec3::operator -= (const Vec3& b) {
	x -= b.x;
	y -= b.y;
	z -= b.z;
	return *this;
}

Vec3& Vec3::operator *= (const float s) {
	x *= s;
	y *= s;
	z *= s;
	return *this;
}

Vec3& Vec3::operator /= (const float s) {
	x /= s;
	y /= s;
	z /= s;
	return *this;
}

Vec3 Vec3::operator - () const {
	return Vec3(-x, -y, -z);
}

Vec3& Vec3::operator ++ () {
	++x;
	++y;
	++z;
	return *this;
}

Vec3& Vec3::operator -- () {
	--x;
	--y;
	--z;
	return *this;
}
