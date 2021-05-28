#include "Enemy.h"

std::shared_ptr<SquareVao> NormalEnemy::s_Vao;
float NormalEnemy::m_Speed{0.005f};
float NormalEnemy::s_Size{0.1f};

NormalEnemy::NormalEnemy(const glm::vec2& position)
	: Enemy(position)
{
	if (!s_Vao.get())
		s_Vao = std::make_shared<SquareVao>("res/textures/enemy.png");
}

void NormalEnemy::Render() const
{
	s_Vao->Render(m_Position, {s_Size, s_Size}, 180.0f);
}

void NormalEnemy::Update()
{
	if (m_Position.y > 0.3f)
		m_Position.y -= m_Speed;
}