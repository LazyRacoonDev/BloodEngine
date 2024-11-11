#include "ModuleImGui.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleWindow.h"
#include "SDL2/SDL.h"
#include <imgui_impl_sdl2.h>
#include <imgui_impl_opengl3.h>


ModuleImGui::ModuleImGui(Application* app, bool start_enabled) : Module(app, start_enabled) {}

ModuleImGui::~ModuleImGui() {}

bool ModuleImGui::Init() {
    IMGUI_CHECKVERSION();
    
    io = &ImGui::GetIO();
    io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; 
    io->ConfigFlags |= ImGuiConfigFlags_DockingEnable;     
    io->ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;   

    return true;
}

bool ModuleImGui::Start() {
    SDL_ShowCursor(SDL_DISABLE);
    SDL_SetRelativeMouseMode(SDL_TRUE);
    return true;
}

update_status ModuleImGui::PreUpdate(float dt) {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
    SetupDockSpace();
    return UPDATE_CONTINUE;
}

update_status ModuleImGui::Update(float dt) {
    RenderPanels(); 
    ImGui::Render();
    return UPDATE_CONTINUE;
}

update_status ModuleImGui::PostUpdate(float dt) {
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    if (io->ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        SDL_GL_MakeCurrent(App->window->window, App->window->context);  
    }
    return UPDATE_CONTINUE;
}

bool ModuleImGui::CleanUp() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    SDL_ShowCursor(SDL_ENABLE);
    SDL_SetRelativeMouseMode(SDL_FALSE);
    return true;
}

void ModuleImGui::SetupDockSpace() {
    ImGui::DockSpaceOverViewport(ImGui::GetMainViewport()->ID);
}

void ModuleImGui::RenderPanels() {
    ImGui::Begin("Dockable Window 1");
    ImGui::Text("This window can be docked.");
    ImGui::End();

    ImGui::Begin("Dockable Window 2");
    ImGui::Text("This window can also be docked.");
    ImGui::End();
}