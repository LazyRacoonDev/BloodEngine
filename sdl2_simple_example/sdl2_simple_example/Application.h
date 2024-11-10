#pragma once
#include "Globals.h"
#include "Timer.h"
#include <vector>

class Module;
class ModuleWindow;
class ModuleInputs;
class ModuleCamera;  // Declaraci�n adelantada de ModuleCamera

class Application
{
public:
    ModuleWindow* window;       // M�dulo de ventana
    ModuleInputs* inputs;       // M�dulo de inputs (manejador de eventos)
    ModuleCamera* camera;       // M�dulo de c�mara para control de vista

private:
    Timer ms_timer;             // Temporizador para delta time
    float dt;                   // Delta time
    std::vector<Module*> list_modules;  // Lista de todos los m�dulos de la aplicaci�n

public:
    Application();
    ~Application();

    bool Init();     // Inicializa todos los m�dulos
    update_status PreUpdate();
    update_status Update();     // Llama a la secuencia de actualizaci�n de cada m�dulo
    update_status PostUpdate;
    bool CleanUp();             // Limpia y elimina todos los m�dulos

    float GetFPS();             // Obtiene el FPS actual
    float GetDT();              // Obtiene el delta time actual
    float GetMS();              // Obtiene el tiempo del cuadro en ms

private:
    void AddModule(Module* mod);  // A�ade un m�dulo a la lista de m�dulos
    void PrepareUpdate();         // Prepara el ciclo de actualizaci�n
    void FinishUpdate();          // Finaliza el ciclo de actualizaci�n
};

extern Application* External;      // Instancia global de Application