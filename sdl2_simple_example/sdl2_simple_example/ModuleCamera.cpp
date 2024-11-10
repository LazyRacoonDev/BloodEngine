#include "ModuleCamera.h"
#include "Application.h"
#include "Globals.h"

ModuleCamera::ModuleCamera(Application* app, bool start_enabled) : Module(app, start_enabled)
{

}

ModuleCamera::~ModuleCamera()
{

}

bool ModuleCamera::Start()
{
	return true;
}

bool ModuleCamera::CleanUp()
{
	return true;
}

bool ModuleCamera::Update(float dt)
{
	return true;
}

void ModuleCamera::Movement(glm::vec3 & newPos, float speed, float fastSpeed)
{
}

void ModuleCamera::Zoom(float zoomSpeed)
{

}

void ModuleCamera::RotateCamera(int dx, int dy)
{

}

void ModuleCamera::LookAt(const glm::vec3 & spot)
{

}

const glm::mat4& ModuleCamera::GetViewMatrix() const
{
	
}

void ModuleCamera::CalculateViewMatrix()
{

}

glm::mat4 ModuleCamera::GetProjectionMatrix() const
{
	
}

glm::vec3 ModuleCamera::RotateVector(glm::vec3 const& vector, float angle, glm::vec3 const& axis)
{

}

void ModuleCamera::SetCursor(CursorType cursorType)
{
	
}