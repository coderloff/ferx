#pragma once

#include <glad/glad.h>
#include <stb_image.h>
#include <string>

class Texture
{
public:
    Texture();
    ~Texture();

    void Init();
    void Shutdown() const;
    void Bind() const;
    void GenerateFromImage(const std::string& path);

    static Texture Create();
    static void ToImage(int width, int height, const unsigned char* data);
    static void GenerateMipmaps();

    unsigned int GetID() const;
    unsigned char* GetTexture() const;
    int GetWidth() const;
    int GetHeight() const;
    int GetNrChannels() const;

private:
    unsigned int m_Texture{};
    unsigned char* m_Data{};
    int m_Width{}, m_Height{}, m_NrChannels{};
};