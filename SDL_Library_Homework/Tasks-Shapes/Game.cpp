#include "Game.h"
#include <iostream>
bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL init success\n";
		
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window != 0) //window init success
		{
			std::cout << "window creation success\n";
			renderer = SDL_CreateRenderer(window, -1, 0);
            if (renderer != 0) //renderer init success
            {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

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
	std::cout << "init success\n";
	running = true;
	return true;
}


void Game::render() {
	SDL_SetRenderDrawColor(renderer, 0xAA, 0xBB, 0xCC, 0xFF); //set background color
	SDL_RenderClear(renderer);

	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh); //get window's width and height

	// Draw Circle using Midpoint Circle Algorithm (right)
	SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0xFF, 0xFF);	
	Shapes::drawCircle(renderer, 3*(ww/4), wh/2, ww/4-20);

	// Draw Circle using Bresenham's Circle Algorithm (left)
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF-20);	
	Shapes::drawCircleB(renderer, ww/4, wh/2, ww/4);	

	// Draw Hexagon by given side in pixels (right)
	Shapes::drawHexagon(renderer, 3*(ww/4), wh/2, 120);
	// Draw Pentagon by given side in pixels (right)
	Shapes::drawPentagon(renderer, ww/4, wh/2, 120);

	//SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_SetRenderDrawColor(renderer, Shapes::rgb[2], Shapes::rgb[0], Shapes::rgb[1],  255);
	
	// Draw Regular Pentagon by given number of sides and radius in pixels (center)

	int & nSides = Shapes::reguarPolygonSides;
	Shapes::drawRegularPolygon(renderer, ww/2, wh/2, nSides, 120);

	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);
	// Draw Ellipse using Midpoint Ellipse Algorithm - input ellipse center coordinates and x and y radius
	Shapes::drawEllipse(renderer, ww/2, wh/2, 220, 135);

	/* Draws  white Rectangle with black border with thickness
	requires position coordinates, width, height and thisckness.
	Can render transparent instead of white. Clipping?
	*/ 
	Shapes::drawRectangleWithBorder(renderer, ww-190, wh-110, 170, 90, 8);

	SDL_RenderPresent(renderer); //prsent the drawings to the renderer
}
void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT: running = false; break;
		case SDL_MOUSEMOTION : {
			//change rectangle colors based on mouse position
			int x, y;
			SDL_GetMouseState(&x, &y);
			int ww, wh;
			SDL_GetWindowSize(window, &ww, &wh);
			Shapes::rgb[0] = (int)(((double)x/ww)*255);
			Shapes::rgb[1] = (int)(((double)y/wh)*255);
			Shapes::rgb[2] = (int)(((((double)x/ww)+((double)y/wh))/2)*255);

		}; break;
		case SDL_KEYDOWN : {
			int & nSides = Shapes::reguarPolygonSides;
			if(event.key.keysym.sym == SDLK_UP){
				(nSides >= 3) ? nSides += 1 : nSides;
			}
			if(event.key.keysym.sym == SDLK_DOWN){
				(nSides > 3) ? nSides -= 1 : nSides;
			}

		}; break;

		default: break;
		}
	}
}
void Game::update() {
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
}
Game::~Game() {
}