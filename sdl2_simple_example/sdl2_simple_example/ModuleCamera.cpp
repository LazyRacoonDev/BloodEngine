#include "ModuleCamera.h"
#include "Application.h"
#include "Globals.h"
#include "ModuleInputs.h" 
#include <glm/gtc/matrix_transform.hpp>

ModuleCamera::ModuleCamera(Application* app, bool start_enabled) : Module(app, start_enabled) {
    position = glm::vec3(10.0f, 10.0f, 10.0f);
    target = glm::vec3(0.0f, 0.0f, 0.0f);     
    up = glm::vec3(0.0f, 1.0f, 0.0f);         
    speed = 20.0f;                            
}

ModuleCamera::~ModuleCamera() {
    CleanUp();
}

bool ModuleCamera::Init() {
    return true;
}

bool ModuleCamera::Start() {
    return true;
}

update_status ModuleCamera::PreUpdate(float dt) {
    return UPDATE_CONTINUE;
}

update_status ModuleCamera::Update(float dt) {
    CameraInput(dt);       
    updateViewMatrix();    
    return UPDATE_CONTINUE;
}

update_status ModuleCamera::PostUpdate(float dt) {
    return UPDATE_CONTINUE;
}

void ModuleCamera::CameraInput(float dt) {
    ModuleInputs* inputs;

    // Movimiento hacia adelante y atrás
    if (inputs->GetKey(SDL_SCANCODE_W) == KEY_REPEAT) {
        position += glm::normalize(target - position) * speed * dt;
    }
    if (inputs->GetKey(SDL_SCANCODE_S) == KEY_REPEAT) {
        position -= glm::normalize(target - position) * speed * dt;
    }
    // Movimiento hacia los lados
    glm::vec3 right = glm::normalize(glm::cross(target - position, up));
    if (inputs->GetKey(SDL_SCANCODE_A) == KEY_REPEAT) {
        position -= right * speed * dt;
    }
    if (inputs->GetKey(SDL_SCANCODE_D) == KEY_REPEAT) {
        position += right * speed * dt;
    }

    int mouseMotionX = inputs->GetMouseXMotion();
    int mouseMotionY = inputs->GetMouseYMotion();

    float sensitivity = 0.1f;

    glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(-mouseMotionX * sensitivity), up);
    position = glm::vec3(rotationMatrix * glm::vec4(position - target, 1.0f)) + target;

    rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(-mouseMotionY * sensitivity), right);
    position = glm::vec3(rotationMatrix * glm::vec4(position - target, 1.0f)) + target;

    target = position + glm::normalize(target - position);
}

void ModuleCamera::updateViewMatrix() {
    // matriz de vista
    viewMatrix = glm::lookAt(position, target, up);
}

bool ModuleCamera::CleanUp() {
    return true;
}