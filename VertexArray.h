//
// Created by Benjamin Gosling on 08/11/2022.
//

#ifndef KRYSTAL_VERTEXARRAY_H
#define KRYSTAL_VERTEXARRAY_H

#include <glad/glad.h>
#include <Graphics/GLObjects/Buffer.h>

namespace Graphics::GL
{
	// Represents an OpenGL Array Object
	class VertexArray
	{
	private:
		GLuint _handle;
	public:
		VertexArray();

		VertexArray(const VertexArray&) = delete;

		VertexArray& operator=(const VertexArray&) = delete;

		~VertexArray();

		// Calls glVertexArrayVertexBuffer for this buffer at the specified index.
		// Index can then be used with SetVertexAttribute
		void LinkBufferAtIndex(const Buffer& buffer, int index, size_t stride) const;

		void SetVertexAttribute(int buffer_index, int index, int size, GLenum type, GLuint relativeOffset) const;

		void SetVertexIntAttribute(int buffer_index, int index, int size, GLenum type, GLuint relativeOffset) const;

		void Bind() const;

		static void BindNull();
	};

} // GLObjects

#endif //KRYSTAL_VERTEXARRAY_H
