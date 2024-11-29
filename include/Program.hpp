#include "Pch.hpp"
#include "Shader.hpp"
#include "Matrix4.hpp"

class Program final {
public:
    GLuint id;

    Program();
    ~Program();

    void use();
    bool link(const Shader& vertexShader, const Shader& fragmentShader);
    GLint getUniformLocation(const std::string name) const;
    
    void setUniform(const GLint location, GLint value);
    void setUniform(const GLint location, GLfloat value);
    void setUniform(const GLint location, Vec2& vector);
    void setUniform(const GLint location, Vec3& vector);
    void setUniform(const GLint location, Vec4& vector);
    void setUniform(const GLint location, Matrix4& matrix);
    
    void detach(const Shader& shader);
    void unbind();
    void destroy();
};
