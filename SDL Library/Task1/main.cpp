#include "Game.h"
#include <iostream>

Game* game = NULL; //create Game class object null pointer
const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 400;

int main( int argc, char *argv[] ){

    game = new Game(); //construct the Game object
    game -> init("My new window", 
                SDL_WINDOWPOS_CENTERED, 
                SDL_WINDOWPOS_CENTERED, 
                WINDOW_WIDTH, WINDOW_HEIGHT,
                SDL_WINDOW_RESIZABLE); //initialize window, renderer and image

    while (game->isRunning()){ //while Close button not pressed
            game->handleEvents(); //listen for Close button event
            game->update(); //updates values
            game->render(); //renders window
    }

    game->clean(); //

    return 0;
}