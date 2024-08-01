#ifndef RENDERER_H
#define RENDERER_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <iostream>
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "FrameBuffer.h"
#include "Window.h"
#include "Shader.h"
#include "UI.h"

struct RendererData
{
    VertexArray* m_VAO;
    VertexBuffer* m_VBO;
    FrameBuffer* m_FBO;
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

    static RendererData s_Data;

private:
    static void LoadShaders();
    static void SetupBuffers();
};

#endif