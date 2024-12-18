#pragma once

#include "../../include/Pch.hpp"

class Face final {
public:
    // Vertices indices - v on OBJ file
    int v0 = 0;
	int v1 = 0;
	int v2 = 0;

    // Texture indices - vt on OBJ file
    int t0 = 0;
    int t1 = 0;
    int t2 = 0;

    // Normal indices - vn on OBJ file
    int n0 = 0;
    int n1 = 0;
    int n2 = 0;

    Face(int v0, int v1, int v2) : v0(v0), v1(v1), v2(v2) {}
    ~Face() = default;
};
