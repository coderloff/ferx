#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <GLFW/glfw3.h>

class Graphics
{
public:
    Graphics();
    ~Graphics();

    void Initialize(GLFWwindow* window);
    void Render();
    void Shutdown();

private:
    GLFWwindow* window;
    unsigned int VAO, VBO;

    void SetupBuffers();
};

#endif