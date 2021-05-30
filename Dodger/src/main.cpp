#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <memory>
#include <vector>

#include "Enemy.h"
#include "Player.h"
#include "Utils.h"

GLFWwindow* SetupContext()
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
	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "Glad failed to initialize!\n";
		std::exit(EXIT_FAILURE);
	}
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	return window;
}

// Returns true if player collides with an enemy
bool IsColliding(const Player& player, const std::vector<Enemy*>& enemies)
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

unsigned int PlayGame(GLFWwindow* window)
{
	Player player({ 0.5f, 0.1f });
	std::vector<Enemy*> enemies;
	
	unsigned int i{0};
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
		
		if (IsColliding(player, enemies))
			return i;
		
		if (i % 100 == 0)
			enemies.push_back(new NormalEnemy({Utils::GenerateRandom(), 1.0f}));
		++i;
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	return i;
}

int main()
{
	GLFWwindow* window{SetupContext()};
	std::cout << "You died!\nYour score is " << PlayGame(window) << '\n';
	
}