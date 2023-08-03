#ifndef PADDLE_H
#define PADDLE_H

void init_paddle(SDL_Rect *paddle, bool is_player);
void draw_paddle(SDL_Renderer *renderer, SDL_Rect *paddle, bool is_player);
void move_paddle(SDL_Rect *paddle, bool up);

#endif
