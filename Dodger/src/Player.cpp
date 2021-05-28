#include "Player.h"

static constexpr float g_PlayerSpeed{0.01f};

Player::Player(const glm::vec2& position)
	: m_Position{position}, m_Vao{std::make_shared<SquareVao>("res/textures/spaceship.png")}
{
}

Player::~Player()
{
}

void Player::Render()
{
	m_Vao->Render(m_Position, {m_Size, m_Size}, 0.0f);
}

void Player::Update(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		m_Position.x -= g_PlayerSpeed;
	else if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		m_Position.x += g_PlayerSpeed;
		
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		m_Position.y += g_PlayerSpeed;
	else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		m_Position.y -= g_PlayerSpeed;
}