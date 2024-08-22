#version 330 core
out vec4 fragColor;

in vec3 ourColor;
uniform vec3 color;

void main()
{
    fragColor = vec4(color, 1.0f) * vec4(ourColor, 1.0f);
}