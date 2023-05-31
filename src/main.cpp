#include <stdio.h>
#include <SDL2/SDL.h>

int main(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Error initializing SDL: %s\n", SDL_GetError()); return EXIT_FAILURE;
    }

    printf("SDL init successful!\n");

    SDL_Quit();

    return EXIT_SUCCESS;
}
