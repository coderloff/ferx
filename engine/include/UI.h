#pragma once

#define GLFW_INCLUDE_NONE
#include "FrameBuffer.h"
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <string>

struct InspectorData
{
    float m_Position[3];
    float m_Rotation[3];
    float m_Scale[3];
    float m_Color[3] = {1.0f, 1.0f, 1.0f};
};

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
    static InspectorData GetData();

    static void ShowMenu();
    static void ShowHierarchy();
    static void ShowProject();
    static void ShowConsole();
    static void ShowScene(const FrameBuffer& sceneBuffer);
    static void ShowInspector();

private:
    static InspectorData s_Data;
};