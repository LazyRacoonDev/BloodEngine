#ifndef __CAMERA_H__
#define __CAMERA_H__
#pragma once

#include "Defs.h"

class Camera {
	public:
		glm::vec3 Position;
		glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
		glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);

		bool firstClick = true;

		int width;
		int height;

		float speed = 0.1f;
		float sensitivity = 100.0f;

		Camera(int width, int height, glm::vec3 position);

		//void Matrix(float Fovdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform);
};

#endif // !__CAMERA_H__