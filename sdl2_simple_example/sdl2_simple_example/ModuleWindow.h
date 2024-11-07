#ifndef __ModuleWindow_H__
#define __ModuleWindow_H__

#include "Module.h"
#include "SDL2/SDL.h"

// Declaraci�n de la clase Application para evitar dependencias circulares
class Application;

class ModuleWindow : public Module {
public:
    // Constructor y Destructor
    ModuleWindow(Application* app, bool start_enabled = true);
    ~ModuleWindow();

    // Implementaci�n de los m�todos virtuales de la clase base Module
    bool Init() override;
    bool Start() override;
    update_status PreUpdate(float dt) override;
    update_status Update(float dt) override;
    update_status PostUpdate(float dt) override;
    bool CleanUp() override;

    // M�todos espec�ficos de ModuleWindow
    void SetTitle(const char* title);
    void SwapBuffers();

public:
    // Miembros de la clase
    SDL_Window* window;
    SDL_Surface* screenSurface;
    SDL_GLContext context;
    int Height;
    int Width;
};
#endif