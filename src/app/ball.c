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

void move_ball(SDL_Rect *ball, int *x_direction, int *y_direction, SDL_Rect *player, SDL_Rect *opponent) {
	// Ball movement
	(*ball).x += (*x_direction) * 1;
	(*ball).y += (*y_direction) * 1;

	// Ceiling/Floor Collisions
	if ((*ball).y == 0 || (*ball).y + (*ball).h == WINDOW_HEIGHT) {
		(*y_direction) = (-1) * (*y_direction);
		return;
	}

	// Side Wall Collisions (Not necessary, will remove later)
	if ((*ball).x + (*ball).w == WINDOW_WIDTH || (*ball).x == 0) {
		(*x_direction) = (-1) * (*x_direction);
		return;
	}

	// Player Collisions
	bool x_player_collision = (*ball).x == (*player).x + (*player).w;
	bool y_player_collision = (*ball).y >= (*player).y && (*ball).y <= (*player).y + (*player).h;

	if (x_player_collision && y_player_collision) {
		(*x_direction) = (-1) * (*x_direction);
		(*y_direction) = (-1) * (*y_direction);
		return;
	}

	// Opponent Collisions
	bool x_opponent_collision = (*ball).x + (*ball).w == (*opponent).x;
	bool y_opponent_collision = (*ball).y >= (*opponent).y && (*ball).y <= (*opponent).y + (*opponent).h;

	if (x_opponent_collision && y_opponent_collision) {
		(*x_direction) = (-1) * (*x_direction);
		(*y_direction) = (-1) * (*y_direction);
		return;
	}
}
