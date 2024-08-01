#ifndef UI_H
#define UI_H

#define GLFW_INCLUDE_NONE
#include "FrameBuffer.h"
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <string>

class UI
{
public:
    UI();
    ~UI();

    static void Init(GLFWwindow* window);
    static void Run();
    static void Render(const FrameBuffer& sceneBuffer);
    static void Shutdown();

    static void Print(const std::string& message);

    static void ShowMenu();
    static void ShowHierarchy();
    static void ShowProject();
    static void ShowConsole();
    static void ShowScene(const FrameBuffer& sceneBuffer);
    static void ShowInspector();
};

#endif
