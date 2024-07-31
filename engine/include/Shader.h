#ifndef SHADER_H
#define SHADER_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
    Shader();
    Shader(const char* vPath, const char* fPath);
    ~Shader();

    void Use();

    unsigned int GetID();

    void SetBool(const char* name, bool value) const;
    void SetInt(const char* name, int value) const;
    void SetFloat(const char* name, float value) const;
    void SetMat4(const char* name, glm::mat4 value) const;

private:
    unsigned int ID;
};

#endif
