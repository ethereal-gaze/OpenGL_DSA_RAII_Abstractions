//
// Created by Skye Gosling on 08/11/2022.
//

#ifndef KRYSTAL_BUFFER_H
#define KRYSTAL_BUFFER_H

#include <vector>
#include <glad/glad.h>

namespace Graphics::GL
{
	// Represents an OpenGL Buffer object.
	class Buffer
	{
	private:
		GLuint _handle{};
		GLenum _type{};
	public:
		friend class VertexArray;

		explicit Buffer(GLenum type);

		~Buffer();

		Buffer(const Buffer&) = delete;

		Buffer& operator=(const Buffer&) = delete;

		Buffer(void *data, size_t size_in_bytes, GLenum type);

		void SetData(void *data, GLsizei size_in_bytes) const;

		void SetType(GLenum type);

		GLenum GetType() const;

		void Bind() const;

		void BindBase(GLuint index) const;

		void BindNull() const;
	};

} // GLObjects

#endif //KRYSTAL_BUFFER_H
