#pragma once
#include "Globals.h"
#include "Timer.h"
#include <vector>

class Module;
class ModuleWindow;
class ModuleInputs;  // Declaraci�n adelantada del m�dulo de inputs

class Application
{
public:
    ModuleWindow* window;       // M�dulo de ventana
    ModuleInputs* inputs;       // M�dulo de inputs (manejador de eventos)

private:
    Timer ms_timer;             // Temporizador para delta time
    float dt;                   // Delta time
    std::vector<Module*> list_modules;  // Lista de todos los m�dulos de la aplicaci�n

public:
    Application();
    ~Application();

    bool Init();                // Inicializa todos los m�dulos
    update_status Update();     // Llama a la secuencia de actualizaci�n de cada m�dulo
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