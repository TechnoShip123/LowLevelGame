#include <stdio.h>
#include <SDL2/SDL.h>

// Screen dimension constants
const int SCREEN_WIDTH = 856;
const int SCREEN_HEIGHT = 482;

int main(int argc, char* args[]) {
    SDL_Window* window = NULL;

    // The surface that the window holds
    SDL_Surface* screenSurface = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error initializing SDL: %s\n", SDL_GetError()); return EXIT_FAILURE;
    }
    printf("SDL init successful!\n");

    //Create window
    window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if (window == NULL) {
        printf("Failed to create window: %s\n", SDL_GetError()); return EXIT_FAILURE;
    }

    // Get surface, fill with red, and then push the changes by updating the surface.
    screenSurface = SDL_GetWindowSurface( window );
    SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0, 0 ) );

    SDL_UpdateWindowSurface( window );

    // Keep the window open until the user closes it (we will recieve a close event)
    SDL_Event e; bool quit = false; 
    while (quit == false) {
        while (SDL_PollEvent(&e)) { 
            if(e.type == SDL_QUIT) quit = true;
        }
    }

    // Exit tasks
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
