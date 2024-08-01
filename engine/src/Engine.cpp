#include "Engine.h"

Engine* Engine::s_Instance = nullptr;

Engine::Engine()
{
    s_Instance = this;

    m_Window = new Window();

    Renderer::Init();
    UI::Init(m_Window->GetWindow());
}

Engine::~Engine()
{
    Shutdown();
}

void Engine::Run()
{
    while (!glfwWindowShouldClose(m_Window->GetWindow())) {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        UI::Run();
        Renderer::Render();
        UI::Render(*Renderer::s_Data.m_FBO);
        glfwSwapBuffers(m_Window->GetWindow());
        glfwPollEvents();
    }
}

void Engine::Shutdown()
{
    Renderer::Shutdown();
}


