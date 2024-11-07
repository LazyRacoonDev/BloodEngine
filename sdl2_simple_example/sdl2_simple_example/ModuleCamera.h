#pragma once
#include "Module.h"
#include "glm/glm.hpp"
#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/transform.hpp"

/* Se tiene que hacer un modulo de input*/

class ModuleCamera : public Module
{
public:
	ModuleCamera(Application* app);
	~ModuleCamera();

	bool Start();
	bool Update(float dt);
	void HandleInput();
	void FrameSelected();
	bool CleanUp();

	void LookAt(const glm::vec3& spot);
	const glm::mat4& GetViewMatrix() const;
	glm::mat4 GetProjectionMatrix() const;

private:
	void HandleMovement(glm::vec3& newPos, float speed, float fastSpeed);
	void HandleZoom(float zoomSpeed);
	void HandleRotation();
	void RotateCamera(int dx, int dy);
	void CalculateViewMatrix();
	glm::vec3 RotateVector(glm::vec3 const& vector, float angle, glm::vec3 const& axis);

	void SetCursor(CursorType cursorType);

public:
	float fov = 60.0f;
	float nearPlane = 0.250f;
	float farPlane = 512.0f;
	int screenWidth, screenHeight;

	bool isMouseInside = false;

private:
	glm::vec3 X, Y, Z;
	glm::vec3 pos, ref;
	glm::mat4 viewMatrix;

	bool isZooming = false;
	bool isOrbiting = false;
	bool isFreeLook = false;
	bool isDragging = false;
	bool isDefaultCursor = true;
};
