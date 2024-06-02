#include "1-Sc-File-01-Header.h"


void runSettingScreen()
{
    SDL_Texture* settingBackground = createTexture("SettingBackground.png");
    SDL_Rect rect = {0, 0, ScreenCharacter::SCREEN_WIDTH, ScreenCharacter::SCREEN_HEIGHT};

    SDL_Texture* description = createTexture("MainDescription.png");
    SDL_Rect d_rect = {746, 181, 372, 265};
    SDL_Event event;

    SettingPointer barPointer_1;
    SettingPointer barPointer_2;
    SettingPointer barPointer_3;

    barPointer_1.texture = createTexture("Pointer.png");
    barPointer_2.texture = createTexture("Pointer.png");
    barPointer_3.texture = createTexture("Pointer.png");

    barPointer_1.position = int((AppStats::musicVolume * 100) / 25) + 1;
    barPointer_2.position = int((AppStats::soundVolume * 100) / 25) + 1;
    barPointer_3.position = (AppStats::gameMode * AppStats::gameMode) - ((AppStats::gameMode - 1) * (AppStats::gameMode
        - 1));

    SDL_RenderCopy(SDLPointers::renderer, settingBackground,NULL, &rect);
    SDL_RenderCopy(SDLPointers::renderer, description,NULL, &d_rect);

    setPointerByPosition(&barPointer_1, 1);
    setPointerByPosition(&barPointer_2, 2);
    setPointerByPosition(&barPointer_3, 3);

    SDL_RenderPresent(SDLPointers::renderer);

    bool quit = false;
    do
    {
        SDL_PollEvent(&event);

        if (event.type == SDL_QUIT)
        {
            quit = true;
            AppStats::exit = true;
        } // Закрыть всё приложение

        if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
        {
            if (event.button.x >= 510 && event.button.x <= 766 && event.button.y >= 492 && event.button.y <= 538)
            {
                playChunk(SDLPointers::click);
                quit = true;
            } // Завершение работы этого меню

            if (event.button.x >= 373 && event.button.x <= 741 && event.button.y >= 180 && event.button.y <= 264)
            {
                if (event.button.x >= 391 && event.button.x <= 401 && event.button.y >= 216 && event.button.y <= 240)
                {
                    if (barPointer_1.position != 1)
                    {
                        barPointer_1.position = 1;

                        AppStats::musicVolume = 0;
                        changeMusicVolume(AppStats::musicVolume);

                        SDL_RenderCopy(SDLPointers::renderer, settingBackground,NULL, &rect);
                        setPointerByPosition(&barPointer_2, 2);
                        setPointerByPosition(&barPointer_3, 3);

                        setPointerByPosition(&barPointer_1, 1);

                        playChunk(SDLPointers::click);

                        SDL_RenderPresent(SDLPointers::renderer);
                    }
                } // 0%

                if (event.button.x >= 464 && event.button.x <= 474 && event.button.y >= 216 && event.button.y <= 240)
                {
                    if (barPointer_1.position != 2)
                    {
                        barPointer_1.position = 2;

                        AppStats::musicVolume = 0.25;
                        changeMusicVolume(AppStats::musicVolume);

                        SDL_RenderCopy(SDLPointers::renderer, settingBackground,NULL, &rect);
                        setPointerByPosition(&barPointer_2, 2);
                        setPointerByPosition(&barPointer_3, 3);

                        setPointerByPosition(&barPointer_1, 1);

                        playChunk(SDLPointers::click);

                        SDL_RenderPresent(SDLPointers::renderer);
                    }
                } // 25%

                if (event.button.x >= 550 && event.button.x <= 560 && event.button.y >= 216 && event.button.y <= 240)
                {
                    if (barPointer_1.position != 3)
                    {
                        barPointer_1.position = 3;

                        AppStats::musicVolume = 0.5;
                        changeMusicVolume(AppStats::musicVolume);

                        SDL_RenderCopy(SDLPointers::renderer, settingBackground,NULL, &rect);
                        setPointerByPosition(&barPointer_2, 2);
                        setPointerByPosition(&barPointer_3, 3);

                        setPointerByPosition(&barPointer_1, 1);

                        playChunk(SDLPointers::click);

                        SDL_RenderPresent(SDLPointers::renderer);
                    }
                } // 50%

                if (event.button.x >= 631 && event.button.x <= 641 && event.button.y >= 216 && event.button.y <= 240)
                {
                    if (barPointer_1.position != 4)
                    {
                        barPointer_1.position = 4;

                        AppStats::musicVolume = 0.75;
                        changeMusicVolume(AppStats::musicVolume);

                        SDL_RenderCopy(SDLPointers::renderer, settingBackground,NULL, &rect);
                        setPointerByPosition(&barPointer_2, 2);
                        setPointerByPosition(&barPointer_3, 3);

                        setPointerByPosition(&barPointer_1, 1);

                        playChunk(SDLPointers::click);

                        SDL_RenderPresent(SDLPointers::renderer);
                    }
                } // 75%

                if (event.button.x >= 710 && event.button.x <= 720 && event.button.y >= 216 && event.button.y <= 240)
                {
                    if (barPointer_1.position != 5)
                    {
                        barPointer_1.position = 5;

                        AppStats::musicVolume = 1;
                        changeMusicVolume(AppStats::musicVolume);

                        SDL_RenderCopy(SDLPointers::renderer, settingBackground,NULL, &rect);
                        setPointerByPosition(&barPointer_2, 2);
                        setPointerByPosition(&barPointer_3, 3);

                        setPointerByPosition(&barPointer_1, 1);

                        playChunk(SDLPointers::click);

                        SDL_RenderPresent(SDLPointers::renderer);
                    }
                } // 100%
            } // Область регулировки громкости музыки


            if (event.button.x >= 373 && event.button.x <= 741 && event.button.y >= 268 && event.button.y <= 355)
            {
                if (event.button.x >= 391 && event.button.x <= 401 && event.button.y >= 216 + 91 && event.button.y <=
                    240 + 91)
                {
                    if (barPointer_2.position != 1)
                    {
                        barPointer_2.position = 1;

                        AppStats::soundVolume = 0;
                        changeChunkVolume(SDLPointers::click, AppStats::soundVolume);

                        SDL_RenderCopy(SDLPointers::renderer, settingBackground,NULL, &rect);
                        setPointerByPosition(&barPointer_1, 1);
                        setPointerByPosition(&barPointer_3, 3);

                        setPointerByPosition(&barPointer_2, 2);

                        playChunk(SDLPointers::click);

                        SDL_RenderPresent(SDLPointers::renderer);
                    }
                } // 0%

                if (event.button.x >= 464 && event.button.x <= 474 && event.button.y >= 216 + 91 && event.button.y <=
                    240 + 91)
                {
                    if (barPointer_2.position != 2)
                    {
                        barPointer_2.position = 2;

                        AppStats::soundVolume = 0.25;
                        changeChunkVolume(SDLPointers::click, AppStats::soundVolume);

                        SDL_RenderCopy(SDLPointers::renderer, settingBackground,NULL, &rect);
                        setPointerByPosition(&barPointer_1, 1);
                        setPointerByPosition(&barPointer_3, 3);

                        setPointerByPosition(&barPointer_2, 2);

                        playChunk(SDLPointers::click);

                        SDL_RenderPresent(SDLPointers::renderer);
                    }
                } // 25%

                if (event.button.x >= 550 && event.button.x <= 560 && event.button.y >= 216 + 91 && event.button.y <=
                    240 + 91)
                {
                    if (barPointer_2.position != 3)
                    {
                        barPointer_2.position = 3;

                        AppStats::soundVolume = 0.5;
                        changeChunkVolume(SDLPointers::click, AppStats::soundVolume);

                        SDL_RenderCopy(SDLPointers::renderer, settingBackground,NULL, &rect);
                        setPointerByPosition(&barPointer_1, 1);
                        setPointerByPosition(&barPointer_3, 3);

                        setPointerByPosition(&barPointer_2, 2);

                        playChunk(SDLPointers::click);

                        SDL_RenderPresent(SDLPointers::renderer);
                    }
                } // 50%

                if (event.button.x >= 631 && event.button.x <= 641 && event.button.y >= 216 + 91 && event.button.y <=
                    240 + 91)
                {
                    if (barPointer_2.position != 4)
                    {
                        barPointer_2.position = 4;

                        AppStats::soundVolume = 0.75;
                        changeChunkVolume(SDLPointers::click, AppStats::soundVolume);

                        SDL_RenderCopy(SDLPointers::renderer, settingBackground,NULL, &rect);
                        setPointerByPosition(&barPointer_1, 1);
                        setPointerByPosition(&barPointer_3, 3);

                        setPointerByPosition(&barPointer_2, 2);

                        playChunk(SDLPointers::click);

                        SDL_RenderPresent(SDLPointers::renderer);
                    }
                } // 75%

                if (event.button.x >= 710 && event.button.x <= 720 && event.button.y >= 216 + 91 && event.button.y <=
                    240 + 91)
                {
                    if (barPointer_2.position != 5)
                    {
                        barPointer_2.position = 5;

                        AppStats::soundVolume = 1;
                        changeChunkVolume(SDLPointers::click, AppStats::soundVolume);

                        SDL_RenderCopy(SDLPointers::renderer, settingBackground,NULL, &rect);
                        setPointerByPosition(&barPointer_1, 1);
                        setPointerByPosition(&barPointer_3, 3);

                        setPointerByPosition(&barPointer_2, 2);

                        playChunk(SDLPointers::click);

                        SDL_RenderPresent(SDLPointers::renderer);
                    }
                } // 100%
            } // Область регулировки громкости звуков


            if (event.button.x >= 373 && event.button.x <= 741 && event.button.y >= 359 && event.button.y <= 446)
            {
                if (event.button.x >= 391 && event.button.x <= 401 && event.button.y >= 216 + 91 * 2 && event.button.y
                    <=
                    240 + 91 * 2)
                {
                    if (barPointer_3.position != 1)
                    {
                        barPointer_3.position = 1;

                        AppStats::gameMode = 1;

                        description = createTexture("DiffDescription_1.png");

                        SDL_RenderCopy(SDLPointers::renderer, settingBackground,NULL, &rect);
                        SDL_RenderCopy(SDLPointers::renderer, description,NULL, &d_rect);

                        setPointerByPosition(&barPointer_1, 1);
                        setPointerByPosition(&barPointer_2, 2);

                        setPointerByPosition(&barPointer_3, 3);

                        playChunk(SDLPointers::click);

                        SDL_RenderPresent(SDLPointers::renderer);
                    }
                } // 0%

                if (event.button.x >= 550 && event.button.x <= 560 && event.button.y >= 216 + 91 * 2 && event.button.y
                    <= 240 + 91 * 2)
                {
                    if (barPointer_3.position != 3)
                    {
                        barPointer_3.position = 3;

                        AppStats::gameMode = 2;

                        description = createTexture("DiffDescription_2.png");

                        SDL_RenderCopy(SDLPointers::renderer, settingBackground,NULL, &rect);
                        SDL_RenderCopy(SDLPointers::renderer, description,NULL, &d_rect);
                        
                        setPointerByPosition(&barPointer_1, 1);
                        setPointerByPosition(&barPointer_2, 2);

                        setPointerByPosition(&barPointer_3, 3);

                        playChunk(SDLPointers::click);

                        SDL_RenderPresent(SDLPointers::renderer);
                    }
                } // 50%

                if (event.button.x >= 710 && event.button.x <= 720 && event.button.y >= 216 + 91 * 2 && event.button.y
                    <= 240 + 91 * 2)
                {
                    if (barPointer_3.position != 5)
                    {
                        barPointer_3.position = 5;

                        AppStats::gameMode = 3;

                        description = createTexture("DiffDescription_3.png");
                        
                        SDL_RenderCopy(SDLPointers::renderer, settingBackground,NULL, &rect);
                        SDL_RenderCopy(SDLPointers::renderer, description,NULL, &d_rect);

                        setPointerByPosition(&barPointer_1, 1);
                        setPointerByPosition(&barPointer_2, 2);

                        setPointerByPosition(&barPointer_3, 3);

                        playChunk(SDLPointers::click);

                        SDL_RenderPresent(SDLPointers::renderer);
                    }
                } // 100%
            } // Область регулировки сложности
        }
    }
    while (quit == false);

    SDL_DestroyTexture(settingBackground);
    SDL_DestroyTexture(description);
    SDL_DestroyTexture(barPointer_1.texture);
    SDL_DestroyTexture(barPointer_2.texture);
    SDL_DestroyTexture(barPointer_3.texture);
}
