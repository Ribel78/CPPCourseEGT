#include "Game.h"
#include <iostream>

Game* game = NULL;
const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 400;

int main( int argc, char *argv[] ){

    game = new Game(); // create
    game -> init("Four Cats", // initialize
                SDL_WINDOWPOS_CENTERED, 
                SDL_WINDOWPOS_CENTERED, 
                WINDOW_WIDTH, WINDOW_HEIGHT,
                SDL_WINDOW_RESIZABLE);
    cout << "----------------------------------------------------\n";
    cout << "Click with Left Mouse Button to show/hide images\n";
    cout << "Click with Right Mouse Button to place the moustache\n";
    cout << "Use Arrow keys to move the moustache\n";
    cout << "----------------------------------------------------\n";
    while (game->isRunning()){ // cycle
            game->handleEvents(); // listen
            game->update(); // update (Game members?)
            game->render(); // draw
    }

    game->clean(); // destroy

    return 0;
}