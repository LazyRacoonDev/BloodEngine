#include "ModuleCamera.h"
#include "Application.h"

ModuleCamera::ModuleCamera(Application* app) : Module(app)
{
	screenWidth = app->window->width;
	screenHeight = app->window->height;

	CalculateViewMatrix();

	X = glm::vec3(1.0f, 0.0f, 0.0f);
	Y = glm::vec3(0.0f, 1.0f, 0.0f);
	Z = glm::vec3(0.0f, 0.0f, 1.0f);

	pos = glm::vec3(0.0f, 5.0f, 5.0f);
	ref = glm::vec3(0.0f, 0.0f, 0.0f);
}

ModuleCamera::~ModuleCamera()
{}

bool ModuleCamera::Start()
{
	LOG(LogType::LOG_INFO, "Setting up the camera");

	LookAt(ref);

	return true;
}

bool ModuleCamera::CleanUp()
{
	LOG(LogType::LOG_INFO, "Cleaning camera");

	return true;

bool ModuleCamera::Update(float dt)
{
	if (((!isMouseInside) || (!isZooming && !isFreeLook && !isOrbiting && !isDragging)) && !isDefaultCursor)
	{
			SetCursor(CursorType::DEFAULT);
	}

	if (isMouseInside)
		HandleInput();

	CalculateViewMatrix();

	return true;
}