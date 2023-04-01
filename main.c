#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define FONT_DIR "fonts/"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* texture = NULL;
SDL_Rect rect;

TTF_Font* font = NULL;

void init() {
    SDL_Init(SDL_INIT_VIDEO);

    TTF_Init();

    window = SDL_CreateWindow("Hangman Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    font = TTF_OpenFont(FONT_DIR "arial.ttf", 24);
    if (font == NULL) {
        fprintf(stderr, "Error loading font: %s\n", TTF_GetError());
        exit(1);
    }
}

void render_text(char* text, int x, int y) {
    SDL_Color color = { 255, 255, 255, 255 };

    SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
    if (surface == NULL) {
        fprintf(stderr, "Error rendering text: %s\n", TTF_GetError());
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL) {
        fprintf(stderr, "Error creating texture from surface: %s\n", SDL_GetError());
        SDL_FreeSurface(surface);
        return;
    }

    rect.x = x;
    rect.y = y;
    rect.w = surface->w;
    rect.h = surface->h;

    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

void cleanup() {
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_Quit();
    SDL_Quit();
}

int main(int argc, char** argv) {
    init();

    while (1) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                cleanup();
                return 0;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        render_text("Hello, world!", 100, 100);

        SDL_RenderPresent(renderer);
    }

    return 0;
}
