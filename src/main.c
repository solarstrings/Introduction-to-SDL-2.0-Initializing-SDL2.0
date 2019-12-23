#include <SDL2/SDL.h>
#include <stdio.h>
#include "initCloseSDL.h"
#include "renderer.h"

int endProgram = 0;

void handleInput()
{
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                endProgram = 1;
            break;
            case SDL_KEYUP:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        endProgram = 1;
                    break;
                    default:break;
                }
            break;
            default:break;
        }
    }
}

void drawBlueScreen()
{
    SDL_SetRenderDrawColor(getRenderer(),0x00,0x00,0xFF,0xFF);
    SDL_RenderClear(getRenderer());
    SDL_RenderPresent(getRenderer());
}

int main(int argc, char *argv[])
{
    initSDL("Johan Forsblom - Introduction to SDL 2.0 - Initialize SDL 2.0");
    drawBlueScreen();
    while(!endProgram)
    {
        handleInput();
    }
    closeDownSDL();
    return 0;
}
