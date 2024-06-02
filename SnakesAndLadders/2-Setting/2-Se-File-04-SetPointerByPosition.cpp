#include "2-Se-File-01-Header.h"

int setPointerByPosition(SettingPointer* pointer, int level)
{
    if (pointer->texture != NULL)
    {
        int startX = 391;
        int startY = 195;

        pointer->rect = {startX, startY, 11, 23};

        if (level == 1) pointer->rect.y = startY;
        if (level == 2) pointer->rect.y = startY + 91 * 1;
        if (level == 3) pointer->rect.y = startY + 91 * 2;

        if (pointer->position == 1) pointer->rect.x = startX;
        if (pointer->position == 2) pointer->rect.x = startX + 73;
        if (pointer->position == 3) pointer->rect.x = startX + 73 + 86;
        if (pointer->position == 4) pointer->rect.x = startX + 73 + 86 + 81;
        if (pointer->position == 5) pointer->rect.x = startX + 73 + 86 + 81 + 79;

        SDL_RenderCopy(SDLPointers::renderer, pointer->texture,NULL, &pointer->rect);

        return 1;
    }
    else return 0;
}
