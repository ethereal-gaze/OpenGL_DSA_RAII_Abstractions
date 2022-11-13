//
// Created by Benjamin Gosling on 11/11/2022.
//

#ifndef KRYSTAL_CAMERA_H
#define KRYSTAL_CAMERA_H

#include <WorldPositionable.h>
#include <glm/glm.hpp>

constexpr glm::vec3 WORLD_UP = glm::vec3(0, 1, 0);

namespace Graphics
{
	class Camera
	{
	public:
		explicit Camera(glm::vec3 position = glm::vec3(1.0f), glm::vec2 resolution = glm::vec2(800, 600),
			   float fov = 45.0f, float yaw = -90.0f, float pitch = 0.0f, float roll = 0.0f);

		// Moves the camera by adding the provided vector to the position.
		void Move(const glm::vec3& vector);

		// Sets the camera's aspect ratio to the resolutions x and y divided
		void SetAspectRatio(int resolutionX, int resolutionY);
		// Sets the Y Fov to the provided degrees (by turning them into radians)
		void SetFovY(float degrees);
		// Sets the camera's position to the provided vector
		void SetPosition(const glm::vec3& position);

		// Returns the aspect ratio of this camera as a float.
		float GetAspectRatio() const;
		// Returns the Fov of this camera in degrees.
		float GetFovY() const;
		// Returns the position of this camera.
		glm::vec3 GetPosition();
		// Returns the front vector of this camera.
		glm::vec3 GetFront();
		// Returns the right vector of this camera.
		glm::vec3 GetRight();
		// Returns the up vector of this camera.
		glm::vec3 GetUp();
		// Returns the current projection matrix.
		glm::mat4 GetProjectionMatrix();
		// Calculates and returns the view matrix.
		glm::mat4 GetViewMatrix();
	private:
		void _updateProjectionMatrix();
		void _calculateVectors();

		glm::mat4 _projectionMatrix;
		float _fov_y, _aspectRatio;
		float _yaw, _pitch, _roll;
		glm::vec3 _front, _up, _right;
		glm::vec3 _position;
	};

} // Graphics

#endif //KRYSTAL_CAMERA_H
