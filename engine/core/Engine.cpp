#include "Engine.h"

Engine* Engine::s_Instance = nullptr;

Engine::Engine()
{
    s_Instance = this;

    m_Window = new Window();

    Renderer::Init();
}

Engine::~Engine()
{
    Shutdown();
}

void Engine::Run()
{
    Renderer::Render();
}

void Engine::Shutdown()
{
    Renderer::Shutdown();
}


