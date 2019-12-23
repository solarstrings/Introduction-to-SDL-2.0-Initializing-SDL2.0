#ifndef __RENDERER_H_
#define __RENDERER_H_
#include <SDL2/SDL.h>

#define WINDOW_WIDTH    1280
#define WINDOW_HEIGHT   720

void initRenderer(char *windowCaption);
SDL_Renderer *getRenderer();
SDL_Window *getWindow();
void closeRenderer();

#endif // __RENDERER_H_
