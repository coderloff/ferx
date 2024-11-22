#pragma once

#include <glad/glad.h>

class IndexBuffer
{
public:
    IndexBuffer();
    ~IndexBuffer();

    static IndexBuffer Create();

    void Bind() const;
    static void Unbind();
    void SetData(int size, const void* data) const;
    void Shutdown() const;

private:
    unsigned int m_IBO{};
};