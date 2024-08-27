#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include "UI.h"
#include "FrameBuffer.h"
#include "Window.h"

InspectorData UI::s_Data;
std::string UI::m_Log;
ImVec4* UI::m_StyleColors;

UI::UI()= default;

UI::~UI()= default;

void UI::Init(GLFWwindow* window)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowBorderSize = 0;
    style.WindowMenuButtonPosition = 1;
    style.FrameRounding = 4;
    style.GrabRounding = 4;
    style.WindowRounding = 6;
    m_StyleColors = style.Colors;
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();
}

InspectorData UI::GetData()
{
    return s_Data;
}

void UI::Run()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
    m_StyleColors[ImGuiCol_DockingEmptyBg] = ImVec4(s_Data.m_BgColor.x, s_Data.m_BgColor.y, s_Data.m_BgColor.z, 1.0f);
}

void UI::Render(const FrameBuffer& sceneBuffer)
{
    ShowConsole();
    ShowHierarchy();
    ShowInspector();
    ShowMenu();
    ShowProject();
    ShowScene(sceneBuffer);

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UI::Shutdown()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void UI::Print(const std::string& message)
{
    m_Log += message + '\n';
}

void UI::ShowConsole(){
    ImGui::Begin("Console");

    if(ImGui::Button("Clear")){
        m_Log.clear();
    }

    ImGui::SameLine();

    if(ImGui::Button("Debug")){
        Print("Debug message");
    }

    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

    ImGui::Text("%s", m_Log.c_str());

    ImGui::End();
}

void UI::ShowHierarchy()
{
    ImGui::Begin("Hierarchy");

    ImGui::CollapsingHeader("Triangle");

    ImGui::End();
}

void UI::ShowInspector()
{
    ImGui::Begin("Inspector");

    ImGui::SeparatorText("Cube");

    ImGui::BeginGroup();
    {
        ImGui::Text("Transform");
        ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(1.0f, 0.0f, 0.0f, 1.0f));
        ImGui::DragFloat3("Position", glm::value_ptr(s_Data.m_Position), 0.2f);
        ImGui::PopStyleColor();
        ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.0f, 1.0f, 0.0f, 1.0f));
        ImGui::DragFloat3("Rotation", glm::value_ptr(s_Data.m_Rotation), 0.4f);
        ImGui::PopStyleColor();
        ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.0f, 0.0f, 1.0f, 1.0f));
        ImGui::DragFloat3("Scale", glm::value_ptr(s_Data.m_Scale), 0.1f);
        ImGui::PopStyleColor();
    }
    ImGui::EndGroup();

    ImGui::NewLine();

    ImGui::BeginGroup();
    ImGui::Text("Colors");
    ImGui::ColorEdit3("Shader Color", glm::value_ptr(s_Data.m_ShaderColor));
    ImGui::ColorEdit3("Background Color", glm::value_ptr(s_Data.m_BgColor));
    ImGui::EndGroup();

    ImGui::End();
}

void UI::ShowMenu()
{
    if(ImGui::BeginMainMenuBar()){
        if(ImGui::BeginMenu("File")){
            if (ImGui::MenuItem("Open..", "Ctrl+O")) { }
            if (ImGui::MenuItem("Save", "Ctrl+S"))   { }
            if (ImGui::MenuItem("Close", "Ctrl+W"))  { }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

void UI::ShowProject()
{
    ImGui::Begin("Project");

    ImGui::End();
}

void UI::ShowScene(const FrameBuffer& sceneBuffer)
{
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2{0, 0});
    ImGui::Begin("Scene");
    {
        ImGui::Image(
            (ImTextureID)sceneBuffer.GetFrameTexture()->GetID(),
            ImGui::GetContentRegionAvail(),
            ImVec2(0, 1),
            ImVec2(1, 0)
        );
    }
    ImGui::End();
    ImGui::PopStyleVar();
}



