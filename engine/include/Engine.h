#ifndef ENGINE_H
#define ENGINE_H

#include <GLFW/glfw3.h>
#include "Graphics.h"

class Engine
{
public:
    Engine();
    ~Engine();

    static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);

    void Initialize(GLFWwindow* window);
    void Render();
    void Shutdown();

private:
    Graphics graphics;
};

#endif
