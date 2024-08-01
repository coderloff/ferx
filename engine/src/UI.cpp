#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include "UI.h"
#include "FrameBuffer.h"
#include "Window.h"

static ImVec4 m_ClearColor;
static ImVec4* m_StyleColors;
static std::string m_Log;

UI::UI()= default;

UI::~UI()= default;

void UI::Init(GLFWwindow* window)
{
    m_ClearColor = ImVec4(0.0f, 0.0f, 0.0f, 1.00f);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    ImGuiStyle& style = ImGui::GetStyle();
    m_StyleColors = style.Colors;
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();
}

void UI::Run()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
    m_StyleColors[ImGuiCol_DockingEmptyBg] = m_ClearColor;
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
    m_Log = message;
}

void UI::ShowConsole(){
    ImGui::Begin("Console");

    if(ImGui::Button("Clear")){
        Print("");
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

    ImGui::End();
}

void UI::ShowInspector()
{
    static float f = 0.0f;
    static int counter = 0;

    ImGui::Begin("Inspector");

    ImGui::Text("This is some useful text.");

    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
    ImGui::ColorEdit3("clear color", (float*)&m_ClearColor);

    if (ImGui::Button("Button"))
        counter++;
    ImGui::SameLine();
    ImGui::Text("counter = %d", counter);

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
    ImGui::Begin("Scene");
    {
        ImGui::BeginChild("GameRender");

        ImGui::Image(
            (ImTextureID)sceneBuffer.GetFrameTexture(),
            ImGui::GetContentRegionAvail(),
            ImVec2(0, 1),
            ImVec2(1, 0)
        );
    }
    ImGui::EndChild();
    ImGui::End();
}



