#include "4-GaPr-File-01-Header.h"

bool checkPosition(Player* players)
{
    for (int i = 0; i < AppStats::numOfPlayers; i++)
    {
        if (players[i].piece.position >= 99) return false;
    }
    return true;
}
