#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "Renderer.h"
#include "Window.h"
#include "UI.h"

class Engine
{
public:
    Engine();
    ~Engine();

    Window& GetWindow() const { return *m_Window; }

    static Engine& Get() { return *s_Instance; }

    void Run();
    void Render();
    void Shutdown();

private:
    Window* m_Window;
    static Engine* s_Instance;
};