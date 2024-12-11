#include "Pch.hpp"
#include "Vec4.hpp"

class Matrix4 final {
public:
    float m[4][4];

    Matrix4();
    ~Matrix4() = default;
    
    static Matrix4 identity();
    static Matrix4 scale(float sx, float sy, float sz);
    static Matrix4 translate(float tx, float ty, float tz);
    static Matrix4 rotateX(float angle);
    static Matrix4 rotateY(float angle);
    static Matrix4 rotateZ(float angle);
    
    static Matrix4 perspective(float fov, float aspect, float znear, float zfar);
    static Matrix4 lookAt(const Vec3& eye, const Vec3& target, const Vec3& up);

    static Vec4 mulVec4(const Matrix4& matrix, const Vec4& vector);
    static Matrix4 mulMat4(const Matrix4& a, const Matrix4& b);
    void toArray(float* array);
};
