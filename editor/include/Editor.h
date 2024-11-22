#pragma once

#define GLFW_INCLUDE_NONE
#include "Engine.h"
#include "GUI.h"

class Editor
{
public:
    Editor();
    ~Editor();

    static void Init();
    static void Run();
    static void Shutdown();

    static Editor* GetInstance();
    static Engine* GetEngine();

private:
    static Editor* s_Instance;
    static Engine* s_Engine;
};