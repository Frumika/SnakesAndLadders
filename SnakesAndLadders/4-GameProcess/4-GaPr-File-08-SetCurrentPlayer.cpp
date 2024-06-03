#include "4-GaPr-File-01-Header.h"

void setCurrentPlayer(int& value)
{
    if (value < AppStats::numOfPlayers - 1) value++;
    else value = 0;
}
