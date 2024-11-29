/**
* @file Vec2.cpp
* @author Hudson Schumaker
* @brief Implements the Vec2 class.
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
#include "../../include/Vec2.hpp"
#include "../../include/Pch.hpp"

Vec2::Vec2() : x(0.0f), y(0.0f) {}
Vec2::Vec2(float value) : x(value), y(value) {}
Vec2::Vec2(float x, float y) : x(x), y(y) {}

Vec3 Vec2::toVec3() const {
	return Vec3(x, y, 1.0f);
}

void Vec2::add(const Vec2& v) {
	x += v.x;
	y += v.y;
}

void Vec2::sub(const Vec2& v) {
	x -= v.x;
	y -= v.y;
}

void Vec2::scale(const float n) {
	x *= n;
	y *= n;
}

Vec2 Vec2::rotateD(const float angle) const {
	float rad = angle * Defs::PI / 180.0f; // Convert to radians
	return rotate(rad);
}

Vec2 Vec2::rotate(const float angle) const {
	float sine   = std::sinf(angle);
	float cosine = std::cosf(angle);

	return Vec2(x * cosine - y * sine, x * sine + y * cosine);
}

float Vec2::magnitude() const {
	return std::sqrtf(x * x + y * y);
}

float Vec2::magnitudeSquared() const {
	return (x * x + y * y);
}

Vec2& Vec2::normalize() {
	float mag = magnitude();
	if (mag != 0.0f) {
		x /= mag;
		y /= mag;
	}
	return *this;
}

Vec2 Vec2::unitVector() const {
	float mag = magnitude();
	return Vec2(x/mag, y/mag);
}

Vec2 Vec2::normal() const {
	return Vec2(y, -x).normalize();
}

float Vec2::dot(const Vec2& b) const {
	return (x * b.x) + (y * b.y);
}

float Vec2::cross(const Vec2& b) const {
	return (x * b.y) - (y * b.x);
}

float Vec2::distance(const Vec2& b) const {
	float dx = x - b.x;
	float dy = y - b.y;
	return std::sqrtf(dx * dx + dy * dy);
}

Vec2& Vec2::operator = (const Vec2& b) {
	x = b.x;
	y = b.y;
	return *this;
}

bool Vec2::operator == (const Vec2& b) const {
	return x == b.x && y == b.y;
}

bool Vec2::operator != (const Vec2& b) const {
	return !(*this == b);
}

Vec2 Vec2::operator + (const Vec2& b) const {
	return Vec2(x + b.x, y + b.y);
}

Vec2 Vec2::operator - (const Vec2& b) const {
	return Vec2(x - b.x, y - b.y);
}

Vec2 Vec2::operator * (const float s) const {
	return Vec2(x * s, y * s);
}

Vec2 Vec2::operator / (const float s) const {
	return Vec2(x / s, y / s);
}

Vec2& Vec2::operator += (const Vec2& b) {
	x += b.x;
	y += b.y;
	return *this;
}

Vec2& Vec2::operator -= (const Vec2& b) {
	x -= b.x;
	y -= b.y;
	return *this;
}

Vec2& Vec2::operator *= (const float s) {
	x *= s;
	y *= s;
	return *this;
}

Vec2& Vec2::operator /= (const float s) {
	x /= s;
	y /= s;
	return *this;
}

Vec2 Vec2::operator - () const {
	return Vec2(-x, -y);
}

Vec2& Vec2::operator ++ () {
	++x;
	++y;
	return *this;
}

Vec2& Vec2::operator -- () {
	--x;
	--y;
	return *this;
}
