#include "TextureManager.h"
#include <iostream>
using namespace std;

/*
Loads texture from image file using SDL_image library
fileName - path to the image file
id - name of the created texture
ren - pointer to the renderer 
*/
bool TextureManager::loadTexture(const char* fileName, std::string id, SDL_Renderer* ren){
    SDL_Surface* tempSurface = IMG_Load(fileName);

    if(tempSurface == 0){
        cout << "tempSurface not created!" << endl;
        return false;
    }

    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface); //create texture
    SDL_FreeSurface(tempSurface); //delete surface

    if (tex != 0){
        textureMap[id] = tex; //add the created texture in the textureMap map
        display[id] = 0; //set display of the texture initially to hidden
        return true;
    }

    return false;
}
/*
Draws the texture in the renderer
Uses all texture pixels but allows rescaling via width and height
id - the name of the texture
x, y - coordinates of the texture in the window
width, height - dimensions of the destination texture
ren - renderer
flip - flags to orient the texture (SDL_FLIP_NONE, SDL_FLIP_VERTICAL, SDL_FLIP_HORIZONTAL)
*/
void TextureManager::drawTexture(std::string id, int x, int y, 
                int width, int height, 
                SDL_Renderer* ren, 
                SDL_RendererFlip flip, int rotation){
    if(display[id]){ //check if texture is hidden
        SDL_Rect srcRect;
        SDL_Rect destRect;
        srcRect.x = srcRect.y = 0;
        srcRect.w = destRect.w = width;
        srcRect.h = destRect.h = height;
        destRect.x = x;
        destRect.y = y;

        SDL_RenderCopyEx(ren, textureMap[id], &srcRect, &destRect, rotation, 0, flip); //paint on renderer
    } else {return;}
}
/*
Splits texture in equal sized rectangles(frames)
Picks a portion of the texture (cropping) useful for sprite animation
x,y, width, height
currentRow - current row of frames - strats from 1
currentFrame - current column of frames - starts from 0
ren - renderer
flip - flags to orient the texture (SDL_FLIP_NONE, SDL_FLIP_VERTICAL, SDL_FLIP_HORIZONTAL)
*/
void TextureManager::drawOneFrameFromTexture(std::string id,
                int x, int y,
                int width, int height,
                int currentRow, int currentFrame,
                SDL_Renderer* ren,
                SDL_RendererFlip flip){
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = width* currentFrame;
    srcRect.y = height*(currentRow -1);
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(ren, textureMap[id], &srcRect, &destRect, 0, 0, flip); //paint on renderer

}

/*
Switch for texture's visibility
id - the name of the texture
checks the current state and replaces it with the opposite
There is probably a clever way to do this.
*/
void TextureManager::toggleVisibility(std::string id){

    bool state = display[id];

    if(state) state = false;
    else state = true;

    display[id] = state;

}

//static Instance function - returns a pointer to new TextureManager object
TextureManager* TextureManager::Instance(){
    if (instance == 0){
        instance = new TextureManager();
        return instance;
    }
    return instance;
}
// initialize the instance of the TextureManager - check static TextureManager* Instance() in the header
TextureManager* TextureManager::instance = 0;