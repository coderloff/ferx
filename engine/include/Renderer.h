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
#include "Shader.h"
#include "Texture.h"
#include "UI.h"
#include "Camera.h"

struct RendererData
{
    VertexArray* m_VAO;
    VertexBuffer* m_VBO;
    IndexBuffer* m_IBO;
    FrameBuffer* m_FBO;
    Camera* m_Camera;
    Shader* m_Shader;
};

class Renderer
{
public:
    Renderer();
    ~Renderer();

    static void Init();
    static void Render();
    static void Shutdown();

    static RendererData GetData();

private:
    static RendererData s_Data;

    static void LoadShaders();
    static void SetupBuffers();
    static void SetCallbacks();
    static void ProcessInput(GLFWwindow* window);

    static float deltaTime;
    static float lastFrame;

    static bool firstMouse;
    static float lastX;
    static float lastY;
};