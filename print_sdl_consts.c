#include <stdio.h>
#include <SDL2/SDL.h>

int main() {
    printf("SDL_INIT_VIDEO: %u\n", SDL_INIT_VIDEO);
    printf("SDL_WINDOWPOS_UNDEFINED: %d\n", SDL_WINDOWPOS_UNDEFINED);
    printf("SDL_PIXELFORMAT_ARGB8888: %u\n", SDL_PIXELFORMAT_ARGB8888);
    printf("SDL_TEXTUREACCESS_STREAMING: %d\n", SDL_TEXTUREACCESS_STREAMING);
    return 0;
}
