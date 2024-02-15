#include "Game.h"
#include <iostream>

int Game::globalFrame = 0;
int Game::offsetGlobalFrame = -1;
const double PI = 3.14159265359;
int mouseX, mouseY, ww, wh; // mouse position and windows dimensions

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

				//load sprite sheet textures
				TextureManager::Instance() -> loadTexture("assets/303x303.png", "explosion", renderer);
				TextureManager::Instance() -> loadTexture("assets/460x460.png", "bird", renderer);
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

void Game::render() {
	SDL_SetRenderDrawColor(renderer, 95, 182, 218, 255); //set drawing color
	SDL_RenderClear(renderer); // clears the previous content and paints fills the background with color

	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh); //get window's width and height	

	int sFrame = globalFrame % 3; // cycle frame number (in a row) - 3 is number of frames per row
	int sRowBird = ( ( globalFrame % 6 ) / 3 ) + 1; // cycle row's number - 6 is total number of frames 3 number of frames per row


	// make a cycle per 25 globalFrame(s) and control the position and size of the bird
	int birdWidth = 350, birdHeight = 350; // desired bird size
	int bw, bh; // variable bird size
	int radius = 150; // radius in pixels to rotate around
	int sizeFactor = (int)( round ( radius * sin( ( (double)globalFrame / 25.00 ) * 2 * PI ) ) );	
	bw = birdWidth + sizeFactor;
	bh = birdHeight + sizeFactor;
	int posX = (int)( round ( radius * cos( ( (double)globalFrame /25.00 ) * 2 * PI ) ) ) + ( ww / 2 - bw / 2 );
	int posY = (wh - bh)/2;
	TextureManager::Instance() -> drawOneFrameFromTexture("bird", posX, posY, 460, 460, bw, bh, sRowBird, sFrame, renderer);

	// Explosion texture animates on mouse button up and cycles only once per click
	if (offsetGlobalFrame != -1){
		if ( globalFrame - offsetGlobalFrame >= 0 && globalFrame - offsetGlobalFrame < 10){
			int sFrame = (globalFrame - offsetGlobalFrame) % 3; // cycle frame number (in a row) - 3 is number of frames per row
			int sRowExplosion = ( ( (globalFrame - offsetGlobalFrame) % 9 ) / 3 ) + 1; //..same for the explosion	
			TextureManager::Instance() -> drawOneFrameFromTexture(
				"explosion" ,mouseX - 303/2 ,mouseY - 303/2 ,
				303 ,303 ,
				303 ,303 ,
				sRowExplosion ,sFrame ,renderer);
		} else {
			offsetGlobalFrame = -1;
		}
	}

	SDL_RenderPresent(renderer); //"present" the drawings from the buffer to the renderer
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT: running = false; break; // on close window 
		case SDL_MOUSEBUTTONUP: {
			SDL_GetMouseState(&mouseX, &mouseY);// get mouse position
			if (offsetGlobalFrame == -1){
				offsetGlobalFrame = globalFrame;
			}
		}; break;
		default: break;
		}
	}
}

void Game::update() {
	globalFrame = int((SDL_GetTicks()/150));
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