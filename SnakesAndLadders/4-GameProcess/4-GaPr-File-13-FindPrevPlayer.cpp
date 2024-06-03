#include "4-GaPr-File-01-Header.h"

Player findPrevPlayer(Player* players, Player* curPlayer)
{
    if (curPlayer->id != 1) return players[curPlayer->id - 2];
    return players[AppStats::numOfPlayers - 1];
}
