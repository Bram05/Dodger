#ifndef VAOS_H
#define VAOS_H

#include <memory>
#include <string>
#include <glm/glm.hpp>

#include "Buffers.h"
#include "Shader.h"
#include "Texture.h"

class SquareVao
{
public:
	SquareVao(const std::string& texturepath);
	~SquareVao() {};
	
	void Render(const glm::vec2& centre, const glm::vec2& size, float rotation) const;
	
private:
	unsigned int m_Vao{};
	std::shared_ptr<Shader> m_Shader{};
	std::shared_ptr<VertexBuffer> m_Vbo{};
	std::shared_ptr<IndexBuffer> m_Ibo{};
	std::shared_ptr<Texture> m_Texture{};
};


#endif // VAOS_H
