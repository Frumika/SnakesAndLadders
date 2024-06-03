#include "5-Bo-File-01-Header.h"


void drawPlayerBonuses(Player* curPlayer)
{
    for (int i = 0; i < 6; i++)
    {
        if (curPlayer->bonuses[i].status != false)
        {
            SDL_RenderCopy(SDLPointers::renderer, curPlayer->bonuses[i].texture,NULL, &curPlayer->bonuses[i].rect);
        }
    }
}
