#include "Application.h"
#include "Module.h"
#include "ModuleWindow.h"

extern Application* External = nullptr;

Application::Application()
{
	External = this;

	window = new ModuleWindow(this);

	//importante el orden de llamada de modulos
	AddModule(window)

}