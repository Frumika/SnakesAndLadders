#include "3-Mu-File-01-Header.h"


/*
 * 
 */
int playMusic()
{
    if (SDLPointers::music != NULL)
    {
        changeMusicVolume(AppStats::musicVolume);
        Mix_PlayMusic(SDLPointers::music, -1);
        return 1;
    }

    return 0;
}
