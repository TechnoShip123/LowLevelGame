#include <iostream>
#include <SDL2/SDL.h>

using std::cout;
using std::endl;
using std::string;

// Screen dimension constants
const int SCREEN_WIDTH = 856;
const int SCREEN_HEIGHT = 482;

// Window and Renderer
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int main(int argc, char* args[]) {
    #pragma region Initialize SDL, window, renderer, etc.
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        cout << "Error initializing SDL: " << SDL_GetError() << endl; return EXIT_FAILURE;
    }
    cout << "SDL init successful.\n";

    // Create window
    window = SDL_CreateWindow("LowLevelGame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (window == NULL) { 
        cout << "Error creating window: " << SDL_GetError() << endl; return EXIT_FAILURE; 
    }
    SDL_SetWindowTitle(window, "LowLevelGame");

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) { 
        cout << "Error creating renderer: " << SDL_GetError() << endl; return EXIT_FAILURE; 
    }
    
    cout << "Window and renderer init successful.\n";
    #pragma endregion

    // Keep the window open until the user closes it (we will recieve a close event)
    SDL_Event e; bool shouldQuit = false;
    while (shouldQuit == false) {
        #pragma region Event Handling
        while (SDL_PollEvent(&e)) {
            // Quit Handling
            if (e.type == SDL_QUIT) 
                shouldQuit = true;
            // Keyboard Input
            if (e.type == SDL_KEYDOWN) { 
                SDL_Keycode key = e.key.keysym.sym;
                if (key == SDLK_UP || key == SDLK_w) {
                    cout << "UP" << endl;
                } else if (key == SDLK_DOWN || key == SDLK_s) {
                    cout << "DOWN" << endl;
                } else if (key == SDLK_LEFT || key == SDLK_a) {
                    cout << "LEFT" << endl;
                } else if (key == SDLK_RIGHT || key == SDLK_d) {
                    cout << "RIGHT" << endl;
                }
            }
        }
        #pragma endregion

        // TODO: Move game updates to their own Update() function?
        // RENDERING STUFF
        SDL_SetRenderDrawColor(renderer, 0xFF, 0, 0, 0xFF);
        SDL_RenderClear(renderer);

        // Draw
        SDL_RenderPresent(renderer);
    }

    // TODO: Move exit tasks to their own Quit() function?
    cout << "Exiting..." << endl;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit(); return EXIT_SUCCESS;
}
