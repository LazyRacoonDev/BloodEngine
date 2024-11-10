#pragma once
#include "Module.h"
#include "Globals.h"
#include <SDL2/SDL.h>
#include <glm/glm.hpp>  // Usaremos GLM para operaciones matemáticas de cámara

class ModuleCamera : public Module
{
public:
    ModuleCamera(Application* app, bool start_enabled = true);
    ~ModuleCamera();

    bool Init() override;
    update_status Update(float dt) override;
    bool CleanUp() override;

    void SetPosition(const glm::vec3& pos);
    void LookAt(const glm::vec3& target);

    void Move(const glm::vec3& direction);
    void Rotate(float pitch, float yaw);

    glm::mat4 GetViewMatrix() const;

private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 world_up;

    float yaw;
    float pitch;
    float movement_speed;
    float mouse_sensitivity;
    float zoom;

    void UpdateCameraVectors();
};