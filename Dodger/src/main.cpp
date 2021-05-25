#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <memory>

#include "Enemy.h"

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
	
	Enemy* enemies[5];
	for (int i{0}; i < 5; ++i)
	{
		enemies[i] = new Enemy(i*0.2f - 0.5f, 1.0f);
	}
	
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
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