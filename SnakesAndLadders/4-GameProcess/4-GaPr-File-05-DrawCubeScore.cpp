#include "4-GaPr-File-01-Header.h"


void drawCubeScore(int value)
{
    char text[2];
    
    SDL_Rect textRect = {1103, 202, 17, 20};

    converIntToChar(text, value);
    
    SDL_Texture* textTexture = createTextureFromText(text);

    SDL_RenderCopy(SDLPointers::renderer, textTexture,NULL, &textRect);
}
