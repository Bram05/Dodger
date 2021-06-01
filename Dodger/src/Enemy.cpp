#include "Enemy.h"

std::shared_ptr<SquareVao> NormalEnemy::s_Vao;
float NormalEnemy::m_Speed{0.25f};
float NormalEnemy::s_Size{0.05f};

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

void NormalEnemy::Update(float frameTime)
{
	m_Position.y -= m_Speed * frameTime;
}