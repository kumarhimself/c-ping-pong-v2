#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_ttf.h>

#include "game.h"
#include "paddle.h"
#include "player.h"

int game(SDL_Renderer *renderer) {
	bool is_game_running = true;

	const Uint8 *keyboard_state = SDL_GetKeyboardState(NULL);

	SDL_Rect rectangle = {0, 45, 32, 32};

	SDL_Rect player;
	init_paddle(&player, true);
	SDL_Rect opponent;
	init_paddle(&opponent, false);

	while (is_game_running) {
		SDL_Event event;

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

		SDL_RenderClear(renderer);

		draw_paddle(renderer, &player, true);
		draw_paddle(renderer, &opponent, false);

		player_detect_movement(&player, keyboard_state);

		if (SDL_PollEvent(&event) > 0) {
			if (event.type == SDL_QUIT) is_game_running = false;
		}

		SDL_RenderPresent(renderer);
	}

	SDL_SetRenderDrawColor(renderer, 1, 111, 185, 255);

	SDL_RenderDrawRect(renderer, &rectangle);

	return 0;
}
