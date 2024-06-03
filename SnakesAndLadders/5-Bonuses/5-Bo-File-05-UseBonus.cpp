#include "5-Bo-File-01-Header.h"


void useBonus(Bonus* bonus)
{
    if (bonus->status != false)
    {
        bonus->count -= 1;

        if (bonus->count <= 0) bonus->status = false;
    }
}
