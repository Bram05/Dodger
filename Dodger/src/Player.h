#ifndef PLAYER_H
#define PLAYER_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Vaos.h"

class Player
{
public:
	Player(const glm::vec2& position);
	~Player();
	
	void Update(GLFWwindow* window, float framTime);
	void Render() const;
	
	const glm::vec2 GetPosition() const { return m_Position;; }
	float GetSize() const { return m_Size; }

private:
	glm::vec2 m_Position;
	float m_Size{0.1f};
	std::shared_ptr<SquareVao> m_Vao;
};

#endif // PLAYER_H
