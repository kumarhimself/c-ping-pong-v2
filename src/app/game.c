#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <SDL.h>
#include <SDL_ttf.h>

#include "game.h"
#include "window_vars.h"
#include "paddle.h"
#include "player.h"
#include "opponent.h"
#include "ball.h"

// Function Prototype(s)
void draw_mid_line(SDL_Renderer *renderer);
bool hit_side_walls(SDL_Rect *ball);

int game(SDL_Renderer *renderer) {
	bool is_game_running = true;

	while (is_game_running) {
		const Uint8 *keyboard_state = SDL_GetKeyboardState(NULL);

		// Initializing entities
		SDL_Rect player;
		init_paddle(&player, true);
		SDL_Rect opponent;
		init_paddle(&opponent, false);
		SDL_Rect ball;
		init_ball(&ball);
		int x_direction = (time(NULL) % 2) ? 1 : -1;
		int y_direction = (time(NULL) % 2) ? -1 : 1;

		while (1) {
			SDL_Event event;

			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

			SDL_RenderClear(renderer);

			draw_mid_line(renderer);	

			// Draw entities
			draw_paddle(renderer, &player, true);
			draw_paddle(renderer, &opponent, false);
			draw_ball(renderer, &ball);
		
			// Updating entity movement
			player_detect_movement(&player, keyboard_state);
			move_ball(&ball, &x_direction, &y_direction, &player, &opponent);
			move_opponent(&opponent, &ball);
		
			if (hit_side_walls(&ball)) {
				break;
			}

			if (SDL_PollEvent(&event) > 0) {
				if (event.type == SDL_QUIT) {
					is_game_running = false;
					break;
				}
			}

			SDL_RenderPresent(renderer);
		}
	}

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

bool hit_side_walls(SDL_Rect *ball) {
	if ((*ball).x + (*ball).w == WINDOW_WIDTH || (*ball).x == 0) {
		return true;
	}

	return false;
}
