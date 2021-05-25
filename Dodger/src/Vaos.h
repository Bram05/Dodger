#ifndef VAOS_H
#define VAOS_H

#include <memory>

#include "Buffers.h"
#include "Shader.h"

class EnemyVao
{
public:
	EnemyVao();
	~EnemyVao() {};
	
	void Render(float x, float y);
	
private:
	unsigned int m_Vao{};
	std::shared_ptr<Shader> m_Shader;
	std::shared_ptr<VertexBuffer> m_Vbo;
	std::shared_ptr<IndexBuffer> m_Ibo;
};


#endif // VAOS_H
