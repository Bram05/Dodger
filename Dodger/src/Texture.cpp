#include "Texture.h"

#include "stb_image/stb_image.h"
#include <glad/glad.h>
#include <iostream>

Texture::Texture(const std::string& filepath)
	: m_Texture{}
{
	stbi_set_flip_vertically_on_load(true);
	int width, height, channels;
	unsigned char* data{stbi_load(filepath.c_str(), &width, &height, &channels, 0)};
	if (!data)
	{
		std::cerr << "Texture " << filepath << " does not exist!\n";
		return;
	}
	
	int format;
	if (channels == 3) format = GL_RGB;
	else if (channels == 4) format = GL_RGBA;
	else
	{
		std::cerr << "Num channels (=" << channels << ") in texture " << filepath << " is not supported!\n";
		return;
	}
	
	glGenTextures(1, &m_Texture);
	glBindTexture(GL_TEXTURE_2D, m_Texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, static_cast<unsigned int>(format), GL_UNSIGNED_BYTE, data);
	
	stbi_image_free(data);
}

Texture::~Texture()
{
	glDeleteTextures(1, &m_Texture);
}

void Texture::Bind(unsigned int unit/* = 0*/) const
{
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, m_Texture);
}

