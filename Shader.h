//
// Created by Skye Gosling on 08/11/2022.
//

#ifndef KRYSTAL_SHADER_H
#define KRYSTAL_SHADER_H

#include <glad/glad.h>

// TODO: Look into this: https://github.com/fendevel/Guide-to-Modern-OpenGL-Functions#setting-up-mix--match-shaders-with-program-pipelines

#include <glm/glm.hpp>

struct mvp
{
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;
};

namespace Graphics::GL
{
	// Represents a GLSL Shader Program
	class Shader
	{
	private:
		GLuint _handle;
	public:
		Shader();
		Shader(const char* vertex_path, const char* fragment_path);
		~Shader();
		Shader(const Shader&) = delete;
		Shader& operator=(const Shader&) = delete;
		void Bind() const;
		void AddShaderFromSource(const char* path, GLenum type) const;
	};
}


#endif //KRYSTAL_SHADER_H
