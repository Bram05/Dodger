#include "Vaos.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

constexpr float g_SquareVertexData[] {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.5f,  0.5f, 0.0f,
	-0.5f,  0.5f, 0.0f
};
constexpr unsigned int g_SquareIndices[] {0, 1, 2, 2, 3, 0};

EnemyVao::EnemyVao()
{
	glGenVertexArrays(1, &m_Vao);
	glBindVertexArray(m_Vao);
	
	m_Shader = std::make_shared<Shader>("res/shaders/Basic.glsl");
	m_Vbo = std::make_shared<VertexBuffer>(g_SquareVertexData, sizeof(g_SquareVertexData));
	m_Ibo = std::make_shared<IndexBuffer>(g_SquareIndices, sizeof(g_SquareIndices));
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
}

void EnemyVao::Render(float x, float y)
{
	m_Shader->Bind();	// Binding this for every enemy is unnecesary
	glm::mat4 model = glm::translate(glm::mat4(1.0f), {x, y, 0.0f});
	m_Shader->SetUniform("u_Model", glm::scale(model, glm::vec3(0.1f)));
	glDrawElements(GL_TRIANGLES, static_cast<int>(m_Ibo->GetCount()), GL_UNSIGNED_INT, nullptr);
}

