#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>

class Scene {
public:
    Scene();  // Constructor
    ~Scene(); // Destructor

    void init();             // Inicializaci�n de la escena
    void render();           // Renderizado de la escena
    void cleanup();          // Limpieza de recursos

private:
    void drawAxes();         // M�todo privado para dibujar los ejes
};