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
	glfwMakeContextCurrent(window);
	
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}