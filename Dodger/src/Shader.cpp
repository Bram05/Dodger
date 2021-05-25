#include "Shader.h"

#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

Shader::Shader(const std::string& filepath)
{
	std::ifstream file(filepath);
	if (!file)
	{
		std::cerr << filepath << " shader failed to open!\n";
		return;
	}
	
	enum Type
	{
		VERTEX = 0, FRAGMENT = 1, NONE = 2
	};
	
	std::stringstream sstreams[Type::NONE];
	Type type{Type::VERTEX};
	std::string line;
	while (std::getline(file, line))
	{
		if (line.find("#type") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
				type = Type::VERTEX;
			else if (line.find("fragment") != std::string::npos)
				type = Type::FRAGMENT;
			else
				std::cerr << "Invalid #type decleration " << line << " in file " << filepath << '\n';
		}
		else
		{
			sstreams[type] << line << '\n';
		}
	}
	
	CreateProgram(sstreams[Type::VERTEX].str(), sstreams[Type::FRAGMENT].str());
}

Shader::~Shader()
{
	glDeleteProgram(m_Shader);
}

void Shader::Bind() const
{
	glUseProgram(m_Shader);
}

void Shader::UnBind() const
{
	glUseProgram(0);
}

void Shader::SetUniform(const std::string& name, const glm::mat4& mat)
{
	glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::CreateProgram(const std::string& vertexShaderSource, const std::string& fragmentShaderSource)
{
	unsigned int vertexShader{CreateShader(vertexShaderSource, GL_VERTEX_SHADER)};
	unsigned int fragmentShader{CreateShader(fragmentShaderSource, GL_FRAGMENT_SHADER)};
	
	m_Shader = glCreateProgram();
	glAttachShader(m_Shader, vertexShader);
	glAttachShader(m_Shader, fragmentShader);
	glLinkProgram(m_Shader);
	
	int success;
	glGetProgramiv(m_Shader, GL_LINK_STATUS, &success);
	if (!success)
	{
		int logLength;
		glGetProgramiv(m_Shader, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> infoLog(logLength);
		glGetProgramInfoLog(m_Shader, logLength, nullptr, infoLog.data());
		
		std::cerr << "Shader linking failed!\n" << infoLog.data() << '\n';
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
		std::exit(EXIT_FAILURE);
	}
	
	glDetachShader(m_Shader, vertexShader);
	glDetachShader(m_Shader, fragmentShader);
}

unsigned int Shader::CreateShader(const std::string& shaderSource, unsigned int type)
{	
	unsigned int shader = glCreateShader(type);
	const char* source = shaderSource.c_str();
	glShaderSource(shader, 1, &source, nullptr);
	glCompileShader(shader);
	
	int success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		int logLength;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> infoLog(logLength);
		glGetShaderInfoLog(shader, logLength, nullptr, infoLog.data());
		
		std::cerr << "Shader compilation failed!\n" << infoLog.data() << '\n';
		glDeleteShader(shader);
		std::exit(EXIT_FAILURE);
	}
	return shader;
}

int Shader::GetUniformLocation(const std::string& name)
{
	auto loc{m_UniformLocations.find(name)};
	if (loc != m_UniformLocations.end())
		return loc->second;
	
	int location = glGetUniformLocation(m_Shader, name.c_str());
	if (location == -1)
		std::cerr << "Uniform " << name << " could not be found or is not used!\n";
	m_UniformLocations.insert({name, location});
	return location;
}