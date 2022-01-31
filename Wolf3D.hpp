#pragma once

#include "sre/SDLRenderer.hpp"
#include "sre/Material.hpp"
#include "WorldMap.hpp"
#include "FirstPersonController.hpp"
#include "rapidjson/rapidjson.h"


class Wolf3D {
public:
    Wolf3D();
private:
    void init();
    void update(float deltaTime);
    void render();
    void addCube(std::vector<glm::vec3>& vertexPositions, std::vector<glm::vec4>& textureCoordinates, int x, int z, int type);
    void renderDebugBricks(sre::RenderPass & renderPass);
    sre::SDLRenderer r;
    sre::Camera camera;
    WorldMap map;
    std::shared_ptr<sre::Mesh> walls;
    std::shared_ptr<sre::Mesh> floors;
    std::shared_ptr<sre::Material> wallMaterial;
    std::shared_ptr<sre::Material> floorMaterial;
    FirstPersonController fpsController;
    glm::vec4 floorColor;
    glm::vec4 ceilColor;
    bool debugBricks = true;
    bool lockRotation = false;
    //rapidjson::GenericArray arrayMoj;

};

