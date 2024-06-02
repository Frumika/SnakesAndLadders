#include "3-Mu-File-01-Header.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int playChunk(Mix_Chunk* chunk)
{
    if (chunk != NULL)
    {
        Mix_PlayChannel(-1, chunk, 0);
        return 1;
    }

    return 0;
}
