#include "Engine.h"

Engine::Engine(){}

Engine::~Engine()
{
    Shutdown();
}

void Engine::FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    Graphics::FramebufferSizeCallback(window, width, height);
}

void Engine::Initialize(GLFWwindow* window)
{
    graphics.Initialize(window);
}

void Engine::Render()
{
    graphics.Render();
}

void Engine::Shutdown()
{
    graphics.Shutdown();
}


