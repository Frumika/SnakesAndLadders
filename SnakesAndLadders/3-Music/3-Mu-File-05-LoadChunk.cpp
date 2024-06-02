#include "3-Mu-File-01-Header.h"

void loadChunk(Mix_Chunk* & chunk, const char* file)
{
    if (chunk != NULL) Mix_FreeChunk(chunk);

    chunk = Mix_LoadWAV(file);

    changeChunkVolume(chunk, AppStats::soundVolume);
}
