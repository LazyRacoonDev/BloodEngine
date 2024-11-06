#pragma once
<<<<<<< HEAD:sdl2_simple_example/sdl2_simple_example/Application.h

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
=======
>>>>>>> parent of e599065 (Created Module and Apps):sdl2_simple_example/sdl2_simple_example/App.h
