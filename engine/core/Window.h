#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include <Renderer.h>

struct WindowSize
{
    int Width, Height;

    WindowSize(): Width(0), Height(0){}
    WindowSize(int width, int height): Width(width), Height(height){}
};

struct WindowData
{
    std::string Title;
    WindowSize Size;

    WindowData(): Title("Ferx Engine"), Size(900, 600){}
    WindowData(const std::string& title, int width, int height): Title(title), Size(width, height){};
};

class Window
{
public:
    Window();
    Window(const std::string& title, int width, int height);
    ~Window();

    static Window Create();
    static Window Create(const std::string& title, int width, int height);

    void Init();

    GLFWwindow* GetNativeWindow() const;
    const std::string& GetTitle() const;
    WindowSize GetSize();

    void Shutdown() const;

private:
    GLFWwindow* m_Window{};
    WindowData m_Data;
};