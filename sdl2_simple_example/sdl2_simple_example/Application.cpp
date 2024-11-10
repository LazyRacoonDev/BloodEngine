#include "Application.h"
#include "Module.h"
#include "ModuleWindow.h"
#include "ModuleInputs.h"

Application* External = nullptr;

Application::Application()
{
    External = this;

    // Inicialización de módulos
    window = new ModuleWindow(this);
    inputs = new ModuleInputs(this); // Añadimos el módulo de inputs

    // Agregamos los módulos a la lista de la aplicación
    AddModule(window);
    AddModule(inputs);
}

Application::~Application()
{
    for (std::vector<Module*>::iterator it = list_modules.begin(); it != list_modules.end(); ++it)
    {
        delete (*it);
        (*it) = nullptr;
    }
}

bool Application::Init()
{
    bool ret = true;

    for (std::vector<Module*>::const_iterator it = list_modules.cbegin(); it != list_modules.cend() && ret; ++it)
    {
        (*it)->Init();
    }

    for (std::vector<Module*>::const_iterator it = list_modules.cbegin(); it != list_modules.cend() && ret; ++it)
    {
        (*it)->Start();
    }

    ms_timer.Start();
    return ret;
}

void Application::PrepareUpdate()
{
    dt = static_cast<float>(ms_timer.Read()) / 1000.0f;
    ms_timer.Start();
}

void Application::FinishUpdate()
{
    // Puedes manejar la sincronización del frame aquí si es necesario
}

update_status Application::Update()
{
    update_status ret = UPDATE_CONTINUE;

    // Prepara el ciclo de actualización
    PrepareUpdate();

    // Llama a PreUpdate, Update, y PostUpdate de cada módulo
    for (std::vector<Module*>::const_iterator it = list_modules.cbegin(); it != list_modules.cend() && ret == UPDATE_CONTINUE; ++it)
    {
        ret = (*it)->PreUpdate(dt);
    }

    for (std::vector<Module*>::const_iterator it = list_modules.cbegin(); it != list_modules.cend() && ret == UPDATE_CONTINUE; ++it)
    {
        ret = (*it)->Update(dt);
    }

    for (std::vector<Module*>::const_iterator it = list_modules.cbegin(); it != list_modules.cend() && ret == UPDATE_CONTINUE; ++it)
    {
        ret = (*it)->PostUpdate(dt);
    }

    FinishUpdate();
    return ret;
}

bool Application::CleanUp()
{
    bool ret = true;

    for (std::vector<Module*>::reverse_iterator it = list_modules.rbegin(); it != list_modules.rend() && ret; ++it)
    {
        ret = (*it)->CleanUp();
    }
    return ret;
}

float Application::GetFPS()
{
    return 1.0f / dt;
}

float Application::GetDT()
{
    return dt;
}

float Application::GetMS()
{
    return dt * 1000.0f;
}

void Application::AddModule(Module* mod)
{
    list_modules.push_back(mod);
}