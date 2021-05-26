#ifndef PLAYER_H
#define PLAYER_H

#include <GLFW/glfw3.h>

#include "Vaos.h"

class Player
{
public:
	Player(float x, float y);
	~Player();
	
	void Update(GLFWwindow* window);
	void Render();

private:
	float m_X, m_Y;
	std::shared_ptr<SquareVao> m_Vao;
};

#endif // PLAYER_H
