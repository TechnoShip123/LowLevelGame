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

    if (SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer) != 0) {
        cout << "Error initializing window and renderer: " << SDL_GetError() << endl; return EXIT_FAILURE;
    }
    SDL_SetWindowTitle(window, "LowLevelGame");
    
    cout << "Window and renderer init successful.\n";
    #pragma endregion

    // Keep the window open until the user closes it (we will recieve a close event)
    SDL_Event e; bool shouldQuit = false;
    while (shouldQuit == false) {
        #pragma region Event Handling
        while (SDL_PollEvent(&e)) { 
            if (e.type == SDL_QUIT) shouldQuit = true;
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
