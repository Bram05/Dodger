#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <memory>

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
	
	Player player(0.5f, 0.1f);
	Enemy* enemies[5];
	for (int i{0}; i < 5; ++i)
	{
		enemies[i] = new NormalEnemy(i*0.2f, 1.0f);
	}
	
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		player.Render();
		player.Update(window);
		for (int i{0}; i < 5; ++i)
		{
			enemies[i]->Render();
			enemies[i]->Update();
		}
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	for (int i{0}; i < 5; ++i)
	{
		delete enemies[i];
	}
}