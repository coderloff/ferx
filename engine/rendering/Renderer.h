#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <iostream>
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "FrameBuffer.h"
#include "Window.h"
#include "Input.h"
#include "Scene.h"
#include "Shader.h"
#include "Texture.h"
#include "Camera.h"
#include "Cube.h"

struct RendererData
{
    VertexArray* m_VAO;
    VertexBuffer* m_VBO;
    IndexBuffer* m_IBO;
    FrameBuffer* m_FBO;
    Scene* m_Scene;
    Shader* m_Shader;
    Camera* m_Camera;
    Cube* m_Cube;

    glm::vec3* m_ClearColor;
};

class Renderer
{
public:
    Renderer();
    ~Renderer();

    static void Init();
    static void Render();
    static void Shutdown();

    static RendererData& GetData();

private:
    static RendererData s_Data;

    static void SetVariables();
    static void LoadShaders();
    static void SetupBuffers();
    static void SetCallbacks();
    static void ProcessInput(GLFWwindow* window);

    static float s_DeltaTime;
    static float s_LastFrame;

    static bool s_FirstMouse;
    static float s_LastX;
    static float s_LastY;
};