#include "Game.h"
#include <iostream>

Game* game = NULL;
const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 400;

int main( int argc, char *argv[] ){

    game = new Game(); // create
    game -> init("Animated Sprites", // initialize
                SDL_WINDOWPOS_CENTERED, 
                SDL_WINDOWPOS_CENTERED, 
                WINDOW_WIDTH, WINDOW_HEIGHT,
                SDL_WINDOW_RESIZABLE);
    cout << "----------------------------------------------------\n";
    cout << "Loop through all rows of the sprite sheet\n";   
    cout << "Click with any Mouse Button to show explosion\n";
    cout << "The bird animation cycles infinitely\n";
    cout << "The explosion - once per click\n";
    cout << "----------------------------------------------------\n";
    while (game->isRunning()){ // cycle
            game->handleEvents(); // listen
            game->update(); // update (Game members?)
            game->render(); // draw
    }

    game->clean(); // destroy

    return 0;
}