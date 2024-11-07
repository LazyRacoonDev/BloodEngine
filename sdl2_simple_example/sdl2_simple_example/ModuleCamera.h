#pragma once
#include "Module.h"
#include "glm/glm.hpp"
#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/transform.hpp"

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