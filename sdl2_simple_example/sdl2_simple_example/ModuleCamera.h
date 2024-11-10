#ifndef __ModuleCamera_H__
#define __ModuleCamera_H__

#include "Module.h"
#include "SDL2/SDL.h"

class Application;

bool processEvents();

class ModuleCamera : public Module {
public:
    ModuleCamera(Application* app, bool start_enabled = true);
    ~ModuleCamera();

    bool Init() override;
    bool Start() override;
    update_status PreUpdate(float dt) override;
    update_status Update(float dt) override;
    update_status PostUpdate(float dt) override;
    bool CleanUp() override;

    void MoveCamera();
    void Control();
    void UpdateCamera();
};
#endif