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

    glfwSetWindowSizeCallback(Engine::Get().GetWindow().GetWindow(), [](GLFWwindow* window, int width, int height)
    {
        SetupBuffers();
    });
    glfwSetFramebufferSizeCallback(Engine::Get().GetWindow().GetWindow(), [](GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    });
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
    WindowSize windowSize = Engine::Get().GetWindow().GetSize();
    s_Data.m_FBO->AttachTexture(windowSize.Width, windowSize.Height);

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
    glfwPollEvents();
    glClearColor(0.0f, 0.1f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    UI::Run();

    s_Data.m_FBO->Bind();

    s_Data.m_Shader->Use();
    auto transform = glm::mat4(1.0f);
    transform = glm::translate(transform, glm::vec3(UI::GetData().m_Position[0], UI::GetData().m_Position[1], UI::GetData().m_Position[2]));
    glUniformMatrix4fv(s_Data.m_Shader->GetUniformLocation("transform"), 1, GL_FALSE, glm::value_ptr(transform));
    glUniform3fv(s_Data.m_Shader->GetUniformLocation("color"), 1, UI::GetData().m_Color);
    s_Data.m_VAO->Bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
    FrameBuffer::Unbind();

    UI::Render(*s_Data.m_FBO);

    glfwSwapBuffers(Engine::Get().GetWindow().GetWindow());
}

void Renderer::Shutdown()
{
    s_Data.m_VAO->Shutdown();
    s_Data.m_VBO->Shutdown();
    s_Data.m_FBO->Shutdown();
    s_Data.m_Shader->Shutdown();
    s_Data.m_Texture->Shutdown();
}
