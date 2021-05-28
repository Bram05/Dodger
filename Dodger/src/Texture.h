#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

class Texture
{
public:
	Texture(const std::string& texturepath);
	~Texture();
	
	void Bind(unsigned int unit = 0) const;

private:
	unsigned int m_Texture;
};

#endif // TEXTURE_H
