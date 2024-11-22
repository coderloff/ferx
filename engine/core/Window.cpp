#include "Window.h"

Window::Window()
{
    Init();
}

Window::Window(const std::string& title, int width, int height)
{
    m_Data = WindowData{title, width, height};
    Init();
}

Window::~Window()
{
    Shutdown();
}

void Window::Init()
{
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return;
    }

    std::cout << "GLFW Initialized" << std::endl;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_Window = glfwCreateWindow(m_Data.Size.Width, m_Data.Size.Height, m_Data.Title.c_str(), nullptr, nullptr);
    if (!m_Window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(m_Window);
}

Window Window::Create()
{
    return Window{};
}

Window Window::Create(const std::string& title, int width, int height)
{
    return Window{title, width, height};
}

GLFWwindow* Window::GetNativeWindow() const
{
    return m_Window;
}

const std::string& Window::GetTitle() const
{
    return m_Data.Title;
}

WindowSize Window::GetSize()
{
    glfwGetWindowSize(m_Window, &m_Data.Size.Width, &m_Data.Size.Height);
    return m_Data.Size;
}

void Window::Shutdown() const
{
    glfwDestroyWindow(m_Window);
}
