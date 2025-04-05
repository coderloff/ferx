#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include "GUI.h"

#include "Editor.h"
#include "FrameBuffer.h"
#include "Window.h"

std::string GUI::s_Log;
ImVec4* GUI::s_StyleColors;
WindowScale GUI::s_WindowScale;

GUI::GUI()= default;

GUI::~GUI()= default;

void GUI::Init(GLFWwindow* window)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    LoadConfigs();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();
}

void GUI::LoadConfigs()
{
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    io.IniFilename = EDITOR_RESOURCES_PATH"imgui.ini";

    s_WindowScale = Engine::Get()->GetWindow()->GetScale();

    const float baseFontSize = 14.0f * s_WindowScale.X;
    const float iconFontSize = baseFontSize * 2.0f / 2.4f; // FontAwesome fonts need to have their sizes reduced by 2.0f/3.0f in order to align correctly

    io.Fonts->AddFontFromFileTTF(ENGINE_RESOURCES_PATH"fonts/Ruda-Bold.ttf", baseFontSize);

    static constexpr ImWchar iconsRanges[] = { ICON_MIN_FA, ICON_MAX_16_FA, 0 };
    ImFontConfig iconsConfig;
    iconsConfig.MergeMode = true;
    iconsConfig.PixelSnapH = true;
    iconsConfig.GlyphMinAdvanceX = iconFontSize;
    io.Fonts->AddFontFromFileTTF(ENGINE_RESOURCES_PATH"fonts/" FONT_ICON_FILE_NAME_FAS, iconFontSize, &iconsConfig, iconsRanges );

    ImGui::StyleColorsDark();

    ImGuiStyle* style = &ImGui::GetStyle();
    s_StyleColors = style->Colors;

    style->WindowMenuButtonPosition = ImGuiDir_None;
    style->WindowBorderSize = 0.0f * s_WindowScale.X;
    style->GrabRounding = 4.0f * s_WindowScale.X;
    style->WindowRounding = 6.0f * s_WindowScale.X;
    style->FrameRounding = 4.0f * s_WindowScale.X;
    style->FramePadding = ImVec2(5.0f * s_WindowScale.X, 5.0f * s_WindowScale.X);
    style->PopupBorderSize = 0.0f * s_WindowScale.X;
    style->PopupRounding = 4.0f * s_WindowScale.X;
    style->SeparatorTextPadding = ImVec2(5.0f * s_WindowScale.X, 5.0f * s_WindowScale.X);
    style->TabBarBorderSize = 2.0f * s_WindowScale.X;
    style->TabBarOverlineSize = 1.5f * s_WindowScale.X;

    s_StyleColors[ImGuiCol_WindowBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.0f);
    s_StyleColors[ImGuiCol_DockingEmptyBg] = ImVec4(0.06f, 0.06f, 0.06f, 1.0f);
    s_StyleColors[ImGuiCol_Border] = ImVec4(0.06f, 0.06f, 0.06f, 1.0f);
    s_StyleColors[ImGuiCol_PopupBg] = ImVec4(0.06f, 0.06f, 0.06f, 1.0f);
    s_StyleColors[ImGuiCol_FrameBg] = ImVec4(0.09f, 0.09f, 0.09f, 1.0f);
    s_StyleColors[ImGuiCol_FrameBgHovered] = ImVec4(0.03f, 0.03f, 0.03f, 0.8f);
    s_StyleColors[ImGuiCol_FrameBgActive] = ImVec4(0.03f, 0.03f, 0.03f, 1.0f);
    s_StyleColors[ImGuiCol_TitleBg] = ImVec4(0.06f, 0.06f, 0.06f, 1.0f);
    s_StyleColors[ImGuiCol_TitleBgActive] = ImVec4(0.06f, 0.06f, 0.06f, 1.0f);
    s_StyleColors[ImGuiCol_MenuBarBg] = ImVec4(0.11f, 0.11f, 0.11f, 1.0f);
    s_StyleColors[ImGuiCol_Header] = ImVec4(0.08f, 0.08f, 0.08f, 1.0f);
    s_StyleColors[ImGuiCol_HeaderHovered] = ImVec4(0.08f, 0.42f, 0.14f, 0.8f);
    s_StyleColors[ImGuiCol_HeaderActive] = ImVec4(0.08f, 0.42f, 0.14f, 1.0f);
    s_StyleColors[ImGuiCol_Separator] = ImVec4(0.08f, 0.42f, 0.14f, 0.3f);
    s_StyleColors[ImGuiCol_SeparatorHovered] = ImVec4(0.08f, 0.42f, 0.14f, 0.8f);
    s_StyleColors[ImGuiCol_SeparatorActive] = ImVec4(0.08f, 0.42f, 0.14f, 1.0f);
    s_StyleColors[ImGuiCol_ResizeGrip] = ImVec4(0.08f, 0.42f, 0.14f, 0.2f);
    s_StyleColors[ImGuiCol_ResizeGripHovered] = ImVec4(0.08f, 0.42f, 0.14f, 0.8f);
    s_StyleColors[ImGuiCol_ResizeGripActive] = ImVec4(0.08f, 0.42f, 0.14f, 1.0f);
    s_StyleColors[ImGuiCol_Tab] = ImVec4(0.06f, 0.06f, 0.06f, 1.0f);
    s_StyleColors[ImGuiCol_TabHovered] = ImVec4(0.2f, 0.2f, 0.2f, 0.5f);
    s_StyleColors[ImGuiCol_TabActive] = ImVec4(0.2f, 0.2f, 0.2f, 1.0f);
    s_StyleColors[ImGuiCol_TabUnfocused] = ImVec4(0.06f, 0.06f, 0.06f, 1.0f);
    s_StyleColors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.2f, 0.2f, 0.2f, 1.0f);
    s_StyleColors[ImGuiCol_TabSelectedOverline] = ImVec4(0.08f, 0.42f, 0.14f, 1.0f);
    s_StyleColors[ImGuiCol_DockingPreview] = ImVec4(0.08f, 0.42f, 0.14f, 0.8f);
    s_StyleColors[ImGuiCol_CheckMark] = ImVec4(0.08f, 0.42f, 0.14f, 1.0f);
    s_StyleColors[ImGuiCol_SliderGrab] = ImVec4(0.08f, 0.42f, 0.14f, 0.8f);
    s_StyleColors[ImGuiCol_SliderGrabActive] = ImVec4(0.08f, 0.42f, 0.14f, 1.0f);
    s_StyleColors[ImGuiCol_Button] = ImVec4(0.2f, 0.2f, 0.2f, 1.0f);
    s_StyleColors[ImGuiCol_ButtonHovered] = ImVec4(0.08f, 0.42f, 0.14f, 0.5f);
    s_StyleColors[ImGuiCol_ButtonActive] = ImVec4(0.08f, 0.42f, 0.14f, 1.0f);
    s_StyleColors[ImGuiCol_TextSelectedBg] = ImVec4(0.08f, 0.42f, 0.14f, 0.35f);
    s_StyleColors[ImGuiCol_TextLink] = ImVec4(0.08f, 0.42f, 0.14f, 1.0f);
    s_StyleColors[ImGuiCol_NavCursor] = ImVec4(0.08f, 0.42f, 0.14f, 1.0f);
}

void GUI::Run()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    ImGui::DockSpaceOverViewport(ImGui::GetMainViewport()->ID);
}

void GUI::Render(const FrameBuffer& sceneBuffer)
{
    ShowConsole();
    ShowEntities();
    ShowProperties();
    ShowMenu();
    ShowFiles();
    ShowScene(sceneBuffer);

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void GUI::Shutdown()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void GUI::Print(const std::string& message)
{
    s_Log += message + '\n';
}

void GUI::ShowConsole(){
    ImGui::Begin(ICON_FA_TERMINAL" Console");

    if(ImGui::Button("Clear")){
        s_Log.clear();
    }

    ImGui::SameLine();

    if(ImGui::Button("Debug")){
        Print("Debug message");
    }

    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

    ImGui::Text("%s", s_Log.c_str());

    ImGui::End();
}

void GUI::ShowEntities()
{
    ImGui::Begin(ICON_FA_CUBE" Entities");

    for(const auto& cube : Renderer::GetData().m_Scene->GetCubes())
    {
        ImGui::CollapsingHeader(cube->name.c_str());
    }

    ImGui::End();
}

void GUI::ShowProperties()
{
    ImGui::Begin(ICON_FA_BARS_STAGGERED" Properties");

    if(ImGui::CollapsingHeader("Transform"))
    {
        ImGui::BeginGroup();
        glm::vec3* position = Renderer::GetData().m_Cube->GetPosition();
        glm::vec3* rotation = Renderer::GetData().m_Cube->GetRotation();
        glm::vec3* scale = Renderer::GetData().m_Cube->GetScale();
        ImGui::DragFloat3("Position", glm::value_ptr(*position), 0.2f);
        ImGui::DragFloat3("Rotation", glm::value_ptr(*rotation), 0.4f);
        ImGui::DragFloat3("Scale", glm::value_ptr(*scale), 0.1f);
        ImGui::EndGroup();
    }

    ImGui::NewLine();

    ImGui::BeginGroup();
    ImGui::Text("Colors");
    glm::vec3* shaderColor = Renderer::GetData().m_Cube->GetShaderColor();
    ImGui::ColorEdit3("Shader Color", glm::value_ptr(*shaderColor));
    ImGui::ColorEdit3("Background Color", glm::value_ptr(*Renderer::GetData().m_ClearColor));
    ImGui::EndGroup();

    ImGui::End();
}

void GUI::ShowMenu()
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

void GUI::ShowFiles()
{
    ImGui::Begin(ICON_FA_FOLDER" Files");

    ImGui::End();
}

void GUI::ShowScene(const FrameBuffer& sceneBuffer)
{
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2{0, 0});
    ImGui::Begin(ICON_FA_CLAPPERBOARD" Scene");
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



