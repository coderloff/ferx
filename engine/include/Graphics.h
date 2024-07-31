#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <GLFW/glfw3.h>
#include "Shader.h"

class Graphics
{
public:
    Graphics();
    ~Graphics();

    static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);

    void Initialize(GLFWwindow* window);
    void Render();
    void Shutdown();

private:
    GLFWwindow* window;
    Shader shader;
    unsigned int VAO, VBO;

    void LoadShaders();
    void SetupBuffers();
};

#endif