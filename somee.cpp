#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char* args[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow("Draw Line", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Set draw color to red
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    // Draw vertical line with width 1 pixel and height 30 pixels
    int x = 400; // X position of the line
    int y = 285; // Y position of the top of the line
    for (int i = 0; i < 30; ++i) {
        SDL_RenderDrawPoint(renderer, x, y + i);
    }

    // Present the renderer
    SDL_RenderPresent(renderer);

    // Wait for a few seconds
    SDL_Delay(5000);

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
