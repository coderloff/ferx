#pragma once

#define GLFW_INCLUDE_NONE
#include "Window.h"

class Engine
{
public:
    Engine();
    ~Engine();

    Window* GetWindow() const { return m_Window; }

    static Engine* Get() { return s_Instance; }

    static void Run();
    void Render();
    static void Shutdown();

private:
    Window* m_Window;
    static Engine* s_Instance;
};