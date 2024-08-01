#include <glad/glad.h>
#include "Renderer.h"
#include "Engine.h"

RendererData Renderer::s_Data;

Renderer::Renderer() = default;

Renderer::~Renderer()
{
    Shutdown();
}

void Renderer::Init()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return;
    }

    LoadShaders();
    SetupBuffers();
}

void Renderer::LoadShaders()
{
    s_Data.m_Shader = new Shader(RESOURCES_PATH"shaders/shader.vs", RESOURCES_PATH"shaders/shader.fs");
}

void Renderer::SetupBuffers()
{
    float vertices[] = {
         0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
         0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f
    };

    s_Data.m_FBO = new FrameBuffer(FrameBuffer::Create(Engine::Get().GetWindow().GetWidth(), Engine::Get().GetWindow().GetHeight()));

    s_Data.m_VAO = new VertexArray();
    s_Data.m_VBO = new VertexBuffer();

    s_Data.m_VAO->Bind();

    s_Data.m_VBO->SetData(sizeof(vertices), vertices);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    VertexArray::Unbind();
    VertexBuffer::Unbind();
}

void Renderer::Render() {
    glClearColor(0.0f, 0.1f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    s_Data.m_FBO->Bind();

    s_Data.m_Shader->Use();
    s_Data.m_VAO->Bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
    FrameBuffer::Unbind();
}

void Renderer::Shutdown()
{
    s_Data.m_VAO->Shutdown();
    s_Data.m_VBO->Shutdown();
    s_Data.m_FBO->Shutdown();
    s_Data.m_Shader->Shutdown();
}
