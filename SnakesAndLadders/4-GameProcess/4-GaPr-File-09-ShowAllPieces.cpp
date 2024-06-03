#include "4-GaPr-File-01-Header.h"


void showAllPieces(Player* players)
{
    for (int i = 0; i < AppStats::numOfPlayers; i++)
    {
        SDL_RenderCopy(SDLPointers::renderer, players[i].piece.texture,NULL, &players[i].piece.rect);
    }
}
