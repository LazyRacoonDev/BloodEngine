#include "ModuleRenderer.h"
#include "Application.h"

Mesh::Mesh() {}
Mesh::~Mesh() {
    delete[] vertex;
    delete[] index;
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Mesh::Render() {
    glEnableClientState(GL_VERTEX_ARRAY);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    glVertexPointer(3, GL_FLOAT, 0, NULL);
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, NULL);

    glDisableClientState(GL_VERTEX_ARRAY);
}

ModuleRenderer::ModuleRenderer(Application* app, bool start_enabled) : Module(app, start_enabled) {}

ModuleRenderer::~ModuleRenderer() {
    CleanUp();
}

bool ModuleRenderer::Init() {
    return true;
}

bool ModuleRenderer::Start() {
    if (model_path) {
        return LoadModel(model_path);
    }
    return true;
}

update_status ModuleRenderer::PreUpdate(float dt) {
    return UPDATE_CONTINUE;
}

update_status ModuleRenderer::Update(float dt) {
    for (Mesh* mesh : meshList) {
        mesh->Render();
    }
    return UPDATE_CONTINUE;
}

update_status ModuleRenderer::PostUpdate(float dt) {
    return UPDATE_CONTINUE;
}

bool ModuleRenderer::CleanUp() {
    for (Mesh* mesh : meshList) {
        delete mesh;
    }
    meshList.clear();
    return true;
}

bool ModuleRenderer::LoadModel(const char* file_path) {
    Assimp::Importer importer;
    const aiScene* currentScene = importer.ReadFile(file_path, aiProcess_Triangulate);

    if (currentScene && currentScene->HasMeshes()) {
        for (unsigned int i = 0; i < currentScene->mNumMeshes; i++) {
            ImportMesh(currentScene->mMeshes[i]);
        }
        return true;
    }
    else {
        return false;
    }
}

void ModuleRenderer::ImportMesh(aiMesh* aiMesh) {
    Mesh* currentMesh = new Mesh();

    currentMesh->vertexCount = aiMesh->mNumVertices;
    currentMesh->vertex = new float[currentMesh->vertexCount * 3];
    memcpy(currentMesh->vertex, aiMesh->mVertices, sizeof(float) * currentMesh->vertexCount * 3);

    if (aiMesh->HasFaces()) {
        currentMesh->indexCount = aiMesh->mNumFaces * 3;
        currentMesh->index = new uint[currentMesh->indexCount];

        for (uint i = 0; i < aiMesh->mNumFaces; ++i) {
            if (aiMesh->mFaces[i].mNumIndices == 3) {
                memcpy(&currentMesh->index[i * 3], aiMesh->mFaces[i].mIndices, 3 * sizeof(uint));
            }
            else {
            }
        }

        glGenBuffers(1, &currentMesh->VBO);
        glGenBuffers(1, &currentMesh->EBO);

        glBindBuffer(GL_ARRAY_BUFFER, currentMesh->VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * currentMesh->vertexCount * VERTEX_ATTRIBUTES, currentMesh->vertex, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, currentMesh->EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint) * currentMesh->indexCount, currentMesh->index, GL_STATIC_DRAW);

        meshList.push_back(currentMesh);
    }
    else {
        delete currentMesh;
    }
}