#ifndef SDLGRAPHICSPROGRAM
#define SDLGRAPHICSPROGRAM

// ==================== Libraries ==================
// Depending on the operating system we use
// The paths to SDL are actually different.
// The #define statement should be passed in
// when compiling using the -D argument.
// This gives an example of how a programmer
// may support multiple platforms with different
// dependencies.
#if defined(LINUX) || defined(MINGW)
    #include <SDL2/SDL.h>
#else // This works for Mac
    #include <SDL.h>
#endif

// The glad library helps setup OpenGL extensions.
#include <glad/glad.h>

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
// Purpose:
// This class sets up a full graphics program using SDL
//
//
//
class SDLGraphicsProgram{
public:

    // Constructor
    SDLGraphicsProgram(int w, int h);
    // Destructor
    ~SDLGraphicsProgram();
    // Setup OpenGL
    bool initGL();
    // Clears the screen
    void clear();
    // Flips to new buffer
    void flip();
    // Delay rendering
    void delay(int milliseconds);
    // loop that runs forever
    void loop();
    void Input();
    // Get Pointer to Window
    SDL_Window* getSDLWindow();
    // Draw a simple rectangle
    void DrawRectangle(int x, int y, int w, int h, int r ,int g, int b, int n);
    bool isWKeyDown();
    bool isSKeyDown();
    bool isUpArrowKeyDown();
    bool isDownArrowKeyDown();
    bool isKeyDown();
    bool isRunning();


private:
    // Screen dimension constants
    int screenHeight;
    int screenWidth;
    // The window we'll be rendering to
    SDL_Window* gWindow ;
    // Our renderer
    SDL_Renderer* gRenderer;
    bool buttons[4]={};
    bool pressKey=false;
    bool running=true;
//    SDL_Event event;
};

enum Buttons
{
    PaddleOneUp,
    PaddleOneDown,
    PaddleTwoUp,
    PaddleTwoDown,
};
// Initialization function
// Returns a true or false value based on successful completion of setup.
// Takes in dimensions of window.
SDLGraphicsProgram::SDLGraphicsProgram(int w, int h):screenWidth(w),screenHeight(h){
	// Initialization flag
	bool success = true;
	// String to hold any errors that occur.
	std::stringstream errorStream;
	// The window we'll be rendering to
	gWindow = NULL;
	// Render flag

	// Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO)< 0){
		errorStream << "SDL could not initialize! SDL Error: " << SDL_GetError() << "\n";
		success = false;
	}
	else{
	    //Create window
    	gWindow = SDL_CreateWindow( "Lab", 100, 100, screenWidth, screenHeight, SDL_WINDOW_SHOWN );

        // Check if Window did not create.
        if( gWindow == NULL ){
			errorStream << "Window could not be created! SDL Error: " << SDL_GetError() << "\n";
			success = false;
		}

		//Create a Renderer to draw on
        gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
        // Check if Renderer did not create.
        if( gRenderer == NULL ){
            errorStream << "Renderer could not be created! SDL Error: " << SDL_GetError() << "\n";
            success = false;
        }
  	}

    
    
    // If initialization did not work, then print out a list of errors in the constructor.
    if(!success){
        errorStream << "SDLGraphicsProgram::SDLGraphicsProgram - Failed to initialize!\n";
        std::string errors=errorStream.str();
        SDL_Log("%s\n",errors.c_str());
    }else{
        SDL_Log("SDLGraphicsProgram::SDLGraphicsProgram - No SDL, GLAD, or OpenGL, errors detected during initialization\n\n");
    }
    bool isquit = false;
    SDL_Event event;
    while (!isquit) {
        if (SDL_PollEvent( & event)) {
            if (event.type == SDL_QUIT) {
                isquit = true;
            }
        }
        isquit = true;
    }
}


// Proper shutdown of SDL and destroy initialized objects
SDLGraphicsProgram::~SDLGraphicsProgram(){
    //Destroy window
	SDL_DestroyWindow( gWindow );
	// Point gWindow to NULL to ensure it points to nothing.
	gWindow = NULL;
	//Quit SDL subsystems
	SDL_Quit();
}
void SDLGraphicsProgram::Input() {
    // Event handler that handles various events in SDL
    // that are related to input and output
    SDL_Event event;
    // Handle events on queue

    while (SDL_PollEvent(&event) != 0) {
        // User posts an event to quit
        // An example is hitting the "x" in the corner of the window.
        // printf("Input SDL_PollEvent one\n");

        if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_q || event.key.keysym.sym == SDLK_ESCAPE) {
            running= false;
        }
        else if (event.type == SDL_KEYDOWN)
        {
            pressKey=true;
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                running = false;
            }
            else if (event.key.keysym.sym == SDLK_w)
            {
                buttons[Buttons::PaddleOneUp] = true;
            }
            else if (event.key.keysym.sym == SDLK_s)
            {
                buttons[Buttons::PaddleOneDown] = true;
            }
            else if (event.key.keysym.sym == SDLK_UP)
            {
                buttons[Buttons::PaddleTwoUp] = true;
            }
            else if (event.key.keysym.sym == SDLK_DOWN)
            {
                buttons[Buttons::PaddleTwoDown] = true;
            }
        }
        else if (event.type == SDL_KEYUP)
        {
            pressKey=false;
            if (event.key.keysym.sym == SDLK_w)
            {
                buttons[Buttons::PaddleOneUp] = false;
            }
            else if (event.key.keysym.sym == SDLK_s)
            {
                buttons[Buttons::PaddleOneDown] = false;
            }
            else if (event.key.keysym.sym == SDLK_UP)
            {
                buttons[Buttons::PaddleTwoUp] = false;
            }
            else if (event.key.keysym.sym == SDLK_DOWN)
            {
                buttons[Buttons::PaddleTwoDown] = false;
            }
        }
    }
}

// Initialize OpenGL
// Setup any of our shaders here.
bool SDLGraphicsProgram::initGL(){
	//Success flag
	bool success = true;

	return success;
}


// clear
// Clears the screen
void SDLGraphicsProgram::clear(){
	// Nothing yet!
    SDL_SetRenderDrawColor(gRenderer, 0x44,0x44,0x4,0xFF);
    SDL_RenderClear(gRenderer);   
}
// Flip
// The flip function gets called once per loop
// It swaps out the previvous frame in a double-buffering system
void SDLGraphicsProgram::flip(){
	// Nothing yet!
    SDL_RenderPresent(gRenderer);
}


void SDLGraphicsProgram::delay(int milliseconds){
    SDL_Delay(milliseconds); 
}


//Loops forever!
void SDLGraphicsProgram::loop() {
    // Main loop flag
    // If this is quit = 'true' then the program terminates.
    bool quit = false;
    // Event handler that handles various events in SDL
    // that are related to input and output
    SDL_Event event;
    // Enable text input
    SDL_StartTextInput();
    // While application is running
    while (!quit) {
        //Handle events on queue
        while (SDL_PollEvent(&event) != 0) {
            // User posts an event to quit
            // An example is hitting the "x" in the corner of the window.
            if (event.type == SDL_QUIT) {
                quit = true;
            }


            //Update screen of our specified window
            SDL_GL_SwapWindow(getSDLWindow());
        }

        //Disable text input
        SDL_StopTextInput();
    }
}


// Get Pointer to Window
SDL_Window* SDLGraphicsProgram::getSDLWindow(){
  return gWindow;
}


// Okay, render our rectangles!
void SDLGraphicsProgram::DrawRectangle(int x, int y, int w, int h, int r, int g, int b, int n){
    SDL_Rect fillRect = {x,y,w,h};
    SDL_SetRenderDrawColor(gRenderer, r, g, b, n);
//    SDL_RenderDrawRect(gRenderer, &fillRect);
    SDL_RenderFillRect(gRenderer, &fillRect);
}

bool SDLGraphicsProgram::isWKeyDown(){
    if (buttons[Buttons::PaddleOneUp]) {

        return true;
    }
    else {

        return false;}
}

bool SDLGraphicsProgram::isSKeyDown(){
    if (buttons[Buttons::PaddleOneDown]) {

        return true;
    }
    else {

        return false;}
}

bool SDLGraphicsProgram::isUpArrowKeyDown(){
    if (buttons[Buttons::PaddleTwoUp]) {

        return true;
    }
    else {

        return false;}
}

bool SDLGraphicsProgram::isDownArrowKeyDown(){
    if (buttons[Buttons::PaddleTwoDown]) {

        return true;
    }
    else {

        return false;}
}

bool SDLGraphicsProgram::isKeyDown(){
    if (pressKey) {

        return true;
    }
    else {

        return false;}
}

bool SDLGraphicsProgram::isRunning() {
    if (running) {
        return true;
    }
    else {
        return false;}
}
// Include the pybindings
#include <pybind11/pybind11.h>

namespace py = pybind11;


// Creates a macro function that will be called
// whenever the module is imported into python
// 'mygameengine' is what we 'import' into python.
// 'm' is the interface (creates a py::module object)
//      for which the bindings are created.
//  The magic here is in 'template metaprogramming'
PYBIND11_MODULE(mygameengine, m){
    m.doc() = "our game engine as a library"; // Optional docstring

    py::class_<SDLGraphicsProgram>(m, "SDLGraphicsProgram")
            .def(py::init<int,int>(), py::arg("w"), py::arg("h"))   // our constructor
            .def("clear", &SDLGraphicsProgram::clear) // Expose member methods
            .def("delay", &SDLGraphicsProgram::delay) 
            .def("flip", &SDLGraphicsProgram::flip) 
            .def("loop", &SDLGraphicsProgram::loop) 
            .def("DrawRectangle", &SDLGraphicsProgram::DrawRectangle)
            .def("isWKeyDown", &SDLGraphicsProgram::isWKeyDown)
            .def("isSKeyDown", &SDLGraphicsProgram::isSKeyDown)
            .def("isUpArrowKeyDown", &SDLGraphicsProgram::isUpArrowKeyDown)
            .def("isDownArrowKeyDown", &SDLGraphicsProgram::isDownArrowKeyDown)
            .def("Input", &SDLGraphicsProgram::Input)
            .def("isKeyDown", &SDLGraphicsProgram::isKeyDown)
            .def("isRunning", &SDLGraphicsProgram::isRunning);
// We do not need to expose everything to our users!
//            .def("getSDLWindow", &SDLGraphicsProgram::getSDLWindow, py::return_value_policy::reference) 
}











#endif
