#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

#include "player.h"
#include "paddle.h"

void player_detect_movement(SDL_Rect *player, const Uint8 *keyboard_state) {
	if (keyboard_state[SDL_SCANCODE_W] == 1) move_paddle(player, true);
	if (keyboard_state[SDL_SCANCODE_S] == 1) move_paddle(player, false);
}
