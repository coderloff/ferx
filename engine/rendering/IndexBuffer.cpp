#include "IndexBuffer.h"

IndexBuffer::IndexBuffer()
{
    glGenBuffers(1, &m_IBO);
}

IndexBuffer::~IndexBuffer()
{
    Shutdown();
}

IndexBuffer IndexBuffer::Create()
{
    return IndexBuffer{};
}

void IndexBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
}
void IndexBuffer::Unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::SetData(int size, const void* data) const
{
    Bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void IndexBuffer::Shutdown() const
{
    glDeleteBuffers(1, &m_IBO);
}
