#include <iostream>
#include "Editor.h"
#include "UI.h"

Editor::Editor() : window(nullptr){}

Editor::~Editor()
{
    Shutdown();
}

void Editor::Initialize()
{
    InitializeWindow();
    engine.Initialize(window);
    ui.Initialize(window);
    Run();
}

void Editor::Run() {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        ui.Run();
        engine.Render();
        ui.Render();
        glfwSwapBuffers(window);
    }
}

void Editor::Shutdown() {
    engine.Shutdown();
    ui.Shutdown();
    glfwDestroyWindow(window);
    glfwTerminate();
}

GLFWwindow* Editor::GetWindow() const {
    return window;
}

void Editor::InitializeWindow() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(1280, 720, "Editor", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);
}