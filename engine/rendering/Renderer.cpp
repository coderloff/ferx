#include "Renderer.h"
#include "Engine.h"

RendererData Renderer::s_Data;

float Renderer::s_DeltaTime = 0.0f;
float Renderer::s_LastFrame = 0.0f;

bool Renderer::s_FirstMouse = true;
float Renderer::s_LastX;
float Renderer::s_LastY;

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

    SetVariables();
    LoadShaders();
    SetupBuffers();
    SetCallbacks();
}

void Renderer::SetVariables()
{
    s_Data.m_Scene = new Scene();
    s_Data.m_Camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f));
    s_Data.m_Cube = new Cube("Cube");
    s_Data.m_ClearColor = new glm::vec3(0.0f, 0.1f, 0.2f);

    s_Data.m_Scene->AddCube(std::shared_ptr<Cube>(s_Data.m_Cube));
}

RendererData& Renderer::GetData()
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

    s_Data.m_VBO->SetData(sizeof(float) * Cube::GetVertices().size(), Cube::GetVertices().data());
    s_Data.m_IBO->SetData(sizeof(unsigned int) * Cube::GetIndices().size(), Cube::GetIndices().data());

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), reinterpret_cast<void*>(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    VertexArray::Unbind();
    VertexBuffer::Unbind();
    IndexBuffer::Unbind();

    s_Data.m_FBO = new FrameBuffer();
    WindowSize windowSize = Engine::Get()->GetWindow()->GetSize();
    s_Data.m_FBO->AttachTexture(windowSize.Width, windowSize.Height);
    FrameBuffer::Unbind();
}

void Renderer::SetCallbacks()
{
    glfwSetWindowSizeCallback(Engine::Get()->GetWindow()->GetNativeWindow(), [](GLFWwindow* window, int width, int height)
    {
        SetupBuffers();
    });
    glfwSetFramebufferSizeCallback(Engine::Get()->GetWindow()->GetNativeWindow(), [](GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    });
    glfwSetScrollCallback(Engine::Get()->GetWindow()->GetNativeWindow(), [](GLFWwindow* window, double xOffset, double yOffset)
    {
        s_Data.m_Camera->ProcessMouseScroll(static_cast<float>(yOffset));
    });
}

void Renderer::Render() {
    auto currentFrame = static_cast<float>(glfwGetTime());
    s_DeltaTime = currentFrame - s_LastFrame;
    s_LastFrame = currentFrame;

    s_Data.m_FBO->Bind();

    glfwPollEvents();
    ProcessInput(Engine::Get()->GetWindow()->GetNativeWindow());

    glEnable(GL_DEPTH_TEST);

    glClearColor(s_Data.m_ClearColor->x, s_Data.m_ClearColor->y, s_Data.m_ClearColor->z, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    s_Data.m_Shader->Use();

    s_Data.m_Cube->Draw();

    const glm::mat4& model = *s_Data.m_Cube->GetModelMatrix();
    const glm::mat4& view = s_Data.m_Camera->GetViewMatrix();

    WindowSize size = Engine::Get()->GetWindow()->GetSize();
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), static_cast<float>(size.Width) / static_cast<float>(size.Height), 0.1f, 100.0f);

    glUniformMatrix4fv(s_Data.m_Shader->GetUniformLocation("model"), 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(s_Data.m_Shader->GetUniformLocation("view"), 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(s_Data.m_Shader->GetUniformLocation("projection"), 1, GL_FALSE, glm::value_ptr(projection));
    glUniform3fv(s_Data.m_Shader->GetUniformLocation("color"), 1, glm::value_ptr(*s_Data.m_Cube->GetShaderColor()));

    *s_Data.m_Cube->GetModelMatrix() = glm::mat4(1.0f);

    s_Data.m_VAO->Bind();

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    glfwSwapBuffers(Engine::Get()->GetWindow()->GetNativeWindow());
}

void Renderer::ProcessInput(GLFWwindow *window)
{
    if(Input::IsMouseButtonPressed(ButtonRight))
    {
        auto mousePos = Input::GetMousePosition();

        if(s_FirstMouse)
        {
            s_LastX = mousePos.x;
            s_LastY = mousePos.y;
            s_FirstMouse = false;
        }

        float xOffset = mousePos.x - s_LastX;
        float yOffset = s_LastY - mousePos.y;

        s_LastX = mousePos.x;
        s_LastY = mousePos.y;

        s_Data.m_Camera->ProcessMouseMovement(xOffset, yOffset);

        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    }
    else
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }

    if (Input::IsKeyPressed(W))
        s_Data.m_Camera->ProcessKeyboard(FORWARD, s_DeltaTime);
    if (Input::IsKeyPressed(S))
        s_Data.m_Camera->ProcessKeyboard(BACKWARD, s_DeltaTime);
    if (Input::IsKeyPressed(A))
        s_Data.m_Camera->ProcessKeyboard(LEFT, s_DeltaTime);
    if (Input::IsKeyPressed(D))
        s_Data.m_Camera->ProcessKeyboard(RIGHT, s_DeltaTime);
    if (Input::IsKeyPressed(Q))
        s_Data.m_Camera->ProcessKeyboard(DOWN, s_DeltaTime);
    if (Input::IsKeyPressed(E))
        s_Data.m_Camera->ProcessKeyboard(UP, s_DeltaTime);
}

void Renderer::Shutdown()
{
    s_Data.m_VAO->Shutdown();
    s_Data.m_VBO->Shutdown();
    s_Data.m_FBO->Shutdown();
    s_Data.m_IBO->Shutdown();
    s_Data.m_Shader->Shutdown();
}
