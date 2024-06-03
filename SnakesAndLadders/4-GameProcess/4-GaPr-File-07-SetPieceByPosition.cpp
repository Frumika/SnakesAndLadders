#include "4-GaPr-File-01-Header.h"


void setPieceByPosition(Player* player)
{
    int startX = 21;
    int startY = 646;

    if (player->piece.position < 100)
    {
        for (int i = 0; i < 5; i++)
        {
            if (player->piece.position >= 1 + 20 * i && player->piece.position < 10 + 20 * i)
            {
                player->piece.rect.x += 70;
            }

            if (player->piece.position == 10 + 20 * i || player->piece.position == 20 + 20 * i)
            {
                player->piece.rect.y -= 70;
            }

            if (player->piece.position >= 11 + 20 * i && player->piece.position < 20 + 20 * i)
            {
                player->piece.rect.x -= 70;
            }
        }
    }
}
