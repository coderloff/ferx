#include "VertexArray.h"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_VAO);
}

VertexArray::~VertexArray()
{
    Shutdown();
}

VertexArray VertexArray::Create()
{
    return VertexArray{};
}

void VertexArray::Bind() const
{
    glBindVertexArray(m_VAO);
}

void VertexArray::Unbind()
{
    glBindVertexArray(0);
}

void VertexArray::Shutdown() const
{
    glDeleteVertexArrays(1, &m_VAO);
}
