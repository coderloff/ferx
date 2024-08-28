#include "Engine.h"
#include "Input.h"

bool Input::IsKeyPressed(const KeyCode key)
{
    return glfwGetKey(Engine::Get().GetWindow().GetWindow(), key) == GLFW_PRESS;
}

bool Input::IsMouseButtonPressed(const MouseCode button)
{
    return glfwGetMouseButton(Engine::Get().GetWindow().GetWindow(), button) == GLFW_PRESS;
}

glm::vec2 Input::GetMousePosition()
{
    double xPos, yPos;
    glfwGetCursorPos(Engine::Get().GetWindow().GetWindow(), &xPos, &yPos);

    return { static_cast<float>(xPos), static_cast<float>(yPos) };
}

float Input::GetMouseX()
{
    return GetMousePosition().x;
}

float Input::GetMouseY()
{
    return GetMousePosition().y;
}