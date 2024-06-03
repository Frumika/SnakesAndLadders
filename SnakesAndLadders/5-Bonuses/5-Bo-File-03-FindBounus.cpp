#include "5-Bo-File-01-Header.h"


bool findBonus(Player* currentPlayer, Bonus* bonuses)
{
    for (int i = 0; i < 6; i++)
    {
        if (currentPlayer->piece.position == bonuses[i].position - 1)
        {
            if (bonuses[i].id == 1)
            {
                currentPlayer->bonuses[0] = bonuses[i];
                currentPlayer->bonuses[0].status = true;
            }

            if (bonuses[i].id == 2)
            {
                currentPlayer->bonuses[1] = bonuses[i];
                currentPlayer->bonuses[1].status = true;
            }

            if (bonuses[i].id == 3)
            {
                currentPlayer->bonuses[2] = bonuses[i];
                currentPlayer->bonuses[2].status = true;
            }

            if (bonuses[i].id == 4)
            {
                currentPlayer->bonuses[3] = bonuses[i];
                currentPlayer->bonuses[3].status = true;
            }

            if (bonuses[i].id == 5)
            {
                currentPlayer->bonuses[4] = bonuses[i];
                currentPlayer->bonuses[4].status = true;
            }

            if (bonuses[i].id == 6)
            {
                currentPlayer->bonuses[5] = bonuses[i];
                currentPlayer->bonuses[5].status = true;
            }
            
            return true;
        }
    }

    return false;
}
