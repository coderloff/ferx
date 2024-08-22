#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <iostream>
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "FrameBuffer.h"
#include "Window.h"
#include "Shader.h"
#include "Texture.h"
#include "UI.h"

struct RendererData
{
    VertexArray* m_VAO;
    VertexBuffer* m_VBO;
    FrameBuffer* m_FBO;
    Shader* m_Shader;
    Texture* m_Texture;
};

class Renderer
{
public:
    Renderer();
    ~Renderer();

    static void Init();
    static void Render();
    static void End();
    static void Shutdown();

    static RendererData GetData();

private:
    static RendererData s_Data;

    static void LoadShaders();
    static void SetupBuffers();
};