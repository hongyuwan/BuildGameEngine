#ifndef LRCONTROLLERCOMPONENT_HPP
#define LRCONTROLLERCOMPONENT_HPP

#include "ControllerComponent.hpp"

//inherit ControllerComponent
class LRControllerComponent : public ControllerComponent {
 public:
  LRControllerComponent(TransformComponent* tf) : ControllerComponent{tf} {};
  virtual ~LRControllerComponent(){};
  virtual void update();

 protected:
 bool handleEvent(SDL_Event* event);
  int accelerate = 5;
};

#endif