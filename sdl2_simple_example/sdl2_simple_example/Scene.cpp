#include "Scene.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Scene::Scene() {
    // Constructor: Inicializar recursos aquí si es necesario
    // Ejemplo: si en el futuro tienes buffers o shaders, podrías inicializarlos
}

Scene::~Scene() {
    cleanup(); // Llamar a cleanup al destruir la escena
}

void Scene::init() {
    // Configuraciones iniciales para la escena
    glEnable(GL_DEPTH_TEST);                  // Habilitar test de profundidad
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);    // Color de fondo de la pantalla (gris)
}

void Scene::render() {
    // Limpiar el buffer de color y profundidad
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Configuración de la cámara (básica, se puede mejorar)
    glm::dvec3 cameraPos(0.0, 0.0, 5.0);    // Posición de la cámara
    glm::dvec3 cameraTarget(0.0, 0.0, 0.0); // Punto al que mira
    glm::dvec3 cameraUp(0.0, 1.0, 0.0);     // Vector arriba
    glm::dmat4 viewMatrix = glm::lookAt(cameraPos, cameraTarget, cameraUp);
    glLoadMatrixd(glm::value_ptr(viewMatrix));

    // Dibujar los ejes
    drawAxes();
}

void Scene::drawAxes() {
    glBegin(GL_LINES);

    // Eje X - Rojo
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);

    // Eje Y - Verde
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);

    // Eje Z - Azul
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 1.0f);

    glEnd();
}

void Scene::cleanup() {
}