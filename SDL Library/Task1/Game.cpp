#include "Game.h"
#include <iostream>
// Initialize window, renderer, texture
bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) { //init SDL library and checks if succesfull (0 on success)
		std::cout << "SDL library initialization was successful\n";
		
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags); //1. create window object member
		if (window != 0) //check if window init successful and draw on it (0 on fail)
		{
			std::cout << "Window initialization was successful\n";

			renderer = SDL_CreateRenderer(window, -1, 0); // 2. create renderer object member
            if (renderer != 0) //check if renderer init successfull (0 on fail)
            {
                std::cout << "Renderer initialization was successful\n";
					//Set some drawing parameters
                SDL_SetRenderDrawColor(renderer, 125, 220, 125, 255); //current drawing color (green), fills the window.
                	// ADD PICTURE TO WINDOW
					//way to create collection of pixels from bmp image (SDL_LoadBMP returns ptr)
                SDL_Surface* tempSurface = SDL_LoadBMP("assets/Baby.bmp"); //temporary variable
					//transfre the pixels from the surface to the texture
                texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
					//deletes the temporary variable no longer needed
                SDL_FreeSurface(tempSurface);
					//retrieve the basic settings of a texture, including the format, access, width, and height
					//that means it sets the last two given pointer variables with the texture(image)'s widht and height
				SDL_QueryTexture(texture, NULL, NULL, &sourceRectangle.w, &sourceRectangle.h);

					//initialize the coords and dimensions of source and destination SDL_Rect rectangles
					//source rect crops area from texture and stretches to dest rectangle size
					//source rectangle coords relative to texture
				sourceRectangle.x = 69;
				sourceRectangle.y = 103;
				sourceRectangle.w = 55;
				sourceRectangle.h = 55;
					//destination rectangle coords relative to window
                destinationRectangle.x = 0;
                destinationRectangle.y = 0;
				destinationRectangle.w = 110;//2x source size
                destinationRectangle.h = 110;
				
            }
			else {
				std::cout << "renderer init failed\n";
				return false;
			}
		}
		else {
			std::cout << "Window initialization has failed\n";
			return false;
		}
	}
	else {
		std::cout << "SDL library initialization has failed\n";
		return false;
	}
	running = true; //all good
	return true;
}
void Game::render() {
	SDL_RenderClear(renderer); //clears the renderer for new drawing
	
	SDL_RenderCopy(renderer, texture, &sourceRectangle, &destinationRectangle); //draws on renderer with portion of the texture
	
	SDL_RenderPresent(renderer); //displays the drawing of (multiple) SDL_RenderCopy
}
void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) { //listen for events
		switch (event.type) {
			case SDL_QUIT: running = false; break; //if close window button is pressed set running to false
			default: break;
		}
	}
}
void Game::update() {
	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh);
	destinationRectangle.y = (wh - destinationRectangle.h) / 2; // center the image vertically

	if(SDL_GetTicks()%50 == 0){
		destinationRectangle.x += speed; //advance in speed steps
		if((destinationRectangle.x >= (ww - destinationRectangle.w))){
			destinationRectangle.x = ww - destinationRectangle.w; //bring back inside window
			speed *= -1; //flip direction
			speed += speed/abs(speed); // increase speed by one
		}			
		if((destinationRectangle.x <= 0)){
			destinationRectangle.x = 0; //bring back inside window
			speed *= -1; //flip direction
			speed += speed/abs(speed); // increase speed by one
		}
		if (abs(speed) > 11)
			speed /= abs(speed); //set speed to unit but keep the direction
	}
	
}
void Game::clean() {
	std::cout << "Cleaning Game on Close\n";
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
bool Game::isRunning() { //checks running based on handleEvents
	return Game::running;
}
Game::Game() {
	//initialize the main members
	Game::window = NULL;
	Game::renderer = NULL;
	Game::running = true;
	Game::speed = 1;
}
Game::~Game() {
}