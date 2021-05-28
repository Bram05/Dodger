#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <memory>
#include <vector>

#include "Enemy.h"
#include "Player.h"

GLFWwindow* CreateWindow()
{
	if (!glfwInit())
	{
		std::cerr << "GLFW failed to initialize!\n";
		std::exit(EXIT_FAILURE);
	}
	
	GLFWwindow* window = glfwCreateWindow(720, 450, "Hello", nullptr, nullptr);
	if (!window)
	{
		std::cerr << "GLFW failed to create a window!\n";
		std::exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	return window;
}

// Returns true if player collides with an enemy
bool CheckCollisions(const Player& player, const std::vector<Enemy*>& enemies)
{
	for (const Enemy* enemy : enemies)
	{
		// Check if they collide on x axis
		// (distance between the objects on x axis) - (size of enemy) - (size of player) < 0
		if (glm::abs(enemy->GetPosition().x - player.GetPosition().x) - (enemy->GetSize()/2) - (player.GetSize()/2) < 0)
		{
			// Check if they collide on y axis in the same way
			if (glm::abs(enemy->GetPosition().y - player.GetPosition().y) - (enemy->GetSize()/2) - (player.GetSize()/2) < 0)
				return true;
		}
	}
	return false;
}

int main()
{	
	GLFWwindow* window{CreateWindow()};
	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "Glad failed to initialize!\n";
		return EXIT_FAILURE;
	}
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	
	Player player({ 0.5f, 0.1f });
	std::vector<Enemy*> enemies(5);
	for (unsigned int i{0}; i < 5; ++i)
	{
		enemies[i] = new NormalEnemy(glm::vec2(i*0.2f, 1.0f));
	}
	
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		player.Render();
		player.Update(window);
		for (Enemy* enemy : enemies)
		{
			enemy->Render();
			enemy->Update();
		}
		
		if (CheckCollisions(player, enemies))
			std::cout << "Colliding!\n";
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}