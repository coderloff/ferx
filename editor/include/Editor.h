#ifndef EDITOR_H
#define EDITOR_H

#include "Engine.h"
#include "UI.h"

class Editor
{
public:
    Editor();
    ~Editor();

    void Initialize();
    void Run();
    void Shutdown();

    GLFWwindow* GetWindow() const;

private:
    GLFWwindow* window;
    Engine engine;
    UI ui;

    void InitializeWindow();
    void InitializeImGui();
};

#endif