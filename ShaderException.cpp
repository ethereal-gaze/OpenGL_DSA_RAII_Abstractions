//
// Created by Skye Gosling on 09/11/2022.
//

#include "ShaderException.h"

namespace Graphics::GL
{
	ShaderException::ShaderException(const char* shader_name, const char* message) :
	_messageBuffer(message), _shaderNameBuffer(shader_name)
	{}

	const char* ShaderException::Message()
	{
		return _messageBuffer.c_str();
	}

	const char* ShaderException::Name()
	{
		return _shaderNameBuffer.c_str();
	}
}
