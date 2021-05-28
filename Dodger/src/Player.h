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
	
	void Update(GLFWwindow* window);
	void Render();

private:
	glm::vec2 m_Position;
	std::shared_ptr<SquareVao> m_Vao;
};

#endif // PLAYER_H
