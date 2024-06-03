#include "4-GaPr-File-01-Header.h"


void showNumOfCurrentPlayer(int value, int x, int y)
{
    char text[2];
    
    SDL_Rect textRect = {x, y, 17, 20};

    converIntToChar(text, value);
    
    SDL_Texture* textTexture = createTextureFromText(text);

    SDL_RenderCopy(SDLPointers::renderer, textTexture,NULL, &textRect);
}