/**
* @file Transform2d.hpp
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
#include "../../../include/Vec2.hpp"

/**
* @class Transform2d
* @brief The transform component.
*/
class Transform2d final : public Component {
public:
    Vec2 position;
    Vec2 scale;
    double rotation;

    Transform2d() {
        this->scale.x = 1.0f;
        this->scale.y = 1.0f;
        this->rotation = 0.0;
    }

    Transform2d(float v) {
        this->scale.x = 1.0f;
        this->scale.y = 1.0f;
        this->position.x = v;
        this->position.y = v;
        this->rotation = 0.0;
    }

    Transform2d(Vec2 position) {
        this->scale.x = 1.0f;
        this->scale.y = 1.0f;
        this->position = position;
        this->rotation = 0.0f;
    }

    Transform2d(float x, float y) {
        this->scale.x = 1.0f;
        this->scale.y = 1.0f;
        this->position.x = x;
        this->position.y = y;
        this->rotation = 0.0f;
    }

    Transform2d(Vec2 position, Vec2 scale, double rotation = 0.0) {
        this->position = position;
        this->scale = scale;
        this->rotation = rotation;
    }

    ~Transform2d() = default;

    Transform2d clone() {
        return Transform2d(position, scale, rotation);
    }
};
