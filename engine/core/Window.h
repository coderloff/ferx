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
    WindowSize(const int width, const int height): Width(width), Height(height){}
};

struct WindowScale
{
    float X, Y;

    WindowScale(): X(1), Y(1){}
};

struct WindowData
{
    std::string Title;
    WindowSize Size;
    WindowScale Scale;

    WindowData(): Title("Ferx Engine"), Size(900, 600){}
    WindowData(const std::string& title, const int width, const int height): Title(title), Size(width, height){};
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
    WindowScale GetScale();

	void SetWindowIcon() const;
    void Shutdown() const;

private:
    GLFWwindow* m_Window{};
    WindowData m_Data;
};
