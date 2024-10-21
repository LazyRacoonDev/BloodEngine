#pragma once

#include "Globals.h"
#include "Timer.h"

#include<vector>

class Module;
class ModuleWindow;

class Application 
{
public:
	ModuleWindow* window;

private:
	Timer timer;
	float dt;
	std::vector<Module*> modules;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();
	
	float GetFPS();
	float GetDT();
	float GetMS();

private:
	void AddModule(Module* mod);
	void PrepareUpdate();
	void FinishUpdate();
	
};
