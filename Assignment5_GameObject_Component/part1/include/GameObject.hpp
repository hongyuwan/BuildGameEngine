#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <vector>

#include "Component.hpp"

class GameObject {
 public:
  GameObject() = default;
  ~GameObject();
    // Note: You may want to add member functions like "AddComponent" or "RemoveComponent"
  void AddComponent(Component* new_component);
  bool RemoveComponent(int idx);
    // Note: You may want to add member functions like 'Update' or 'Render'
  void update();

 private:
  std::vector<Component*> m_components;
};

#endif
