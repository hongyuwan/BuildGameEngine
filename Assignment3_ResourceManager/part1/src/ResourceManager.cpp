// I recommend an unordered_map for filling in the resource manager
#include "ResourceManager.hpp"
#include <iterator>
#include <iostream>

//spritesheet
std::unordered_map<std::string, SDL_Surface*> ResourceManager::mResourceMap;
std::unordered_map<std::string, SDL_Texture*> ResourceManager::mTextureMap;

ResourceManager::ResourceManager(){
}


ResourceManager::~ResourceManager(){
}
// TODO: YUCK! Fix this common resource consumption error.
//       You should use some data structure (e.g. a Map or unordered_map
//       to first search if this resource has been loaded, and then
//       only call SDL_LoadBMP if that resource does not previously exist.
void ResourceManager::LoadResource(std::string image_filename){
        SDL_Log("New LoadBMP copy of  %s has been loaded\n", image_filename.c_str());
        std::cout << "New LoadBMP copy of " << image_filename << " has been loaded\n"<<std::endl;
        SDL_Surface* newResource = SDL_LoadBMP(image_filename.c_str());
        mResourceMap[image_filename] = newResource;

}

void ResourceManager::LoadTexture(std::string image_filename, SDL_Renderer* renderer){
    SDL_Log("New Texture copy of  %s has been loaded\n", image_filename.c_str());
    std::cout << "New Texture copy of " << image_filename << " has been loaded\n"<<std::endl;
    mTexture = SDL_CreateTextureFromSurface(renderer, mResourceMap[image_filename]);
    mTextureMap[image_filename] = mTexture;

}


SDL_Surface* ResourceManager::GetResource(std::string image_filename){
    auto resourceIter = mResourceMap.find(image_filename);
    if (resourceIter == mResourceMap.end()) {
        ResourceManager::LoadResource(image_filename);
        SDL_Log("Retrieved saved Surface copy of  %s", image_filename.c_str());
        std::cout << "Retrieved saved Surface copy of " << image_filename << " \n"<<std::endl;

        return ResourceManager::mResourceMap[image_filename];
    } else {
        SDL_Log("Retrieved saved Surface copy of  %s", image_filename.c_str());
        std::cout << "Retrieved saved Surface copy of " << image_filename << " from saved Surface\n"<<std::endl;
        return resourceIter->second;
    }
}

SDL_Texture* ResourceManager::GetTexture(std::string image_filename,SDL_Renderer* renderer){
    auto textureIter = mTextureMap.find(image_filename);
    if (textureIter == mTextureMap.end()) {
        ResourceManager::LoadTexture(image_filename, renderer);
        SDL_Log("Retrieved saved texture copy of  %s", image_filename.c_str());
        std::cout << "Retrieved saved texture copy of " << image_filename << " from\n"<<std::endl;

        return ResourceManager::mTextureMap[image_filename];
    } else {
        std::cout << "Retrieved saved Texture copy of " << image_filename << " from saved Texture\n"<<std::endl;
        return textureIter->second;
    }
}




SDL_Surface* ResourceManager::mSpriteSheet = nullptr;
SDL_Texture* ResourceManager::mTexture = nullptr;

