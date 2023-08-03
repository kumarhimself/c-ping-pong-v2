#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_ttf.h>

#include "game.h"
#include "window_vars.h"
#include "paddle.h"
#include "player.h"
#include "ball.h"

// Function Prototype(s)
void draw_mid_line(SDL_Renderer *renderer);

int game(SDL_Renderer *renderer) {
	bool is_game_running = true;

	const Uint8 *keyboard_state = SDL_GetKeyboardState(NULL);

	SDL_Rect player;
	init_paddle(&player, true);
	SDL_Rect opponent;
	init_paddle(&opponent, false);
	SDL_Rect ball;
	init_ball(&ball);

	while (is_game_running) {
		SDL_Event event;

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

		SDL_RenderClear(renderer);

		draw_mid_line(renderer);	

		draw_paddle(renderer, &player, true);
		draw_paddle(renderer, &opponent, false);
		draw_ball(renderer, &ball);

		player_detect_movement(&player, keyboard_state);

		if (SDL_PollEvent(&event) > 0) {
			if (event.type == SDL_QUIT) is_game_running = false;
		}

		SDL_RenderPresent(renderer);
	}

	SDL_SetRenderDrawColor(renderer, 1, 111, 185, 255);

	return 0;
}

void draw_mid_line(SDL_Renderer *renderer) {
	SDL_Rect line;
	line.w = 2;
	line.h = 10;
	line.x = WINDOW_WIDTH / 2 - line.w / 2;

	for (line.y = 10; line.y < WINDOW_HEIGHT; line.y += 30) {
		SDL_SetRenderDrawColor(renderer, 253, 202, 64, 255);

		SDL_RenderFillRect(renderer, &line);
	}
}
