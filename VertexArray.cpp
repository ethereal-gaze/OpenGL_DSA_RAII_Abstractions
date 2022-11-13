//
// Created by Benjamin Gosling on 08/11/2022.
//

#include "VertexArray.h"

namespace Graphics::GL
{
	VertexArray::VertexArray() : _handle(0)
	{
		glCreateVertexArrays(1, &_handle);
	}

	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &_handle);
	}

	void VertexArray::LinkBufferAtIndex(const Buffer& buffer, int index, size_t stride) const
	{
		glVertexArrayVertexBuffer(_handle, index, buffer._handle, 0, stride);
	}

	void VertexArray::SetVertexAttribute(int buffer_index, int index, int size, GLenum type, GLuint relativeOffset) const
	{
		glEnableVertexArrayAttrib(_handle, index);
		glVertexArrayAttribFormat(_handle, index, size, type, GL_FALSE, relativeOffset);
		glVertexArrayAttribBinding(_handle, index, buffer_index);
	}

	void VertexArray::SetVertexIntAttribute(int buffer_index, int index, int size, GLenum type, GLuint relativeOffset) const
	{
		glEnableVertexArrayAttrib(_handle, index);
		glVertexArrayAttribIFormat(_handle, index, size, type, relativeOffset);
		glVertexArrayAttribBinding(_handle, index, buffer_index);
	}

	void VertexArray::Bind() const
	{
		glBindVertexArray(_handle);
	}

	void VertexArray::BindNull()
	{
		glBindVertexArray(0);
	}
} // GLObjects