#include <glad/glad.h>
#include "Renderer.h"
#include "Engine.h"

RendererData Renderer::s_Data;

float Renderer::deltaTime = 0.0f;
float Renderer::lastFrame = 0.0f;

bool Renderer::firstMouse = true;
float Renderer::lastX;
float Renderer::lastY;

float vertices[] = {
    -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 0.0f,
};

unsigned int indices[] = {
    0, 1, 2, 2, 3, 0,
    4, 5, 6, 6, 7, 4,
    0, 1, 5, 5, 4, 0,
    2, 3, 7, 7, 6, 2,
    0, 3, 7, 7, 4, 0,
    1, 2, 6, 6, 5, 1
};

Renderer::Renderer() = default;

Renderer::~Renderer()
{
    Shutdown();
}

void Renderer::Init()
{
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return;
    }

    UI::Init(Engine::Get().GetWindow().GetWindow());
    s_Data.m_Camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f));

    LoadShaders();
    SetupBuffers();
    SetCallbacks();
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
    s_Data.m_VAO = new VertexArray();
    s_Data.m_VBO = new VertexBuffer();
    s_Data.m_IBO = new IndexBuffer();

    s_Data.m_VAO->Bind();

    s_Data.m_VBO->SetData(sizeof(vertices), vertices);
    s_Data.m_IBO->SetData(sizeof(indices), indices);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), reinterpret_cast<void*>(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    VertexArray::Unbind();
    VertexBuffer::Unbind();
    IndexBuffer::Unbind();

    s_Data.m_FBO = new FrameBuffer();
    WindowSize windowSize = Engine::Get().GetWindow().GetSize();
    s_Data.m_FBO->AttachTexture(windowSize.Width, windowSize.Height);
    FrameBuffer::Unbind();
}

void Renderer::SetCallbacks()
{
    glfwSetWindowSizeCallback(Engine::Get().GetWindow().GetWindow(), [](GLFWwindow* window, int width, int height)
    {
        SetupBuffers();
    });
    glfwSetFramebufferSizeCallback(Engine::Get().GetWindow().GetWindow(), [](GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    });
    glfwSetScrollCallback(Engine::Get().GetWindow().GetWindow(), [](GLFWwindow* window, double xOffset, double yOffset)
    {
        s_Data.m_Camera->ProcessMouseScroll(static_cast<float>(yOffset));
    });
}

void Renderer::Render() {
    auto currentFrame = static_cast<float>(glfwGetTime());
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    s_Data.m_FBO->Bind();

    glfwPollEvents();
    ProcessInput(Engine::Get().GetWindow().GetWindow());

    glEnable(GL_DEPTH_TEST);
    glm::vec3 color = UI::GetData().m_BgColor;
    glClearColor(color.x, color.y, color.z, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    UI::Run();

    s_Data.m_Shader->Use();

    auto model = glm::mat4(1.0f);
    model = glm::translate(model, UI::GetData().m_Position);
    if(glm::length(UI::GetData().m_Rotation) != 0)
    model = glm::rotate(model, glm::radians(length(UI::GetData().m_Rotation)), normalize(UI::GetData().m_Rotation));
    model = glm::scale(model, UI::GetData().m_Scale);
    glm::mat4 view = s_Data.m_Camera->GetViewMatrix();

    WindowSize size = Engine::Get().GetWindow().GetSize();
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), static_cast<float>(size.Width) / static_cast<float>(size.Height), 0.1f, 100.0f);

    glUniformMatrix4fv(s_Data.m_Shader->GetUniformLocation("model"), 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(s_Data.m_Shader->GetUniformLocation("view"), 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(s_Data.m_Shader->GetUniformLocation("projection"), 1, GL_FALSE, glm::value_ptr(projection));
    glUniform3fv(s_Data.m_Shader->GetUniformLocation("color"), 1, glm::value_ptr(UI::GetData().m_ShaderColor));

    s_Data.m_VAO->Bind();

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    UI::Render(*s_Data.m_FBO);

    glfwSwapBuffers(Engine::Get().GetWindow().GetWindow());
}

void Renderer::ProcessInput(GLFWwindow *window)
{
    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_2) == GLFW_PRESS)
    {
        double xPosIn, yPosIn;
        glfwGetCursorPos(window, &xPosIn, &yPosIn);

        auto xPos = static_cast<float>(xPosIn);
        auto yPos = static_cast<float>(yPosIn);

        if(firstMouse)
        {
            lastX = xPos;
            lastY = yPos;
            firstMouse = false;
        }

        float xOffset = xPos - lastX;
        float yOffset = lastY - yPos;

        lastX = xPos;
        lastY = yPos;

        s_Data.m_Camera->ProcessMouseMovement(xOffset, yOffset);

        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    }
    else
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        s_Data.m_Camera->ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        s_Data.m_Camera->ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        s_Data.m_Camera->ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        s_Data.m_Camera->ProcessKeyboard(RIGHT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        s_Data.m_Camera->ProcessKeyboard(DOWN, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        s_Data.m_Camera->ProcessKeyboard(UP, deltaTime);

}

void Renderer::Shutdown()
{
    s_Data.m_VAO->Shutdown();
    s_Data.m_VBO->Shutdown();
    s_Data.m_FBO->Shutdown();
    s_Data.m_IBO->Shutdown();
    s_Data.m_Shader->Shutdown();
}
