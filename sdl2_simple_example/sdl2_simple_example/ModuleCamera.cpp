#include "ModuleCamera.h"
#include "Application.h"
#include "Globals.h"
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"

ModuleCamera::ModuleCamera(Application* app, bool start_enabled) : Module(app, start_enabled) {

}

ModuleCamera::~ModuleCamera() {
	CleanUp();
}

bool ModuleCamera::Init() {
	bool ret = true;

    return ret;
}

bool ModuleCamera::CleanUp() {
    return true;
}

bool ModuleCamera::Start(){
    return true;
}

update_status ModuleCamera::PreUpdate(float dt) {
    return UPDATE_CONTINUE;
}

update_status ModuleCamera::Update(float dt) {
    return UPDATE_CONTINUE;
}

update_status ModuleCamera::PostUpdate(float dt) {
    return UPDATE_CONTINUE;
}