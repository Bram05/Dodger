#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

#include "Enemy.h"
#include "Player.h"
#include "Utils.h"

// Initialize glfw, create a window and setup glad
// Returns the window
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

// Check if player collides with any enemy
// Returns true if they collide
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

// Update the player and enemies' locations and remove any unecessary enemies
void Update(Player& player, std::vector<Enemy*>& enemies, GLFWwindow* window, float frameTime)
{
	player.Update(window, frameTime);
	for (Enemy* enemy : enemies)
	{
		enemy->Update(frameTime);
	}
	
	enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [](const Enemy* enemy){
		return (enemy->GetPosition().y < 0.0f);
	}), enemies.end());
}

// Render the player and enemies
void Render(const Player& player, const std::vector<Enemy*>& enemies)
{
	player.Render();
	for (Enemy* enemy : enemies)
	{
		enemy->Render();
	}
}

// Spawn an enemy in at a random x-coordinate after a random interval 
void SpawnEnemy(std::vector<Enemy*>& enemies, float frameTime)
{
	static float timeTillNextEnemy{0.0f};
	static const float maxTimeTillNextEnemy{3.0f};
	if (timeTillNextEnemy < 0.0f)
	{
		enemies.push_back(new NormalEnemy({Utils::GenerateRandomFloat(), 1.0f}));
		timeTillNextEnemy = Utils::GenerateRandomFloat() * maxTimeTillNextEnemy;
	}
	timeTillNextEnemy -= frameTime;
}

// Play the game and return the score (time since game started in seconds)
unsigned int PlayGame(GLFWwindow* window)
{
	Player player({ 0.5f, 0.1f });
	std::vector<Enemy*> enemies;
	
	float lastFrame{0.0f};
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		float currentTime{static_cast<float>(glfwGetTime())};
		float frameTime{currentTime - lastFrame};
		lastFrame = currentTime;
		
		std::cout << "FPS: " << 1/frameTime << '\n';
		
		Update(player, enemies, window, frameTime);
		Render(player, enemies);
		
		if (IsColliding(player, enemies))
			return static_cast<unsigned int>(glfwGetTime());
		
		SpawnEnemy(enemies, frameTime);
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	for (Enemy* enemy : enemies)
		delete enemy;
	return static_cast<unsigned int>(glfwGetTime());
}

int main()
{
	GLFWwindow* window{SetupContext()};
	unsigned int score{PlayGame(window)};
	std::cout << "You died!\nYour score is " << score << '\n';
}