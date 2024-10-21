//
// Created by Skye Gosling on 11/11/2022.
//

#include "Camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Graphics
{
	void Camera::SetFovY(float degrees)
	{
		_fov_y = glm::radians(degrees);
		_updateProjectionMatrix();
	}

	void Camera::SetAspectRatio(int resolutionX, int resolutionY)
	{
		_fov_y = (float) resolutionX / (float) resolutionY;
		_updateProjectionMatrix();
	}

	glm::mat4 Camera::GetProjectionMatrix() { return _projectionMatrix; }
	void Camera::_updateProjectionMatrix() { _projectionMatrix = glm::perspective(_fov_y, _aspectRatio, 0.01f, 100.0f); }
	float Camera::GetFovY() const { return _fov_y; }
	float Camera::GetAspectRatio() const { return _aspectRatio; }

	Camera::Camera(glm::vec3 position, glm::vec2 resolution, float fov, float yaw, float pitch, float roll) :
	_projectionMatrix(), _fov_y(glm::radians(fov)), _aspectRatio(resolution.x / resolution.y),
	_yaw(glm::radians(yaw)),
	_pitch(glm::radians(pitch)), _roll(glm::radians(roll)), _front(0, 0, -1), _up(0, 1, 0),
	_right(-1, 0, 0)
	{
		SetAspectRatio(resolution.x, resolution.y);
		_calculateVectors();
		_updateProjectionMatrix();
	}

	void Camera::_calculateVectors()
	{
		glm::vec3 new_front;
		new_front.x = cos(_yaw) * cos(_pitch);
		new_front.y = sin(_pitch);
		new_front.z = sin(_yaw) * cos (_pitch);
		_front = glm::normalize(new_front);
		_right = glm::normalize(glm::cross(_front, WORLD_UP));
		_up = glm::normalize(glm::cross(_right, _front));
	}

	glm::mat4 Camera::GetViewMatrix()
	{
		return glm::lookAt(_position, _position + _front, _up);
	}

	glm::vec3 Camera::GetFront()
	{
		return _front;
	}

	glm::vec3 Camera::GetRight()
	{
		return _right;
	}

	glm::vec3 Camera::GetUp()
	{
		return _up;
	}

	void Camera::SetPosition(const glm::vec3 &position)
	{
		_position = position;
	}

	void Camera::Move(const glm::vec3 &vector)
	{
		_position += vector;
	}

	glm::vec3 Camera::GetPosition()
	{
		return _position;
	}
} // Graphics
