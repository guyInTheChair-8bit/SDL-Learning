#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

const int SCREENWIDTH = 1920;
const int SCREENHEIGHT = 1920;
const char* TITLE = "TEST";

int main() {

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL Init FAILED: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREENWIDTH, SCREENHEIGHT, 0);

    if (!window) {
        printf("window creation FAILED: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!renderer) {
        printf("renderer creation FAILED: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    int is_running = 1;
    SDL_Event event;
    
    SDL_Rect rect;
    rect.x = 100;
    rect.y = 200;
    rect.w = 64;
    rect.h = 64;

    while (is_running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) is_running = 0;
        }
        
        //clearing screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        //drawing the rectangle
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    return 0;
}

