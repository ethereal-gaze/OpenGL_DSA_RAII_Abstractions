//
// Created by Skye Gosling on 09/11/2022.
//

#ifndef KRYSTAL_SHADEREXCEPTION_H
#define KRYSTAL_SHADEREXCEPTION_H

#include <iostream>

namespace Graphics::GL
{
	class ShaderException : std::exception
	{
	private:
		std::string _messageBuffer;
		std::string _shaderNameBuffer;
	public:
		ShaderException(const char* shader_name, const char* message);
		const char* Message();
		const char* Name();
	};
}

#endif //KRYSTAL_SHADEREXCEPTION_H
