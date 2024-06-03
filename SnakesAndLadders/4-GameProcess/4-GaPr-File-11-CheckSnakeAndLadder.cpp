#include "4-GaPr-File-01-Header.h"


int checkSnakeAndLadder(Player* player)
{
    // Змеи
    if (player->piece.position == 98 - 1)
    {
        player->piece.rect.x += 70 * 2;
        player->piece.rect.y += 70 * 3;
        player->piece.position = 65 - 1;
        return 1;
    }

    if (player->piece.position == 72 - 1)
    {
        player->piece.rect.x -= 70 * 2;
        player->piece.rect.y += 70 * 5;
        player->piece.position = 27 - 1;
        return 1;
    }

    if (player->piece.position == 60 - 1)
    {
        player->piece.rect.x += 70 * 3;
        player->piece.rect.y += 70 * 4;
        player->piece.position = 17 - 1;
        return 1;
    }

    
    // Лестницы
    if (player->piece.position == 67 - 1)
    {
        player->piece.rect.y -= 70 * 3;
        player->piece.position = 94 - 1;
        return 1;
    }

    if (player->piece.position == 26 - 1)
    {
        player->piece.rect.y -= 70 * 3;
        player->piece.position = 55 - 1;
        return 1;
    }

    if (player->piece.position == 9 - 1)
    {
        player->piece.rect.y -= 70 * 3;
        player->piece.position = 32 - 1;
        return 1;
    }

    return 0;
}
