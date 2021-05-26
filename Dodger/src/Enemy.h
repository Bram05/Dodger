#ifndef ENEMY_H
#define ENEMY_H

#include "Vaos.h"

class Enemy
{
public:
	Enemy(float x, float y)
		: m_X{x}, m_Y{y}
	{}
	
	virtual ~Enemy() {}
	
	virtual void Update() = 0;
	virtual void Render() = 0;
	
protected:
	float m_X, m_Y;
};

class NormalEnemy : public Enemy
{
public:
	NormalEnemy(float x, float y)
		: Enemy(x, y)
	{
		if (!s_Vao.get())
			s_Vao = std::make_shared<SquareVao>();
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
	static std::shared_ptr<SquareVao> s_Vao;
	static float m_Speed;
};

#endif // ENEMY_H
