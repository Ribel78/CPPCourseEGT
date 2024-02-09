#include <SDL2/SDL.h>
using namespace std;

class Game {
public:
    Game();
    ~Game();
    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
    void render();
    void update();
    void handleEvents();
    void clean();
    bool isRunning( );

private:
    //declare main members
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    bool running;
    //declare elements for drawing
    SDL_Texture* texture; //get pixels (from image)
    SDL_Rect sourceRectangle; //determine initial dimensions of the image
    SDL_Rect destinationRectangle; //stretches the image to this rectangle
    // some animation parameters
    int speed; //speed in pixels
};