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
#if defined(_WIN32)
	// Add Windows-specific configuration if needed
#elif defined(__linux__)
    glfwWindowHintString(GLFW_X11_CLASS_NAME, "ferx");
    glfwWindowHintString(GLFW_X11_INSTANCE_NAME, "Ferx");
#endif

    m_Window = glfwCreateWindow(m_Data.Size.Width, m_Data.Size.Height, m_Data.Title.c_str(), nullptr, nullptr);
    if (!m_Window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }

    SetWindowIcon();

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

void Window::SetWindowIcon() const
{
    int width, height, channels;
    const char* iconPath = ENGINE_RESOURCES_PATH"icons/icon.png";

    unsigned char* pixels = stbi_load(iconPath, &width, &height, &channels, 4); // Force RGBA
    if (!pixels) {
        std::cerr << "Failed to load icon: " << iconPath << std::endl;
        return;
    }

    GLFWimage images[1];
    images[0].width = width;
    images[0].height = height;
    images[0].pixels = pixels;

    glfwSetWindowIcon(m_Window, 1, images);

    stbi_image_free(pixels);
}

void Window::Shutdown() const
{
    glfwDestroyWindow(m_Window);
}
