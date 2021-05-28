#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <map>
#include <glm/glm.hpp>

class Shader
{
public:
	Shader(const std::string& filepath);
	~Shader();
	
	void Bind() const;
	void UnBind() const;
	
	void SetUniform(const std::string& name, const glm::mat4& mat);
	void SetUniform(const std::string& name, int val);
	
	Shader(const Shader&) = delete;
	Shader& operator=(const Shader&) = delete;
	
private:
	unsigned int m_Shader{};
	mutable std::map<std::string, int> m_UniformLocations{};
private:
	void CreateProgram(const std::string& vertexShader, const std::string& fragmentShader);
	unsigned int CreateShader(const std::string& shaderSource, unsigned int type);
	int GetUniformLocation(const std::string& name);
};

#endif // SHADER_H
