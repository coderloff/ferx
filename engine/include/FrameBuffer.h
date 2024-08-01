#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <glad/glad.h>
#include <iostream>
#include <glm/glm.hpp>

class FrameBuffer
{
public:
    FrameBuffer();
    FrameBuffer(int width, int height);
    ~FrameBuffer();

    unsigned int GetFrameTexture() const;

    static FrameBuffer Create(int width, int height);

    void RescaleFrameBuffer(int width, int height) const;
    void Bind() const;
    static void Unbind();
    void Shutdown() const;

private:
    unsigned int m_FBO{}, m_RBO{};
    unsigned int m_Texture{};
};

#endif