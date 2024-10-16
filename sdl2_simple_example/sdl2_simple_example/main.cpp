#include <GL/glew.h>
#include <chrono>
#include <thread>
#include <exception>
#include <SDL2/SDL.h>
#include "imgui_impl_sdl2.h"
#include "Window.h"
#include "Scene.h"

using namespace std;
using hrclock = chrono::high_resolution_clock;

static const int WINDOW_WIDTH = 1024;
static const int WINDOW_HEIGHT = 1024;
static const unsigned int FPS = 60;
static const auto FRAME_DT = 1.0s / FPS;

static void init_openGL() {
    glewInit();
    if (!GLEW_VERSION_3_0) throw exception("OpenGL 3.0 API is not available.");
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
}

static bool processEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            return false; // Cierra la ventana
        default:
            ImGui_ImplSDL2_ProcessEvent(&event);
            break;
        }
    }
    return true; // Continúa si no se cierra
}

int main(int argc, char** argv) {
    MyWindow window("SDL2 OpenGL Example", WINDOW_WIDTH, WINDOW_HEIGHT);

    init_openGL();

    Scene scene;    // Crear instancia de Scene
    scene.init();   // Inicializar la escena

    while (processEvents()) {
        const auto t0 = hrclock::now();

        // Renderizar la escena
        scene.render();

        window.swapBuffers(); // Intercambiar buffers para mostrar el nuevo frame

        const auto t1 = hrclock::now();
        const auto dt = t1 - t0;
        if (dt < FRAME_DT) {
            this_thread::sleep_for(FRAME_DT - dt); // Controlar la velocidad de los frames
        }
    }

    return 0; // Fin del programa
}