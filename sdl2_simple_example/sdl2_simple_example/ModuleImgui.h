#ifndef __MODULEIMGUI_H__
#define __MODULEIMGUI_H__

#include "Module.h"
#include "Application.h"
#include "imgui.h"

class ModuleImGui : public Module {
public:
    ModuleImGui(Application* app, bool start_enabled = true);
    ~ModuleImGui();

    bool Init() override;
    bool Start() override;
    update_status PreUpdate(float dt) override;
    update_status Update(float dt) override;
    update_status PostUpdate(float dt) override;
    bool CleanUp() override;

private:
    ImGuiIO* io = nullptr; 
    void SetupDockSpace(); 
    void RenderPanels();   
};
#endif 
