#pragma once

#define GLFW_INCLUDE_NONE
#include "Engine.h"
#include "UI.h"

class Editor
{
public:
    Editor();
    ~Editor();

    static void Init();
    static void Run();
    static void Shutdown();

private:
    void InitializeImGui();
};