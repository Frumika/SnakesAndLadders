#include "4-GaPr-File-01-Header.h"


SDL_Texture* createTextureFromText(char* text)
{
    SDL_Surface* textSurface = TTF_RenderText_Blended(SDLPointers::font, text, AppStats::textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(SDLPointers::renderer, textSurface);

    
    SDL_SetTextureBlendMode(textTexture, SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(textTexture, 255);
    
    SDL_FreeSurface(textSurface);

    return textTexture;
}
