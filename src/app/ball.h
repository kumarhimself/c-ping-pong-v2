#ifndef BALL_H
#define BALL_H

void init_ball(SDL_Rect *ball);
void draw_ball(SDL_Renderer *renderer, SDL_Rect *ball);
void move_ball(SDL_Rect *ball, int *x_direction, int *y_direction, SDL_Rect *player, SDL_Rect *opponent);

#endif
