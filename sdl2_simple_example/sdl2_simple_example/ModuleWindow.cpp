#include "ModuleWindow.h"
#include "Application.h"
#include "Globals.h"

ModuleWindow::ModuleWindow(Application* app, bool start_enabled) : Module(app, start_enabled)
{
    window = nullptr;
    screenSurface = nullptr;
    context = nullptr;
}

ModuleWindow::~ModuleWindow()
{
    CleanUp();
}

bool ModuleWindow::Init()
{
    bool ret = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        ret = false;
    }
    else
    {
        int width = SCREEN_WIDTH * SCREEN_SIZE;
        int height = SCREEN_HEIGHT * SCREEN_SIZE;
        Uint32 flags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

        if (WIN_FULLSCREEN)
            flags |= SDL_WINDOW_FULLSCREEN;
        if (WIN_RESIZABLE)
            flags |= SDL_WINDOW_RESIZABLE;
        if (WIN_BORDERLESS)
            flags |= SDL_WINDOW_BORDERLESS;
        if (WIN_FULLSCREEN_DESKTOP)
            flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;

        window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);
        Width = width;
        Height = height;

        if (window == nullptr)
        {
            ret = false;
        }
        else
        {
            context = SDL_GL_CreateContext(window);
            if (context == nullptr)
            {
                SDL_Log("No se pudo crear el contexto OpenGL: %s", SDL_GetError());
                ret = false;
            }
            else
            {
                SDL_GL_MakeCurrent(window, context);
                SDL_GL_SetSwapInterval(1);
                glEnable(GL_DEPTH_TEST);
                glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
            }
        }
    }

    return ret;
}

static bool processEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            return false;
            break;
        default:
            ImGui_ImplSDL2_ProcessEvent(&event);
            break;
        }
    }
    return true;
}

bool ModuleWindow::CleanUp()
{
    if (context != nullptr)
    {
        SDL_GL_DeleteContext(context);
    }

    if (window != nullptr)
    {
        SDL_DestroyWindow(window);
    }

    SDL_Quit();
    return true;
}

void ModuleWindow::SetTitle(const char* title)
{
    if (window != nullptr)
    {
        SDL_SetWindowTitle(window, title);
    }
}

void ModuleWindow::SwapBuffers()
{
    SDL_GL_SwapWindow(window);
}

bool ModuleWindow::Start() {
    return true;
}

update_status ModuleWindow::PreUpdate(float dt) {
    return UPDATE_CONTINUE; 
}

update_status ModuleWindow::Update(float dt) {
    SwapBuffers();
    return UPDATE_CONTINUE; 
}

update_status ModuleWindow::PostUpdate(float dt) {
    return UPDATE_CONTINUE; 
}