#include "Vaos.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

constexpr float g_SquareVertexData[] {
	// position			// tex coords
	-0.5f, -0.5f, 0.0f,	0.0f, 0.0f, 
	 0.5f, -0.5f, 0.0f,	1.0f, 0.0f, 
	 0.5f,  0.5f, 0.0f,	1.0f, 1.0f, 
	-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
};
constexpr unsigned int g_SquareIndices[] {0, 1, 2, 2, 3, 0};

SquareVao::SquareVao(const std::string& texturepath)
{
	glGenVertexArrays(1, &m_Vao);
	glBindVertexArray(m_Vao);
	
	m_Shader = std::make_shared<Shader>("res/shaders/Basic.glsl");
	m_Vbo = std::make_shared<VertexBuffer>(g_SquareVertexData, sizeof(g_SquareVertexData));
	m_Ibo = std::make_shared<IndexBuffer>(g_SquareIndices, sizeof(g_SquareIndices));
	m_Texture = std::make_shared<Texture>(texturepath);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), nullptr);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (int*)(3*sizeof(float)));
}

void SquareVao::Render(const glm::vec2& centre, const glm::vec2& size, float angle)
{
	m_Shader->Bind();	// Binding this for every enemy is unnecesary
	glm::mat4 view = glm::ortho(0.0f, 1.0f, 0.0f, 1.0f);
	glm::mat4 model = glm::translate(glm::mat4(1.0f), {centre, 0.0f});
	model = glm::scale(model, glm::vec3(size.x, size.y, 1.0f));
	model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
	m_Shader->SetUniform("u_VM", view * model);
	m_Texture->Bind(0);
	m_Shader->SetUniform("u_Texture", 0);
	glDrawElements(GL_TRIANGLES, static_cast<int>(m_Ibo->GetCount()), GL_UNSIGNED_INT, nullptr);
}

