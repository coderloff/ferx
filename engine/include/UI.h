#pragma once

#define GLFW_INCLUDE_NONE
#include "FrameBuffer.h"
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <string>
#include <IconsFontAwesome6.h>

struct InspectorData
{
    glm::vec3 m_Position;
    glm::vec3 m_Rotation;
    glm::vec3 m_Scale = {1.0f, 1.0f, 1.0f};
    glm::vec3 m_ShaderColor = {1.0f, 1.0f, 1.0f};
    glm::vec3 m_BgColor = {0.0, 0.1f, 0.2f};
};

class UI
{
public:
    UI();
    ~UI();

    static void Init(GLFWwindow* window);
    static void LoadConfigs();
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

    static std::string m_Log;
    static ImVec4* m_StyleColors;
};