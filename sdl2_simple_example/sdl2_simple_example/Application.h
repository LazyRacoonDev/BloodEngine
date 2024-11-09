#pragma once
#include "Globals.h"
#include "Timer.h"
#include<vector>

class Module;
class ModuleWindow;
//class ModuleConsole;

class Application
{
public:
	ModuleWindow* window;
	//ModuleConsole* console;
private:
	Timer ms_timer;
	float dt;
	std::vector<Module*> list_modules;
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

extern Application* External;
