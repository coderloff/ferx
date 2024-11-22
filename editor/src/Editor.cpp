#include "Editor.h"

Editor* Editor::s_Instance = nullptr;
Engine* Editor::s_Engine = nullptr;

Editor::Editor()
{
    s_Instance = this;
}

Editor::~Editor()
{
    Shutdown();
}

void Editor::Init()
{
    s_Engine = new Engine();

    GUI::Init(s_Engine->GetWindow()->GetNativeWindow());

    Run();
}

void Editor::Run()
{
    while (!glfwWindowShouldClose(s_Engine->GetWindow()->GetNativeWindow())) {
        s_Engine->Run();
        GUI::Run();
        GUI::Render(*Renderer::GetData().m_FBO);
    }
}

void Editor::Shutdown(){

}