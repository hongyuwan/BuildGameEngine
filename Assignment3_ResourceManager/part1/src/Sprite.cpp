#include "Sprite.hpp"
#include <iostream>
#include "ResourceManager.hpp"

// Constructor for our sprite class
Sprite::Sprite(SDL_Renderer* renderer, int x, int y, std::string image_filename){

    mXPosition = x;
    mYPosition = y;


    // TODO: Really all you want to do is retrieve the spritesheet and
    //       the texture from the resource manager. Make the resource
    //       manager otherwise do all of the hard work.
    //
    //       Don't forget to #include your Resource Manager where it is used.
    
    // An SDL Surface contains pixel data to draw an image
//	ResourceManager::LoadResource(image_filename.c_str());
    SDL_Surface* spriteSheet =ResourceManager::GetResource(image_filename.c_str());
    if(spriteSheet == nullptr){
        std::cerr << image_filename << " not found!\n";
    }else{
        std::cout << "SDL_LoadBMP allocated\n";
    }

    // Texture data on the GPU that we keep track of
    mTexture = ResourceManager::GetTexture(image_filename.c_str(),renderer);
    if(nullptr == mTexture){
        std::cerr << "Error creating texture\n";
    }else{
        std::cout << "SDL_Texture allocated\n";
    }
    // Free surface once we are done setting up our texture
//    SDL_FreeSurface(spriteSheet);
}

// TODO:    Make sure spritesheet and texture are destroyed
//          but is this the right place?
//          Consider adding a 'destroy' member function instead.
void Sprite::destroy() {
    // Free memory
    while (ResourceManager::mResourceMap.begin() != ResourceManager::mResourceMap.end())
    {
        if (ResourceManager::mResourceMap.begin()->second != nullptr) {
            std::cout<<"free memory"<<std::endl;
            delete ResourceManager::mResourceMap.begin()->second;
            ResourceManager::mResourceMap.erase(ResourceManager::mResourceMap.begin());
        }
    }


}
//          Ideally, we want all destruction of resources to take
//          place in our resource managers. Because if a resource
//          is used by many sprites, the resource manager will be
//          the place to know when to delete a resource.
Sprite::~Sprite(){

//    destroy();

}


// Copy Constructor
//
// NOTE: This only does a 'shallow' copy, in order to
//       to do a true copy, we need to allocate a new texture
//       and assign it to mTexture.
Sprite::Sprite(const Sprite& rhs)
{
    std::cout << "Copy Construtor called\n";
    mXPosition      = rhs.mXPosition;
    mYPosition      = rhs.mYPosition;
    mCurrentFrame   = rhs.mCurrentFrame;
    mLastFrame      = rhs.mLastFrame;
    mTexture        = rhs.mTexture;
    spriteSheet     = rhs.spriteSheet;
    mSrc            = rhs.mSrc;
    mDest           = rhs.mDest;
}


// Update the current frame we are on
void Sprite::Update(int x, int y, int frame){
	// The part of the image that we want to render
	mCurrentFrame = frame;
	if(mCurrentFrame>6){
		mCurrentFrame=0;
	}        

	// Here I am selecting which frame I want to draw
	// from our sprite sheet. Think of this as just
	// using a mouse to draw a rectangle around the
	// sprite that we want to draw.
	mSrc.x = mCurrentFrame*75;
	mSrc.y = 0;
	mSrc.w = 75;
	mSrc.h = 87;

	// Where we want the rectangle to be rendered at.
	// This is an actual 'quad' that will draw our
	// source image on top of.	
	mDest.x = mXPosition; 
	mDest.y = mYPosition;
	mDest.w = 128;
	mDest.h = 128;
}

// Render our sprite as its position(mDest) and
// using our texture mTexture,
// mSrc represents the portion of the mTexture that
// we want to draw onto our mDest.
void Sprite::Render(SDL_Renderer* renderer){
    SDL_RenderCopy(renderer, mTexture, &mSrc, &mDest);
}
