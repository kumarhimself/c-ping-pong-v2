#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_ttf.h>

#include "game.h"

int game(SDL_Renderer *renderer) {
	bool is_game_running = true;
	
	SDL_Rect rectangle = {0, 45, 32, 32};

	while (is_game_running) {
		SDL_Event event;

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 1, 111, 185, 255);

		SDL_RenderDrawRect(renderer, &rectangle);

		if (SDL_PollEvent(&event) > 0) {
			if (event.type == SDL_QUIT) is_game_running = false;
		}

		SDL_RenderPresent(renderer);
	}

	SDL_SetRenderDrawColor(renderer, 1, 111, 185, 255);

	SDL_RenderDrawRect(renderer, &rectangle);

	return 0;
}
