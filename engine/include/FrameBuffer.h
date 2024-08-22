#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <glad/glad.h>
#include <iostream>
#include <Texture.h>
#include <glm/glm.hpp>

class FrameBuffer
{
public:
    FrameBuffer();
    ~FrameBuffer();

    void RescaleFrameBuffer(int width, int height) const;
    void AttachTexture(int width, int height);
    void Bind() const;
    static void Unbind();
    void Shutdown() const;

    static FrameBuffer Create();

    Texture* GetFrameTexture() const;

private:
    unsigned int m_FBO{}, m_RBO{};
    Texture* m_Texture;
};

#endif