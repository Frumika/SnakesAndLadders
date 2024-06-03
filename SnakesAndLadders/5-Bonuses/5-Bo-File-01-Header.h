#pragma once

#include "../0-Common/0-Co-File-01-Header.h"

void createBonuses(Bonus* bonuses);

bool findBonus(Player* currentPlayer, Bonus* bonuses);

void drawPlayerBonuses(Player* curPlayer);

void useBonus(Bonus* bonus);