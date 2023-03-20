#ifndef SDLGRAPHICSPROGRAM
#define SDLGRAPHICSPROGRAM

#include <stdlib.h>
#include <time.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "IGraphicsEngineRenderer.hpp"
#include "GameObject.hpp"
// Try toggling this number!
#define OBJECT_NUM 2

/**
 * This class sets up the main game engine
 */
class Engine {
 public:
  /**
   * Constructor of Engine
   */
  Engine();
  /**
   * Destructor
   */
  ~Engine();
  /**
   * Input engine
   */
  void Input(bool* quit);
  /**
   * Per frame update
   */
  void Update();
  /**
   * Per frame render. Renders everything
   */
  void Render();
  /**
   * Main Game Loop that runs forever
   */
  void MainGameLoop();
  /**
   * Initialization and shutdown pattern
   * Explicitly call 'Start' to launch the engine
   */
  void Start();
  /**
   * Initialization and shutdown pattern
   * Explicitly call 'Shutdown' to terminate the engine
   */
  void Shutdown();

  /**
   * Request to startup the Graphics Subsystem
   */
  void InitializeGraphicsSubSystem();

 private:
  // Engine Subsystem
  // Setup the Graphics Rendering Engine
  GraphicsEngineRenderer* m_renderer = nullptr;
  std::vector<GameObject> gameObjects;
};

#endif
