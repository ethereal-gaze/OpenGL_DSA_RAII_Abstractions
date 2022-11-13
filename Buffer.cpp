//
// Created by Benjamin Gosling on 08/11/2022.
//

#include "Buffer.h"

namespace Graphics::GL
{
	Buffer::Buffer(GLenum type) : _handle(0), _type(type)
	{
		glCreateBuffers(1, &_handle);
	}

	Buffer::Buffer(void *data, size_t size_in_bytes, GLenum type) : Buffer(type)
	{
		SetData(data, size_in_bytes);
	}

	void Buffer::SetData(void *data, GLsizei size_in_bytes) const
	{
		glNamedBufferData(_handle, size_in_bytes, data, GL_STATIC_DRAW);
	}

	void Buffer::SetType(GLenum type)
	{
		_type = type;
	}

	GLenum Buffer::GetType() const
	{
		return _type;
	}

	void Buffer::Bind() const
	{
		glBindBuffer(_type, _handle);
	}

	Buffer::~Buffer()
	{
		glDeleteBuffers(1, &_handle);
	}

	void Buffer::BindNull() const
	{
		glBindBuffer(_type, 0);
	}

	void Buffer::BindBase(GLuint index) const
	{
		glBindBufferBase(_type, index, _handle);
	}
} // GLObjects