#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

#include "window_vars.h"

void init_ball(SDL_Rect *ball) {
	(*ball).w = 15;
	(*ball).h = 15;
	(*ball).x = WINDOW_WIDTH / 2 - (*ball).w / 2;
	(*ball).y = WINDOW_HEIGHT / 2 - (*ball).h / 2;
}

void draw_ball(SDL_Renderer *renderer, SDL_Rect *ball) {
	SDL_SetRenderDrawColor(renderer, 230, 232, 230, 255);

	SDL_RenderFillRect(renderer, ball);
}
