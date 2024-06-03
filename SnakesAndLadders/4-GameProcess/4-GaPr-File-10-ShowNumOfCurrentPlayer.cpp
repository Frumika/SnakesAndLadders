#include "4-GaPr-File-01-Header.h"


void showNumOfCurrentPlayer(int value)
{
    char text[2];
    
    SDL_Rect textRect = {871, 138, 17, 20};

    converIntToChar(text, value);
    
    SDL_Texture* textTexture = createTextureFromText(text);

    SDL_RenderCopy(SDLPointers::renderer, textTexture,NULL, &textRect);
}