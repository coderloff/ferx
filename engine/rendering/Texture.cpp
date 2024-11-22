#include "Texture.h"

Texture::Texture()
{
    Init();
}

Texture::~Texture()
{
    Shutdown();
}

void Texture::Init()
{
    glGenTextures(1, &m_Texture);
    Bind();

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void Texture::Bind() const
{
    glBindTexture(GL_TEXTURE_2D, m_Texture);
}

void Texture::Shutdown() const
{
    glDeleteTextures(1, &m_Texture);
}

void Texture::GenerateFromImage(const std::string& path)
{
    m_Data = stbi_load(path.c_str(), &m_Width, &m_Height, &m_NrChannels, 0);

    if (m_Data)
    {
        ToImage(m_Width, m_Height, m_Data);
        GenerateMipmaps();
    }
    else
    {
        std::cerr << "Failed to load texture: " << path;
    }
    stbi_image_free(m_Data);

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::ToImage(int width, int height, const unsigned char* data)
{
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
}

void Texture::GenerateMipmaps()
{
    glGenerateMipmap(GL_TEXTURE_2D);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
}

Texture Texture::Create()
{
    return Texture{};
}

unsigned int Texture::GetID() const
{
    return m_Texture;
}

int Texture::GetWidth() const
{
    return m_Width;
}

int Texture::GetHeight() const
{
    return m_Height;
}

unsigned char* Texture::GetTexture() const
{
    return m_Data;
}

int Texture::GetNrChannels() const
{
    return m_NrChannels;
}