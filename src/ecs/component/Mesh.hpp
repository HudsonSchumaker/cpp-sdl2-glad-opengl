#pragma once
#include "Component.hpp"
#include "../../../include/Vec3.hpp"
#include "../../3d/Text2.hpp"
#include "../../3d/Face.hpp"

class Mesh final : public Component {
public:
    std::vector<Vec3*> vertices;
    std::vector<Tex2*> uvs;
    std::vector<Vec3*> normals;
    std::vector<Face*> faces;

    Mesh() = default;
    ~Mesh() = default;

    void addVertex(Vec3* vertex) {
        vertices.push_back(vertex);
    }

    void addUV(Tex2* uv) {
        uvs.push_back(uv);
    }

    void addNormal(Vec3* normal) {
        normals.push_back(normal);
    }

    void addFace(Face* face) {
        faces.push_back(face);
    }
};
