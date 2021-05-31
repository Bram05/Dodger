#include "Player.h"

static constexpr float g_PlayerSpeed{0.4f};

Player::Player(const glm::vec2& position)
	: m_Position{position}, m_Vao{std::make_shared<SquareVao>("res/textures/spaceship.png")}
{
}

Player::~Player()
{
}

void Player::Render() const
{
	m_Vao->Render(m_Position, {m_Size, m_Size}, 0.0f);
}

void Player::Update(GLFWwindow* window, float frameTime)
{
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		m_Position.x -= g_PlayerSpeed * frameTime;
	else if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		m_Position.x += g_PlayerSpeed * frameTime;
		
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		m_Position.y += g_PlayerSpeed * frameTime;
	else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		m_Position.y -= g_PlayerSpeed * frameTime;
		
	if (m_Position.x > 1.0f) m_Position.x = 1.0f;
	if (m_Position.x < 0.0f) m_Position.x = 0.0f;
	
	if (m_Position.y > 1.0f) m_Position.y = 1.0f;
	if (m_Position.y < 0.0f) m_Position.y = 0.0f;
}