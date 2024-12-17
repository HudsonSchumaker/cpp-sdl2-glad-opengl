#pragma once

#include "../../include/Pch.hpp"

class Face final {
public:
    int v0 = 0;
	int v1 = 0;
	int v2 = 0;

    int n0 = 0;
    int n1 = 0;
    int n2 = 0;

    int t0 = 0;
    int t1 = 0;
    int t2 = 0;

    Face() = default;
    ~Face() = default;
};
