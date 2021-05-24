#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main()
{
	if (!glfwInit())
	{
		std::cerr << "GLFW failed to initialize!\n";
		return EXIT_FAILURE;
	}
	
	GLFWwindow* window = glfwCreateWindow(720, 450, "Hello", nullptr, nullptr);
	if (!window)
	{
		std::cerr << "GLFW failed to create a window!\n";
		return EXIT_FAILURE;
	}
	glfwMakeContextCurrent(window);
	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "Glad failed to initialize!\n";
		return EXIT_FAILURE;
	}
	
	unsigned int vao;
	glGenVertexArrays(1, &vao);
	
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}