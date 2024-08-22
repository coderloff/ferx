#pragma once

#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

class Shader
{
public:
    Shader() = default;
    Shader(const std::string& vPath, const std::string& fPath);
    ~Shader();

    static Shader Create(const std::string& vPath, const std::string& fPath);

    unsigned int GetID() const;

    void Use() const;
    void Shutdown() const;
    void SetBool(const char* name, bool value) const;
    void SetInt(const char* name, int value) const;
    void SetFloat(const char* name, float value) const;
    void SetMat4(const char* name, glm::mat4 value) const;

private:
    unsigned int m_ID;
};