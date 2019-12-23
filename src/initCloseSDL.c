#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include "initCloseSDL.h"
#include "renderer.h"

void initSDL(char *windowCaption)
{
    // try to initialize SDL Video
    if (SDL_Init(SDL_INIT_VIDEO)<0){
        fprintf(stderr,"Could not initialize SDL! SDL Error: %s",SDL_GetError());
        exit(1);
    }
    // try to initialize SDL Image
    if( !(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        SDL_Quit();
        fprintf(stderr,"Could not initialize SDL Image! SDL Image Error: %s",IMG_GetError());
        exit(1);
    }
    // if all went ok, initialize the renderer
    initRenderer(windowCaption);
}
void closeDownSDL()
{
    closeRenderer();
    IMG_Quit();
    SDL_Quit();
}

