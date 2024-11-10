#ifndef __ModuleWindow_H__
#define __ModuleWindow_H__

#include "Module.h"
#include "SDL2/SDL.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Application;

class ModuleWindow : public Module {
public:
    ModuleWindow(Application* app, bool start_enabled = true);
    ~ModuleWindow();

    bool Init() override;
    bool Start() override;
    update_status PreUpdate(float dt) override;
    update_status Update(float dt) override;
    update_status PostUpdate(float dt) override;
    bool CleanUp() override;

    void SetTitle(const char* title);
    void SwapBuffers();
    void SetCameraView();  // Nueva funci�n para configurar la c�mara

private:
    void DrawGrid();
    SDL_Window* window;
    SDL_Surface* screenSurface;
    SDL_GLContext context;
    glm::mat4 viewMatrix;   // Matriz de vista para la c�mara
    int Height;
    int Width;
};

#endif