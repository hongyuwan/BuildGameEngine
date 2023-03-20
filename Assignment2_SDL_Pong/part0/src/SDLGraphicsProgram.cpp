#include "SDLGraphicsProgram.hpp"
#include "Rectangle.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <time.h>       /* time */


const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

class LTimer
{
public:
    //Initializes variables
    LTimer();

    //The various clock actions
    void start();
    void stop();
    void pause();
    void unpause();

    //Gets the timer's time
    Uint32 getTicks();

    //Checks the status of the timer
    bool isStarted();
    bool isPaused();

private:
    //The clock time when the timer started
    Uint32 mStartTicks;

    //The ticks stored when the timer was paused
    Uint32 mPausedTicks;

    //The timer status
    bool mPaused;
    bool mStarted;
};

LTimer::LTimer()
{
    //Initialize the variables
    mStartTicks = 0;
    mPausedTicks = 0;

    mPaused = false;
    mStarted = false;
}

void LTimer::start()
{
    //Start the timer
    mStarted = true;

    //Unpause the timer
    mPaused = false;

    //Get the current clock time
    mStartTicks = SDL_GetTicks();
    mPausedTicks = 0;
}

void LTimer::stop()
{
    //Stop the timer
    mStarted = false;

    //Unpause the timer
    mPaused = false;

    //Clear tick variables
    mStartTicks = 0;
    mPausedTicks = 0;
}

void LTimer::pause()
{
    //If the timer is running and isn't already paused
    if( mStarted && !mPaused )
    {
        //Pause the timer
        mPaused = true;

        //Calculate the paused ticks
        mPausedTicks = SDL_GetTicks() - mStartTicks;
        mStartTicks = 0;
    }
}

void LTimer::unpause()
{
    //If the timer is running and paused
    if( mStarted && mPaused )
    {
        //Unpause the timer
        mPaused = false;

        //Reset the starting ticks
        mStartTicks = SDL_GetTicks() - mPausedTicks;

        //Reset the paused ticks
        mPausedTicks = 0;
    }
}

Uint32 LTimer::getTicks()
{
    //The actual timer time
    Uint32 time = 0;

    //If the timer is running
    if( mStarted )
    {
        //If the timer is paused
        if( mPaused )
        {
            //Return the number of ticks when the timer was paused
            time = mPausedTicks;
        }
        else
        {
            //Return the current time minus the start time
            time = SDL_GetTicks() - mStartTicks;
        }
    }

    return time;
}

bool LTimer::isStarted()
{
    //Timer is running and paused or unpaused
    return mStarted;
}

bool LTimer::isPaused()
{
    //Timer is running and paused
    return mPaused && mStarted;
}
// Initialization function
// Returns a true or false value based on successful completion of setup.
// Takes in dimensions of window.
SDLGraphicsProgram::SDLGraphicsProgram(int w, int h):mScreenWidth(w),mScreenHeight(h){
  // Initialize random number generation.
   srand(time(NULL));
    // Setup blocks
    mRectangles = new Rectangle[mBlocks];
    for(int i=0; i < mBlocks; ++i){
        mRectangles[i].Init(mScreenWidth,mScreenHeight);
    }


  // Initialization flag
    bool success = true;
  // String to hold any errors that occur.
  std::stringstream errorStream;
  // The window we'll be rendering to
  mWindow = NULL;
  // Render flag

	// Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO)< 0){
		errorStream << "SDL could not initialize! SDL Error: " << SDL_GetError() << "\n";
		success = false;
	}
	else{

		//Create window
		mWindow = SDL_CreateWindow( "Lab",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                mScreenWidth,
                                mScreenHeight,
                                SDL_WINDOW_SHOWN );

        // Check if Window did not create.
        if( mWindow == NULL ){
			errorStream << "Window could not be created! SDL Error: " << SDL_GetError() << "\n";
			success = false;
		}

		//Create a Renderer to draw on
        mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
        // Check if Renderer did not create.
        if( mRenderer == NULL ){
			errorStream << "Renderer could not be created! SDL Error: " << SDL_GetError() << "\n";
			success = false;
		}
        
  }

  // If initialization did not work, then print out a list of errors in the constructor.
  if(!success){
    errorStream << "Failed to initialize!\n";
    std::string errors=errorStream.str();
    std::cout << errors << "\n";
  }else{
    std::cout << "No SDL, or OpenGL, errors Detected\n\n";
  }
}




// Proper shutdown and destroy initialized objects
SDLGraphicsProgram::~SDLGraphicsProgram(){
    if(nullptr != mRectangles){
        delete[] mRectangles;
    }

    // Destroy Renderer
    SDL_DestroyRenderer(mRenderer);
	//Destroy window
	SDL_DestroyWindow( mWindow );
    // Point mWindow to NULL to ensure it points to nothing.
	mRenderer = NULL;
    mWindow = NULL;
	//Quit SDL subsystems
	SDL_Quit();
}



// Update OpenGL
void SDLGraphicsProgram::Update()
{
	// Nothing yet!
    SDL_SetRenderDrawColor(mRenderer, 0x22,0x22,0x22,0xFF);
    SDL_RenderClear(mRenderer);  
    for(int i =0; i < mBlocks; i++){
        mRectangles[i].Update(mScreenWidth,mScreenHeight);
    }
}


// Render
// The render function gets called once per loop
void SDLGraphicsProgram::Render(){

    for(int i =0; i < mBlocks; i++){
        mRectangles[i].Render(GetSDLRenderer());
    }

    SDL_RenderPresent(mRenderer);
}



//Loops forever!
void SDLGraphicsProgram::Loop(){

    // Main loop flag
    // If this is quit = 'true' then the program terminates.
    bool quit = false;

    //Timer for fps
    LTimer fpsTimer;

    //Timer for frame
    LTimer capTimer;
    // Event handler that handles various events in SDL
    // that are related to input and output
    SDL_Event e;
    // Enable text input
    SDL_StartTextInput();
    //start calculate fps
    int countedFrames = 0;
    fpsTimer.start();
    // While application is running
    while(!quit){

        //start cap timer
        capTimer.start();
      //Handle events on queue
      while(SDL_PollEvent( &e ) != 0){
        // User posts an event to quit
        // An example is hitting the "x" in the corner of the window.
        if(e.type == SDL_QUIT){
          quit = true;
        }		
      }
        float avgFPS = countedFrames / ( fpsTimer.getTicks() / 1000.f );
        if( avgFPS > 2000000 )
        {
            avgFPS = 0;
        }
        std::cout<<"Average Frames Per Second (With Cap) " << avgFPS<< std::endl;
	  // Update our scene
	  Update();
      // Render
      Render();
      //Update screen of our specified window
      // SDL_GL_SwapWindow(getSDLWindow());
        ++countedFrames;
        // if frame finish before
        int frameTicks = capTimer.getTicks();
        if( frameTicks < SCREEN_TICKS_PER_FRAME )
        {
            // wait last time
            SDL_Delay( SCREEN_TICKS_PER_FRAME - frameTicks );
        }
    }

    //Disable text input
    SDL_StopTextInput();
}

// Get Pointer to Window
SDL_Window* SDLGraphicsProgram::GetSDLWindow(){
  return mWindow;
}

// Get Pointer to Renderer
SDL_Renderer* SDLGraphicsProgram::GetSDLRenderer(){
  return mRenderer;
}
