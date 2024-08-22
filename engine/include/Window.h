#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include <Renderer.h>

struct WindowData
{
    std::string Title;
    int Width, Height;

    WindowData(): Title("Ferx Engine"), Width(900), Height(600){}
    WindowData(const std::string& title, int width, int height): Title(title), Width(width), Height(height){};
};

class Window
{
public:
    Window();
    Window(const std::string& title, int width, int height);
    ~Window();

    static Window Create();
    static Window Create(const std::string& title, int width, int height);
    static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);

    void Init();

    GLFWwindow* GetWindow() const;
    const std::string& GetTitle() const;
    int GetWidth() const;
    int GetHeight() const;

    void Shutdown();

private:
    GLFWwindow* m_Window{};
    WindowData m_Data;
};