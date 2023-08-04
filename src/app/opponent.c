#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

#include "paddle.h"

void move_opponent(SDL_Rect *opponent, SDL_Rect *ball) {
	bool go_up = (*opponent).y > (*ball).y;

	if ((*opponent).y / 2 != (*ball).y) {	
		move_paddle(opponent, go_up);	
	}	
}
