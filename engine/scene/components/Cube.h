#pragma once

#include <string>
#include <glm/vec3.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <glm/glm.hpp>

class Cube{
public:
  Cube(const std::string& cubeName);

  void Draw() const;

  void SetPosition(const glm::vec3& newPosition){ *m_Position = newPosition; }
  glm::vec3* GetPosition() const{ return m_Position; }

  void SetRotation(const glm::vec3& newRotation){ *m_Rotation = newRotation; }
  glm::vec3* GetRotation() const{ return m_Rotation; }

  void SetScale(const glm::vec3& newScale){ *m_Scale = newScale; }
  glm::vec3* GetScale() const{ return m_Scale; }

  glm::mat4* GetModelMatrix() const{ return m_ModelMatrix; }
  glm::vec3* GetShaderColor() const{ return m_ShaderColor; }
  static std::vector<float>& GetVertices() { return s_Vertices; }
  static std::vector<unsigned int>& GetIndices() { return s_Indices; }

  std::string name;

private:
  static std::vector<float> s_Vertices;
  static std::vector<unsigned int> s_Indices;

  glm::vec3* m_Position = new glm::vec3{0.0f, 0.0f, 0.0f};
  glm::vec3* m_Rotation = new glm::vec3{0.0f, 0.0f, 0.0f};
  glm::vec3* m_Scale = new glm::vec3{1.0f, 1.0f, 1.0f};

  glm::mat4* m_ModelMatrix = new glm::mat4(1.0f);
  glm::vec3* m_ShaderColor = new glm::vec3(1.0f, 1.0f, 1.0f);
};
