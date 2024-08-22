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
        UI::Run();
        Renderer::Render();
        UI::Render(*Renderer::GetData().m_FBO);
        Renderer::End();
    }
}

void Engine::Shutdown()
{
    Renderer::Shutdown();
}


