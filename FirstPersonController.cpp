#include "FirstPersonController.hpp"
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/rotate_vector.hpp>
#include <iostream>

using namespace sre;
using namespace glm;


FirstPersonController::FirstPersonController(sre::Camera * camera)
:camera(camera)
{
    camera->setPerspectiveProjection(45,0.1f,1000);
    position = vec3(0,0,0);
}


void FirstPersonController::update(float deltaTime){
    // TODO implement the camera movement using position and rotation here
    //camera->lookAt(vec3(0,0,0), vec3(this->position.x,this->position.y,this->position.z), vec3{0,1,0});
    camera->setPositionAndRotation(position, vec3(0, rotation ,0));
}

void FirstPersonController::onKey(SDL_Event &event) {
    // TODO implement key input here
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    auto rotationMatrix = mat3(glm::rotate(radians(rotation), vec3(0,1,0)));
    /*if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_a){*/
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_a) {
        //position.x -= 0.05;
        position += vec3(rotationMatrix * vec3(-0.05,0,0) );
    }
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_d){
        position += vec3(rotationMatrix * vec3(+0.05,0,0) );
    }
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_s){
        position += vec3(rotationMatrix * vec3(0,0,0.05) );
    }
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_w){
        position += vec3(rotationMatrix * vec3(0,0,-0.05));
    }
    /*if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
        position += vec3(rotationMatrix * vec3(0, 0.05, 0));
    }*/
}

void FirstPersonController::onMouse(SDL_Event &event) {
    // TODO implement mouse input here
    int x, y;
    Uint32 buttons;

    SDL_PumpEvents();  // make sure we have the latest mouse state.

    buttons = SDL_GetMouseState(&x, &y);

    //std::cout<<"Mouse cursor is at "<< x << " " << y << std::endl;
    rotation = -x;
}

void FirstPersonController::setInitialPosition(glm::vec2 position, float rotation) {
    this->position = glm::vec3(position.x,0,position.y);
    this->rotation = rotation;
}
