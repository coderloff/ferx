#pragma once

#include <glad/glad.h>

class VertexBuffer
{
public:
    VertexBuffer();
    ~VertexBuffer();

    static VertexBuffer Create();

    void Bind() const;
    static void Unbind();
    void SetData(int size, const void* data) const;
    void Shutdown() const;

private:
    unsigned int m_VBO{};
};