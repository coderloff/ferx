#ifndef UI_H
#define UI_H

#include <GLFW/glfw3.h>
#include <imgui.h>
#include <string>

class UI
{
public:
    UI();
    ~UI();

    void Initialize(GLFWwindow* window);
    void Run();
    void Render();
    void Shutdown();

    void Print(const std::string& message);

    void ShowMenu();
    void ShowHierarchy();
    void ShowProject();
    void ShowConsole();
    void ShowScene();
    void ShowInspector();

private:
    ImVec4 clearColor = ImVec4(0.0f, 0.0f, 0.0f, 1.00f);
    ImVec4* styleColors;
    std::string log;
};

#endif
