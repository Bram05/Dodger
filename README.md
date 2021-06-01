# Dodger game
This is a basic 2D game written in c++ using OpenGL. You control the player object using the arrow keys and enemies fall from above. If you hit an enemy you die and
the game stops. 

The project uses Premake to generate the project files for codelite.

Right now it only works on Linux.

## Dependencies
To build this project you need a Linux machine, the codelite IDE and a c++17 minimum compiler.

## Using
1. Clone the repository using `git clone --recurse-submodules` to clone the project and get the submodules (GLFW)
2. Run `./GenerateProject.sh` (only works on Linux) to generate the codelite project files
3. Open the project files in codelite
4. Compile and run the project from within codelite

## Internal Dependencies
This project uses:
  - Premake for creating the project files to open the code in an IDE
  - GLFW for creating a window and creating an opengl context
  - GLAD to load all the opengl functions
  - GLM for transformations
  - Stb_image for loading textures
These are all included in the project and will be build automatically
