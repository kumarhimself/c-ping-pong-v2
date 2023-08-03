#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_ttf.h>

#include "window.h"
#include "window_vars.h"
#include "game.h"

int init(SDL_Window **window, SDL_Renderer **renderer) {
	// Initialize SDL2
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Failed to initialize the SDL2 library\n");
		return -1;
	}

	if (TTF_Init() < 0) {
		printf("Failed to initialize TTF library\n");
		return -1;
	}

	// Initializing window
	Uint32 flags = SDL_WINDOW_SHOWN;
	*window = SDL_CreateWindow("2D Ping Pong",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			flags);

	if (!(*window)) {
		printf("Failed to initialize window\n");
		return -1;
	}

	*renderer = SDL_CreateRenderer(*window, -1, 0);

	if (!(*renderer)) {
		printf("Failed to initialize renderer\n");
		printf("%s\n", SDL_GetError());
		return -1;
	}

	return 0;
}

void update(SDL_Renderer **renderer) {
	game(*renderer);
}
