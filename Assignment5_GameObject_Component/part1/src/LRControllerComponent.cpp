#include "LRControllerComponent.hpp"
#define MAX_PULL_EVENT_NUM 1000
#include <vector>

//inherit ControllerComponent
void LRControllerComponent::update() {

  std::vector<SDL_Event> other_events;
  SDL_Event e;
  while (SDL_PollEvent(&e) != 0) {
    if (!handleEvent(&e)) {
      other_events.emplace_back(e);
    }
  }
  for (SDL_Event& e : other_events)
    ;
  SDL_PushEvent(&e);
}

bool LRControllerComponent::handleEvent(SDL_Event* event) {
  bool getVaildInput = false;
  if (event->type == SDL_KEYDOWN) {
    switch (event->key.keysym.sym) {
      case SDLK_LEFT:
      case SDLK_a: {
        SDL_Log("Running to left");
        transform->updateSpeed(-accelerate, 0);
        getVaildInput = true;
        break;
      }
      case SDLK_RIGHT:
      case SDLK_d: {
        SDL_Log("Running to right");
        transform->updateSpeed(accelerate, 0);
        getVaildInput = true;
        break;
      }
      default:
        break;
    }

  } else if (event->type == SDL_KEYUP) {
    switch (event->key.keysym.sym) {
      case SDLK_LEFT:
      case SDLK_a:
      case SDLK_RIGHT:
      case SDLK_d: {
        SDL_Log("Stop");
        transform->updateSpeed(0, 0);
        getVaildInput = true;
        break;
      }
      default:
        break;
    }
  }
  return getVaildInput;
}

