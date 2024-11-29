#pragma once
class Tex2 final {
public:
	float u = 0.0f;
	float v = 0.0f;

	Tex2() = default;
	Tex2(float u, float v) : u(u), v(v) {}
	~Tex2() = default;
};
