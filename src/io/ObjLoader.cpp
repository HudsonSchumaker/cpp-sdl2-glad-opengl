#include "../../include/ObjLoader.hpp"
#include "../3d/Face.hpp"

Mesh* ObjLoader::load(const std::string& path) {
    Mesh* mesh = new Mesh();
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << path << std::endl;
        return nullptr;
    }
    std::string line; 

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        // Vertex information
        if (type == "v") {
            Vec3 vertex;
            iss >> vertex.x >> vertex.y >> vertex.z;
            mesh->addVertex(vertex);
            continue;
        }

        // Texture coordinate information
        if (type == "vt") {
            float u, v;
            iss >> u >> v;
            mesh->addUV(Tex2(u, v));
            continue;
        }

        // Normal information
        if (type == "vn") {
            Vec3 normal;
            iss >> normal.x >> normal.y >> normal.z;
            mesh->addNormal(normal);
            continue;
        }

        // Face information
        if (type == "f") {
            // Indices for vertex, texture, and normal
            int vertexI[3]  = { 0 };
            int textureI[3] = { 0 };
            int normalI[3]  = { 0 };
         
            for (short i = 0; i < 3; i++) {
                iss >> vertexI[i];
                vertexI[i]--; // Adjust for 0-based indexing
                if (iss.peek() == '/') {
                    iss.get(); // Skip the first slash
                    if (iss.peek() != '/') {
                        iss >> textureI[i];
                        textureI[i]--; // Adjust for 0-based indexing
                    }
                    if (iss.peek() == '/') {
                        iss.get(); // Skip the second slash
                        iss >> normalI[i];
                        normalI[i]--; // Adjust for 0-based indexing
                    }
                }
            }

            Face face(vertexI[0], vertexI[1], vertexI[2]);
            face.t0 = textureI[0];
            face.t1 = textureI[1];
            face.t2 = textureI[2];

            face.n0 = normalI[0];
            face.n1 = normalI[1];
            face.n2 = normalI[2];
            mesh->addFace(face);
        }
    }

    return mesh;
}
