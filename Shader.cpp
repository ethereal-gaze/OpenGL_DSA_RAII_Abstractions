//
// Created by Skye Gosling on 08/11/2022.
//

#include <string>
#include <Util/File.h>
#include "Exception/ShaderException.h"
#include "Shader.h"



namespace Graphics::GL
{
	Shader::Shader() : _handle(0)
	{ _handle = glCreateProgram(); }

	Shader::Shader(const char *vertex_path, const char *fragment_path) : Shader()
	{
		AddShaderFromSource(vertex_path, GL_VERTEX_SHADER);
		AddShaderFromSource(fragment_path, GL_FRAGMENT_SHADER);
	}

	void Shader::AddShaderFromSource(const char* path, GLenum type) const
	{
		// Getting the source code for the shader
		std::string source = Util::File::ReadTextFile(path);
		if (source.empty())
			throw GL::ShaderException(path, "No source string provided");

		GLuint shader_handle = glCreateShader(type);
		const char* source_pointer = source.c_str();
		glShaderSource(shader_handle, 1, &source_pointer, nullptr);

		// Shader Compilation
		glCompileShader(shader_handle);

		int compile_success;
		glGetShaderiv(shader_handle, GL_COMPILE_STATUS, &compile_success);
		if (!compile_success)
		{
			int buffer_size;
			char* buffer;
			std::string error_text;

			glGetShaderiv(shader_handle, GL_INFO_LOG_LENGTH, &buffer_size);
			buffer = new char[buffer_size];
			glGetShaderInfoLog(shader_handle, buffer_size, nullptr, buffer);
			error_text = std::string(buffer);
			delete[] buffer;

			throw GL::ShaderException(path, error_text.c_str());
		}

		// Attach shader
		glAttachShader(_handle, shader_handle);

		// Link program again now new shader has been added
		compile_success = 0;
		glLinkProgram(_handle);
		glGetProgramiv(_handle, GL_LINK_STATUS, &compile_success);
		if (!compile_success)
		{
			int buffer_size;
			char *buffer;
			std::string error_text;

			glGetProgramiv(_handle, GL_INFO_LOG_LENGTH, &buffer_size);
			buffer = new char[buffer_size];
			glGetProgramInfoLog(_handle, buffer_size, nullptr, buffer);
			error_text = buffer;
			delete[] buffer;

			throw GL::ShaderException(path, error_text.c_str());
		}

		glDeleteShader(shader_handle);
	}

	void Shader::Bind() const
	{
		glUseProgram(_handle);
	}

	Shader::~Shader()
	{
		glDeleteProgram(_handle);
	}
}
