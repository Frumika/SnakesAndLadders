#include "5-Bo-File-01-Header.h"


void createBonuses(Bonus* bonuses)
{
    int position[] = {14, 39, 57, 70, 80, 88};

    for (int i = 0; i < 6; i++)
    {
        bonuses[i].position = position[i];
        
        if (AppStats::gameMode == 1) bonuses[i].id = getRandomValue(1, 3);
        if (AppStats::gameMode == 2) bonuses[i].id = getRandomValue(1, 6);
        if (AppStats::gameMode == 3) bonuses[i].id = getRandomValue(4, 6);

        // Доп. Куб
        if (bonuses[i].id == 1)
        {
            bonuses[i].count = 1;
            bonuses[i].status = false;
            bonuses[i].rect = {861, 240, 43, 43};
            bonuses[i].texture = createTexture("cube.png");
        }

        // Защита от змей
        if (bonuses[i].id == 2)
        {
            bonuses[i].count = 5;
            bonuses[i].status = false;
            bonuses[i].rect = {912, 240, 43, 43};
            bonuses[i].texture = createTexture("Guard.png");
        }

        // Вдохновение
        if (bonuses[i].id == 3)
        {
            bonuses[i].count = 10;
            bonuses[i].status = false;
            bonuses[i].rect = {963, 240, 43, 43};
            bonuses[i].texture = createTexture("mana.png");
        }

        // Капкан
        if (bonuses[i].id == 4)
        {
            bonuses[i].count = 1;
            bonuses[i].status = false;
            bonuses[i].rect = {1014, 240, 43, 43};
            bonuses[i].texture = createTexture("sword.png");
        }

        // Потерянный путь
        if (bonuses[i].id == 5)
        {
            bonuses[i].count = 1;
            bonuses[i].status = false;
            bonuses[i].rect = {1065, 240, 43, 43};
            bonuses[i].texture = createTexture("question.png");
        }

        // На дно
        if (bonuses[i].id == 6)
        {
            bonuses[i].count = 1;
            bonuses[i].status = false;
            bonuses[i].rect = {1116, 240, 43, 43};
            bonuses[i].texture = createTexture("eye.png");
        }
    }
}
