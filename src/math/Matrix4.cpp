#include "../../include/Matrix4.hpp"

Matrix4::Matrix4() : m{{0.0f, 0.0f, 0.0f, 0.0f},
                       {0.0f, 0.0f, 0.0f, 0.0f},
                       {0.0f, 0.0f, 0.0f, 0.0f},
                       {0.0f, 0.0f, 0.0f, 0.0f}} {}

Matrix4 Matrix4::identity() {
    // | 1  0  0  0 |
    // | 0  1  0  0 |
    // | 0  0  1  0 |
    // | 0  0  0  1 |
    Matrix4 m;
    m.m[0][0] = 1.0f;
    m.m[1][1] = 1.0f;
    m.m[2][2] = 1.0f;
    m.m[3][3] = 1.0f;
    return m;
}

Matrix4 Matrix4::scale(float sx, float sy, float sz) {
    // | sx  0  0  0 |
    // |  0 sy  0  0 |
    // |  0  0 sz  0 |
    // |  0  0  0  1 |
    Matrix4 m = identity();
    m.m[0][0] = sx;
    m.m[1][1] = sy;
    m.m[2][2] = sz;
    return m;
}

Matrix4 Matrix4::translate(float tx, float ty, float tz) {
    // | 1  0  0 tx |
    // | 0  1  0 ty |
    // | 0  0  1 tz |
    // | 0  0  0  1 |
    Matrix4 m = identity();
    m.m[0][3] = tx;
    m.m[1][3] = ty;
    m.m[2][3] = tz;
    return m;
}

Matrix4 Matrix4::rotateX(float angle) {
    // | 1    0        0     0 |
    // | 0  cos(a)  -sin(a)  0 |
    // | 0  sin(a)   cos(a)  0 |
    // | 0    0        0     1 |
    float sine = std::sinf(angle);
    float cosine = std::cosf(angle);

    Matrix4 m = identity();
    m.m[1][1] = cosine;
    m.m[1][2] = -sine;
    m.m[2][1] = sine;
    m.m[2][2] = cosine;
    return m;
}

Matrix4 Matrix4::rotateY(float angle) {
    // |  cos(a)  0  sin(a)  0 |
    // |    0     1    0     0 |
    // | -sin(a)  0  cos(a)  0 |
    // |    0     0    0     1 |
    float sine = std::sinf(angle);
    float cosine = std::cosf(angle);

    Matrix4 m = identity();
    m.m[0][0] = cosine;
    m.m[0][2] = sine;
    m.m[2][0] = -sine;
    m.m[2][2] = cosine;
    return m;
}

Matrix4 Matrix4::rotateZ(float angle) {
    // | cos(a) -sin(a)  0  0 |
    // | sin(a)  cos(a)  0  0 |
    // |   0       0     1  0 |
    // |   0       0     0  1 |
    float sine = std::sinf(angle);
    float cosine = std::cosf(angle);

    Matrix4 m = identity();
    m.m[0][0] = cosine;
    m.m[0][1] = -sine;
    m.m[1][0] = sine;
    m.m[1][1] = cosine;
    return m;
}

Matrix4 Matrix4::perspective(float fov, float aspect, float znear, float zfar) {
    // | (h/w)*1/tan(fov/2)             0              0                 0 |
    // |                  0  1/tan(fov/2)              0                 0 |
    // |                  0             0     zf/(zf-zn)  (-zf*zn)/(zf-zn) |
    // |                  0             0              1                 0 |
    float ctanFov = 1.0f / std::tanf(fov / 2.0f);

    Matrix4 m;
    m.m[0][0] = aspect * ctanFov;
    m.m[1][1] = ctanFov;
    m.m[2][2] = zfar / (zfar - znear);
    m.m[2][3] = (-zfar * znear) / (zfar - znear);
    m.m[3][2] = 1.0f; // right-handed coordinate system 
    return m;
}

Matrix4 Matrix4::lookAt(const Vec3& eye, const Vec3& target, const Vec3& up) {
    Vec3 z = (target - eye).normalize();
    Vec3 x = up.cross(z).normalize();
    Vec3 y = z.cross(x);

    // | x.x   x.y   x.z  -dot(x,eye) |
    // | y.x   y.y   y.z  -dot(y,eye) |
    // | z.x   z.y   z.z  -dot(z,eye) |
    // |   0     0     0      1       |
    Matrix4 m;
    // X
    m.m[0][0] = x.x;
    m.m[0][1] = x.y;
    m.m[0][2] = x.z;
    m.m[0][3] = -x.dot(eye);

    // Y
    m.m[1][0] = y.x;
    m.m[1][1] = y.y;
    m.m[1][2] = y.z;
    m.m[1][3] = -y.dot(eye);

    // Z
    m.m[2][0] = z.x;
    m.m[2][1] = z.y;
    m.m[2][2] = z.z;
    m.m[2][3] = z.dot(eye);

    // W
    m.m[3][3] = 1.0f;

    return m;
}

Vec4 Matrix4::mulVec4(const Matrix4& m, const Vec4& v) {
    Vec4 result;
    result.x = m.m[0][0] * v.x + m.m[0][1] * v.y + m.m[0][2] * v.z + m.m[0][3] * v.w;
    result.y = m.m[1][0] * v.x + m.m[1][1] * v.y + m.m[1][2] * v.z + m.m[1][3] * v.w;
    result.z = m.m[2][0] * v.x + m.m[2][1] * v.y + m.m[2][2] * v.z + m.m[2][3] * v.w;
    result.w = m.m[3][0] * v.x + m.m[3][1] * v.y + m.m[3][2] * v.z + m.m[3][3] * v.w;
    return result;
}

Matrix4 Matrix4::mulMat4(const Matrix4& a, const Matrix4& b) {
    Matrix4 result;
    for (short i = 0; i < 4; i++) {
        for (short j = 0; j < 4; j++) {
            result.m[i][j] = a.m[i][0] * b.m[0][j] + 
                            a.m[i][1] * b.m[1][j] + 
                            a.m[i][2] * b.m[2][j] +
                            a.m[i][3] * b.m[3][j];
        }
    }
    return result;
}

void Matrix4::toArray(float* array) {
    for (short i = 0; i < 4; i++) {
        for (short j = 0; j < 4; j++) {
            array[j * 4 + i] = m[i][j]; // column-major order
        }
    }
}
