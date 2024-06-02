#include "3-Mu-File-01-Header.h"


/*
 * Функция changeMusicVolume устанавливает громкость фоновой музыки
 *
 * Функция принимает:
 * 1. value - значение громкости музыки в процентах (0.00) от максимума.
 *
 * Функция возвращает:
 * 1. 1 - Если громкость музыки изменена.
 * 2. 0 - Если громкость музыки изменить не удалось.
 */
int changeMusicVolume(double value)
{
    if (SDLPointers::music != NULL)
    {
        Mix_VolumeMusic(int(MIX_MAX_VOLUME * value));
        return 1;
    }

    return 0;
}
