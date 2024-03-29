//TextureManager.h
#pragma once
#include "Game.h"
#include <string>
#include <map>

class TextureManager {
public:
	bool loadTexture(const char* fileName, std::string id, SDL_Renderer* ren); 

	void drawTexture(std::string id,
		int x, int y,
		int width, int height,
		int t_width, int t_height,
		SDL_Renderer* ren,
		SDL_RendererFlip flip = SDL_FLIP_NONE,
		int rotation = 0);

	void drawOneFrameFromTexture(std::string id,
		int x, int y,
		int width, int height,
		int t_width, int t_height,
		int currentRow, int currentFrame,
		SDL_Renderer* ren,
		SDL_RendererFlip flip = SDL_FLIP_NONE);
    
	void toggleVisibility(std::string id);

    static TextureManager* Instance();

private:
	std::map<std::string, SDL_Texture*> textureMap; //map to store the loaded textures with loadTexture
	std::map<std::string, bool> display; //map to store instruction for displaying the loaded textures
	TextureManager() {}
	static TextureManager* instance;
};