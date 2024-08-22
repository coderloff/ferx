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

RendererData Renderer::GetData()
{
    return s_Data;
}

void Renderer::LoadShaders()
{
    s_Data.m_Shader = new Shader(RESOURCES_PATH"shaders/vertex.glsl", RESOURCES_PATH"shaders/fragment.glsl");
}

void Renderer::SetupBuffers()
{
    float vertices[] = {
         0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
         0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f
    };

    s_Data.m_FBO = new FrameBuffer();
    s_Data.m_FBO->AttachTexture(Engine::Get().GetWindow().GetWidth(), Engine::Get().GetWindow().GetHeight());

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
    auto transform = glm::mat4(1.0f);
    transform = glm::translate(transform, glm::vec3(UI::GetData().m_Position[0], UI::GetData().m_Position[1], UI::GetData().m_Position[2]));
    s_Data.m_Shader->SetMat4("transform", transform);
    glUniform3fv(glGetUniformLocation(s_Data.m_Shader->GetID(), "color"), 1, UI::GetData().m_Color);
    s_Data.m_VAO->Bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
    FrameBuffer::Unbind();
}

void Renderer::End()
{
    glfwSwapBuffers(Engine::Get().GetWindow().GetWindow());
    glfwPollEvents();
}

void Renderer::Shutdown()
{
    s_Data.m_VAO->Shutdown();
    s_Data.m_VBO->Shutdown();
    s_Data.m_FBO->Shutdown();
    s_Data.m_Shader->Shutdown();
}
