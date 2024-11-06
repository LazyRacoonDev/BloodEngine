#pragma once

#include "Globals.h"
#include "Timer.h"
#include<vector>

class Module;

class App
{
public:

private:
	Timer ms_timer;
	float dt;
	std::vector<Module*> list_modules;
public:
	App();
	~App();

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
