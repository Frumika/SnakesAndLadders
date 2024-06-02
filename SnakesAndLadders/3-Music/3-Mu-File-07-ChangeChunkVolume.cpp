#include "3-Mu-File-01-Header.h"


/*
 * Функция changeChunkVolume устанавливает громкость конкретного звука
 *
 * Функция принимает:
 * 1. value - значение громкости звука в процентах (0.00) от максимума.
 *
 * Функция возвращает:
 * 1. 1 - Если громкость звука изменена.
 * 2. 0 - Если громкость звука изменить не удалось.
 */
int changeChunkVolume(Mix_Chunk* chunk, double value)
{
    if (chunk != NULL)
    {
        Mix_VolumeChunk(chunk, int(MIX_MAX_VOLUME * value));
        return 1;
    }

    return 0;
}
