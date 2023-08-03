#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_ttf.h>

#include "app/window.h"

int main(int argc, char *argv[]) {
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	// Initialize window and renderer
	int error = init(&window, &renderer);		
	if (error < 0) return error;

	// Update and draw to the window
	update(&renderer);

	TTF_Quit();
	SDL_Quit();

	return 0;
}
