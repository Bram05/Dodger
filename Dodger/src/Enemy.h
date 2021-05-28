#ifndef ENEMY_H
#define ENEMY_H

#include <glm/glm.hpp>

#include "Vaos.h"

class Enemy
{
public:
	Enemy(const glm::vec2& position)
		: m_Position{position}
	{}
	
	virtual ~Enemy() {}
	
	virtual void Update() = 0;
	virtual void Render() const = 0;
	
protected:
	glm::vec2 m_Position;
};

class NormalEnemy : public Enemy
{
public:
	NormalEnemy(const glm::vec2& position);
	
	void Update() override;
	void Render() const override;
	
private:
	static std::shared_ptr<SquareVao> s_Vao;
	static float m_Speed;
};

#endif // ENEMY_H
