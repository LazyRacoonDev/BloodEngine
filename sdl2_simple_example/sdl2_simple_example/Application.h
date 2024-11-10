#pragma once
#include "Globals.h"
#include "Timer.h"
#include <vector>

class Module;
class ModuleWindow;
class ModuleInputs;  // Declaración adelantada del módulo de inputs

class Application
{
public:
    ModuleWindow* window;       // Módulo de ventana
    ModuleInputs* inputs;       // Módulo de inputs (manejador de eventos)

private:
    Timer ms_timer;             // Temporizador para delta time
    float dt;                   // Delta time
    std::vector<Module*> list_modules;  // Lista de todos los módulos de la aplicación

public:
    Application();
    ~Application();

    bool Init();                // Inicializa todos los módulos
    update_status Update();     // Llama a la secuencia de actualización de cada módulo
    bool CleanUp();             // Limpia y elimina todos los módulos

    float GetFPS();             // Obtiene el FPS actual
    float GetDT();              // Obtiene el delta time actual
    float GetMS();              // Obtiene el tiempo del cuadro en ms

private:
    void AddModule(Module* mod);  // Añade un módulo a la lista de módulos
    void PrepareUpdate();         // Prepara el ciclo de actualización
    void FinishUpdate();          // Finaliza el ciclo de actualización
};

extern Application* External;      // Instancia global de Application