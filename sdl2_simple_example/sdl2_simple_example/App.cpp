#include "App.h"

#include "Module.h"


extern App* External = nullptr;

App::App()
{
	External = this;


}

App::~App()
{
	for (std::vector<Module*>::iterator it = list_modules.begin(); it != list_modules.end(); ++it)
	{
		delete (*it);
		(*it) = nullptr;
	}
}

bool App::Init()
{
	bool ret = true;

	// Call Init() in all modules
	for (std::vector<Module*>::const_iterator it = list_modules.cbegin(); it != list_modules.cend() && ret; ++it)
	{
		(*it)->Init();
	}

	// After all Init calls we call Start() in all modules
	LOG("Application Start --------------");
	for (std::vector<Module*>::const_iterator it = list_modules.cbegin(); it != list_modules.cend() && ret; ++it)
	{
		(*it)->Start();
	}

	ms_timer.Start();
	return ret;
}

// ---------------------------------------------
void App::PrepareUpdate()
{
	dt = (float)ms_timer.Read() / 1000.0f;
	ms_timer.Start();
}

// ---------------------------------------------
void App::FinishUpdate()
{
}

// Call PreUpdate, Update and PostUpdate on all modules
update_status App::Update()
{
	update_status ret = UPDATE_CONTINUE;
	PrepareUpdate();

	for (std::vector<Module*>::const_iterator it = list_modules.cbegin(); it != list_modules.cend() && ret == UPDATE_CONTINUE; ++it)
	{
		(*it)->PreUpdate(dt);
	}

	for (std::vector<Module*>::const_iterator it = list_modules.cbegin(); it != list_modules.cend() && ret == UPDATE_CONTINUE; ++it)
	{
		(*it)->Update(dt);
	}

	for (std::vector<Module*>::const_iterator it = list_modules.cbegin(); it != list_modules.cend() && ret == UPDATE_CONTINUE; ++it)
	{
		(*it)->PostUpdate(dt);
	}

	FinishUpdate();
	return ret;
}

bool App::CleanUp()
{
	bool ret = true;
	for (std::vector<Module*>::reverse_iterator it = list_modules.rbegin(); it != list_modules.rend() && ret; ++it)
	{
		ret = (*it)->CleanUp();
	}
	return ret;
}

float App::GetFPS()
{
	return 1 / dt;
}

float App::GetDT()
{
	return dt;
}

float App::GetMS()
{
	return dt * 1000;
}

void App::AddModule(Module* mod)
{
	list_modules.push_back(mod);
}