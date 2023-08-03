#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_ttf.h>

#include "paddle.h"
#include "window_vars.h"

void init_paddle(SDL_Rect *paddle, bool is_player) {	
	(*paddle).w = 20;
	(*paddle).h = 100;
	(*paddle).y = WINDOW_HEIGHT / 2 - (*paddle).h / 2;
	
	if (is_player) {
		(*paddle).x = 5;
	} else {
		(*paddle).x = WINDOW_WIDTH - (*paddle).w - 5;
	}
}

void draw_paddle(SDL_Renderer *renderer, SDL_Rect *paddle, bool is_player) {
	if (is_player) {	
		SDL_SetRenderDrawColor(renderer, 0, 73, 245, 255);
	} else {	
		SDL_SetRenderDrawColor(renderer, 233, 41, 53, 255);
	}

	SDL_RenderFillRect(renderer, paddle);
}
