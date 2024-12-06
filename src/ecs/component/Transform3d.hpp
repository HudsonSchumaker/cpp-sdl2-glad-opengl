/**
* @file Transform3d.hpp
* @author Hudson Schumaker
* @brief Defines the Tranform class.
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
#include "Component.hpp"
#include "../../../include/Vec3.hpp"

/**
* @class Transform3d
* @brief The transform component.
*/
class Transform3d final : public Component {
public:
    Vec3 position;
    Vec3 scale;
    float rotation;

    Transform3d() {
        this->scale.x = 1.0f;
        this->scale.y = 1.0f;
        this->scale.z = 1.0f;
        this->rotation = 0.0f;
    }

    Transform3d(float v) {
        this->scale.x = 1.0f;
        this->scale.y = 1.0f;
        this->scale.z = 1.0f;
        this->position.x = v;
        this->position.y = v;
        this->position.z = v;
        this->rotation = 0.0f;
    }

    Transform3d(Vec3 position) {
        this->scale.x = 1.0f;
        this->scale.y = 1.0f;
        this->scale.z = 1.0f;
        this->position = position;
        this->rotation = 0.0f;
    }

    Transform3d(float x, float y, float z) {
        this->scale.x = 1.0f;
        this->scale.y = 1.0f;
        this->scale.z = 1.0f;
        this->position.x = x;
        this->position.y = y;
        this->position.z = z;
        this->rotation = 0.0f;
    }

    Transform3d(Vec3 position, Vec3 scale, float rotation = 0.0f) {
        this->position = position;
        this->scale = scale;
        this->rotation = rotation;
    }

    ~Transform3d() = default;

    Transform3d clone() {
        return Transform3d(position, scale, rotation);
    }
};
