#ifndef __ModuleWindow_H__
#define __ModuleWindow_H__
#include "Module.h"

class Application;

class ModuleWindow : public Module
{
public:
	ModuleWindow(Application* app, bool start_enabled = true);

	virtual ~ModuleWindow();

	bool Init() override;
	bool CleanUp() override;

	void SetTitle(const char* title);

public:
	SDL_Window* window;

	SDL_Surface* screenSurface;

	int height;
	int width;
};
#endif // __ModuleWindow_H__