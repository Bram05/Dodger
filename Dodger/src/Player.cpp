#include "Player.h"

static constexpr float g_PlayerSpeed{0.01f};

Player::Player(float x, float y)
	: m_X{x}, m_Y{y}, m_Vao{std::make_shared<SquareVao>()}
{
}

Player::~Player()
{
}

void Player::Render()
{
	m_Vao->Render(m_X, m_Y);
}

void Player::Update(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		m_X -= g_PlayerSpeed;
	else if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		m_X += g_PlayerSpeed;
}