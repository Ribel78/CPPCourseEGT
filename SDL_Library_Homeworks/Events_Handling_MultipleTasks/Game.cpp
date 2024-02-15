#include "Game.h"
#include <iostream>

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL running\n";
		
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window != 0) //window init success
		{
			std::cout << "Window created\n";
			renderer = SDL_CreateRenderer(window, -1, 0);
            if (renderer != 0) //renderer init success
            {
                std::cout << "Renderer created\n";
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				TextureManager::Instance() -> loadTexture("assets/000.png", "BL", renderer);
				TextureManager::Instance() -> loadTexture("assets/001.png", "BR", renderer);
				TextureManager::Instance() -> loadTexture("assets/002.png", "TR", renderer);
				TextureManager::Instance() -> loadTexture("assets/003.png", "TL", renderer);

				TextureManager::Instance() -> loadTexture("assets/moustache.png", "moustache", renderer);
				TextureManager::Instance() -> toggleVisibility("moustache"); //make it visible on init
            }
			else {
				std::cout << "renderer init failed\n";
				return false;
			}
		}
		else {
			std::cout << "window init failed\n";
			return false;
		}
	}
	else {
		std::cout << "SDL init fail\n";
		return false;
	}
	std::cout << "Initialization successful\n";
	running = true;
	return true;
}

// enumerator to handle window quadrants for readability
enum Quadrant {TL = 0, TR = 1, BL = 10, BR = 11, UNDEFINED = 100};

Quadrant mouseDownIn = UNDEFINED; // indicates which quadrant the L or R mouse button was pressed down
Quadrant mouseDownOut = UNDEFINED; // indicates which quadrant the L mouse was released up

// Texture positions for the moustache texture
int texPosX, texPosY = 0;

// texture dimensions;  down-scaling not implemented - must be the size of the image or higher
int w = 100; int h = 60; 

void Game::render() {
	SDL_SetRenderDrawColor(renderer, 242, 154, 207, 255); //set drawing color
	SDL_RenderClear(renderer); // clears the previous content and paints fills the background with color

	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh); //get window's width and height	

	// Show/Hide 4 textures if clicked in their respective quadrant with the Left mouse

	TextureManager::Instance() -> drawTexture("TL", 0, 0, ww/2, wh/2, renderer); //renders only if visible
	TextureManager::Instance() -> drawTexture("TR", ww/2, 0, ww/2, wh/2, renderer); //...
	TextureManager::Instance() -> drawTexture("BL", 0, wh/2, ww/2, wh/2, renderer); //...
	TextureManager::Instance() -> drawTexture("BR", ww/2, wh/2, ww/2, wh/2, renderer); //...

	// Draw a moustache texture with its center on Right mouse click position

	int angle = 0; // texture's rotation angle
	switch(mouseDownIn){ //chek where Right mouse clicked
		case TL : {angle = 350;} break;
		case TR : {angle = 0;} break;
		case BL : {angle = 5;} break;
		case BR : {angle = 45;} break;
		default: break;
	}

	// let's use references to global variables to update this texture position
	int & tPosX = texPosX;
	int & tPosY = texPosY;

	TextureManager::Instance() -> drawTexture(
												"moustache", 
												tPosX, 
												tPosY,
												w, h, renderer, SDL_FLIP_NONE, angle); //...
	
	// Draw horizontal and vertical lines at the center and window borders 
	SDL_SetRenderDrawColor(renderer, 251, 15, 65, 255);	

	for (double i = 0.0; i <= 1.0; i += 0.5){
		SDL_RenderDrawLine(renderer, (ww-i)*i, 0, (ww-i)*i, wh);
		SDL_RenderDrawLine(renderer, 0, (wh-i)*i, ww, (wh-i)*i);	
	}

	SDL_RenderPresent(renderer); //"present" the drawings from the buffer to the renderer
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		int mouseX, mouseY, ww, wh;
		//int button;
		SDL_GetWindowSize(window, &ww, &wh); //get window's width and height
		switch (event.type) {
		case SDL_QUIT: running = false; break; // on close window 

		case SDL_MOUSEBUTTONDOWN: {
				/*Get quadrant*/
				SDL_GetMouseState(&mouseX, &mouseY);

				if(event.button.button == SDL_BUTTON_LEFT || event.button.button == SDL_BUTTON_RIGHT){
					switch(((mouseX > ww/2) + (mouseY>wh/2)*10)){
						case 0 : 	mouseDownIn = TL; break;
						case 1 : 	mouseDownIn = TR; break;
						case 10 : 	mouseDownIn = BL; break;
						case 11 : 	mouseDownIn = BR; break;
						default: break;
					}
				}
			}; break;

		case SDL_MOUSEBUTTONUP: {
			/*Get quadrant on mouse up - to ensure the mouse stayed in the same quadrant*/
			SDL_GetMouseState(&mouseX, &mouseY);// get mouse position

			if(event.button.button == SDL_BUTTON_LEFT){
				switch(((mouseX > ww/2) + (mouseY>wh/2)*10)){
					case 0 :{ 	
						mouseDownOut = TL;
							if (mouseDownIn == mouseDownOut){
								TextureManager::Instance() ->toggleVisibility("TL"); //toggle visibility
							}
						}; break;
					case 1 : {
						mouseDownOut = TR;
							if (mouseDownIn == mouseDownOut){
								TextureManager::Instance() ->toggleVisibility("TR"); //toggle visibility
							}					
						} break;
					case 10 : {
						mouseDownOut = BL;
							if (mouseDownIn == mouseDownOut){
								TextureManager::Instance() ->toggleVisibility("BL"); //toggle visibility
							}					
						} break;
					case 11 : 	{
						mouseDownOut = BR;
							if (mouseDownIn == mouseDownOut){
								TextureManager::Instance() ->toggleVisibility("BR"); //toggle visibility
							}				
						} break;
					default: break;
				}
			}
			if(event.button.button == SDL_BUTTON_RIGHT){
				// update global variables using references
				int & tPosX = texPosX; int & tPosY = texPosY;
				tPosX = mouseX-w/2;
				tPosY = mouseY-h/2;
			}
		}; break;
		case SDL_KEYDOWN : {
			// update global variables using references
			int & tPosX = texPosX; int & tPosY = texPosY;
			if(event.key.keysym.sym == SDLK_UP)
				tPosY -= 5;
			if(event.key.keysym.sym == SDLK_DOWN)
				tPosY += 5;
			if(event.key.keysym.sym == SDLK_LEFT)
				tPosX -= 5;
			if(event.key.keysym.sym == SDLK_RIGHT)
				tPosX += 5;
		} break;
		default: break;
		}
	}
}
void Game::update() {
	// std::cout << "Ticks" << SDL_GetTicks()<< "\n";
	// std::cout << "Ticks / 100 " << int((SDL_GetTicks()/100)) << "\n";
	// std::cout << "(Ticks / 100 )% 5 " << int(((SDL_GetTicks()/100)%5)) << "\n\n";

	currentFrame = int(((SDL_GetTicks()/100) % 5)); //animate sprites %x x frames per row; /y controls the speed
}
void Game::clean() {
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
bool Game::isRunning() {
	return Game::running;
}
Game::Game() {
	Game::window = NULL;
	Game::renderer = NULL;
	Game::running = true;
	Game::currentFrame = 0; //frames start form 0
	Game::currentRow = 1; //rows start from 1
}
Game::~Game() {
}