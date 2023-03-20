#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#if defined(LINUX) || defined(MINGW)
    #include <SDL2/SDL.h>
#else // This works for Mac
    #include <SDL.h>
#endif

// I recommend a map for filling in the resource manager
#include <unordered_map>
#include <string>

class ResourceManager{
private:
    // TODO: Make constructor private 
	ResourceManager();
    ResourceManager(ResourceManager const& other)= delete; // Avoid copy constructor
    void operator=(ResourceManager const& other)=delete ; // Don't allow assignment.

//    std::unordered_map<ResName, ResFilePath> fileMap_;
//    std::unordered_map<ResName, T*> resMap_;
    // Destructor
    // In theory, this is never called
	~ResourceManager();
public:
    // TODO: Refactor to be a static function
    static void LoadResource(std::string image_filename);
    static void LoadTexture(std::string image_filename, SDL_Renderer* renderer);

    // TODO: Refactor to be a static function
    static SDL_Surface* GetResource(std::string image_filename);
    static SDL_Texture* GetTexture(std::string image_filename, SDL_Renderer* renderer);

private:
    static SDL_Surface* mSpriteSheet;
    static SDL_Texture* mTexture;

public:
    static std::unordered_map<std::string, SDL_Surface*> mResourceMap;
    static std::unordered_map<std::string, SDL_Texture*> mTextureMap;
};


#endif
