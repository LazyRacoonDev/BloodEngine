#include "ModuleCamera.h"
#include "Application.h"
#include "Globals.h"
#include <glm/gtc/matrix_transform.hpp>
#include "ModuleWindow.h"

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
    glLoadIdentity();

    gluPerspective(45.0f, (GLfloat)App->window->Width / (GLfloat)App->window->Height, 0.1f, 100.0f);

    gluLookAt(target.x, target.y, target.z,
        0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f);

    return UPDATE_CONTINUE;
}

update_status ModuleCamera::PostUpdate(float dt) {
    return UPDATE_CONTINUE;
}

void ModuleCamera::CameraInput(float dt) {
    const Uint8* keys = SDL_GetKeyboardState(NULL); 

    // Movimiento hacia adelante y atrás
    if (keys[SDL_SCANCODE_W]) {
        position += glm::normalize(target - position) * speed * dt;
        SDL_Log("se pulsa w");
    }
    if (keys[SDL_SCANCODE_S]) {
        position -= glm::normalize(target - position) * speed * dt;
        SDL_Log("se pulsa s");
    }

    // Movimiento hacia los lados
    glm::vec3 right = glm::normalize(glm::cross(target - position, up));
    if (keys[SDL_SCANCODE_A]) {
        position -= right * speed * dt;
        SDL_Log("se pulsa a");
    }
    if (keys[SDL_SCANCODE_D]) {
        position += right * speed * dt;
        SDL_Log("se pulsa d");
    }

    int mouseMotionX, mouseMotionY;
    SDL_GetRelativeMouseState(&mouseMotionX, &mouseMotionY); 

    float sensitivity = 0.1f;

    glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(-mouseMotionX * sensitivity), up);
    position = glm::vec3(rotationMatrix * glm::vec4(position - target, 1.0f)) + target;

    rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(-mouseMotionY * sensitivity), right);
    position = glm::vec3(rotationMatrix * glm::vec4(position - target, 1.0f)) + target;
    
    target = position + glm::normalize(target - position);
}

void ModuleCamera::updateViewMatrix() {
    viewMatrix = glm::lookAt(position, target, up);
}

bool ModuleCamera::CleanUp() {
    return true;
}