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
	
	const glm::vec2 GetPosition() const { return m_Position; }
	virtual float GetSize() const = 0;
	
protected:
	glm::vec2 m_Position;
};

class NormalEnemy : public Enemy
{
public:
	NormalEnemy(const glm::vec2& position);
	
	void Update() override;
	void Render() const override;
	
	float GetSize() const override { return s_Size; }
	
private:
	static std::shared_ptr<SquareVao> s_Vao;
	static float m_Speed;
	static float s_Size;
};

#endif // ENEMY_H
