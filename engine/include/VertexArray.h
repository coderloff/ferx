#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include <glad/glad.h>

class VertexArray
{
public:
    VertexArray();
    ~VertexArray();

    static VertexArray Create();

    void Bind() const;
    static void Unbind();
    void Shutdown() const;

private:
    unsigned int m_VAO{};
};

#endif