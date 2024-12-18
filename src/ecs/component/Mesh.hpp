/**
* @file Mesh.hpp
* @author Hudson Schumaker
* @brief Defines the Mesh class.
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
#include "../../3d/Text2.hpp"
#include "../../3d/Face.hpp"

class Mesh final : public Component {
public:
    std::vector<Vec3> vertices;
    std::vector<Tex2> uvs;
    std::vector<Vec3> normals;
    std::vector<Face> faces;

    Mesh() = default;
    ~Mesh() = default;

    void addVertex(const Vec3& vertex) {
        vertices.push_back(vertex);
    }

    void addUV(const Tex2& uv) {
        uvs.push_back(uv);
    }

    void addNormal(const Vec3& normal) {
        normals.push_back(normal);
    }

    void addFace(const Face& face) {
        faces.push_back(face);
    }
};
