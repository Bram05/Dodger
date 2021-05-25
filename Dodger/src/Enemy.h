#ifndef ENEMY_H
#define ENEMY_H

#include "Vaos.h"

class Enemy
{
public:
	Enemy(float x, float y)
		: m_X{x}, m_Y{y}
	{
		if (!s_Vao.get())
			s_Vao = std::make_shared<EnemyVao>();
	}
	
	void Update()
	{
		m_Y -= m_Speed;
	}
	
	void Render()
	{
		s_Vao->Render(m_X, m_Y);
	}
	
private:
	float m_X, m_Y;
	static float m_Speed;
	
	static std::shared_ptr<EnemyVao> s_Vao;
};

#endif // ENEMY_H
