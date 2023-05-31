#include <iostream>
#include <SDL2/SDL.h>

using std::printf;
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
        printf("Error initializing SDL: %s\n", SDL_GetError()); return EXIT_FAILURE;
    }
    printf("SDL init successful.\n");

    if (SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer) != 0) {
        printf("Error initializing window and renderer: %s\n", SDL_GetError()); return EXIT_FAILURE;
    }
    SDL_SetWindowTitle(window, "LowLevelGame");
    printf("Window and renderer init successful.\n");
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
        SDL_SetRenderDrawColor(renderer, 0xFF, 0, 0, 0xFF);
        SDL_RenderClear(renderer);

        // Draw
        SDL_RenderPresent(renderer);
    }

    // Exit tasks
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
