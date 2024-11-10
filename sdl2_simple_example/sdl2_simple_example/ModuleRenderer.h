#ifndef __MODULERENDERER_H__
#define __MODULERENDERER_H__

#include "Module.h"
#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <vector>
#include <GL/glew.h>
#include <iostream>

#define VERTEX_ATTRIBUTES 3

struct Mesh {
    uint id_vertex = 0;
    uint vertexCount = 0;
    float* vertex = nullptr;

    uint id_index = 0;
    uint indexCount = 0;
    uint* index = nullptr;

    uint VBO = 0; // Vertex Buffer Object
    uint EBO = 0; // Element Buffer Object

    Mesh();
    ~Mesh();
    void Render();
};

class ModuleRenderer : public Module {
public:
    ModuleRenderer(Application* app, bool start_enabled = true);
    ~ModuleRenderer();

    bool Init() override;
    bool Start() override;
    update_status PreUpdate(float dt) override;
    update_status Update(float dt) override;
    update_status PostUpdate(float dt) override;
    bool CleanUp() override;

private:
    std::vector<Mesh*> meshList;
    const char* model_path = "sdl2_simple_example\sdl2_simple_example\Assets\BakerHouse.fbx";

    bool LoadModel(const char* file_path);
    void ImportMesh(aiMesh* aiMesh);
};
#endif