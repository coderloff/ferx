#pragma once

#define GLFW_INCLUDE_NONE
#include "FrameBuffer.h"
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <string>
#include <IconsFontAwesome6.h>

struct WindowScale;

class GUI
{
public:
    GUI();
    ~GUI();

    static void Init(GLFWwindow* window);
    static void LoadConfigs();
    static void Run();
    static void Render(const FrameBuffer& sceneBuffer);
    static void Shutdown();

    static void Print(const std::string& message);

    static void ShowMenu();
    static void ShowEntities();
    static void ShowFiles();
    static void ShowConsole();
    static void ShowScene(const FrameBuffer& sceneBuffer);
    static void ShowProperties();

private:
    static std::string s_Log;
    static ImVec4* s_StyleColors;
    static WindowScale s_WindowScale;
};
