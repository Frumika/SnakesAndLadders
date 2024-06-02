#include "1-Sc-File-01-Header.h"
#include <iostream>

using namespace std;


/*
 * 
 */
void runMainScreen()
{
    if (AppStats::exit == false)
    {
        do
        {
            SDL_Texture* background = createTexture("MainScreenBackground.jpg");
            SDL_Rect rect = {0, 0, ScreenCharacter::SCREEN_WIDTH, ScreenCharacter::SCREEN_HEIGHT};
            SDL_Event event;

            int button = 0;

            SDL_RenderCopy(SDLPointers::renderer, background,NULL, &rect);

            SDL_RenderPresent(SDLPointers::renderer);

            bool quit = false;

            do
            {
                SDL_PollEvent(&event);

                if (event.type == SDL_QUIT)
                {
                    quit = true;
                    AppStats::exit = true;
                }

                if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
                {
                    if (event.button.x >= 213 && event.button.x <= 469
                        && event.button.y >= 146 && event.button.y <= 193)
                    {
                        quit = true;
                        button = 1;
                        cout << "Начать игру" << endl;
                    }

                    if (event.button.x >= 213 && event.button.x <= 469
                        && event.button.y >= 223 && event.button.y <= 270)
                    {
                        quit = true;
                        button = 2;
                    }

                    if (event.button.x >= 213 && event.button.x <= 469
                        && event.button.y >= 300 && event.button.y <= 347)
                    {
                        quit = true;
                        button = 3;
                    } // Правила

                    if (event.button.x >= 213 && event.button.x <= 469
                        && event.button.y >= 375 && event.button.y <= 422)
                    {
                        quit = true;
                        button = 4;
                    } // О бонусах

                    if (event.button.x >= 213 && event.button.x <= 469
                        && event.button.y >= 450 && event.button.y <= 497)
                    {
                        quit = true;
                        AppStats::exit = true;
                    } // Выход
                }
            }
            while (!quit);

            SDL_DestroyTexture(background);

            switch (button)
            {
            case 1:
                {
                }
                break;
            case 2:
                {
                    cout << playChunk(SDLPointers::click) << endl;
                    runSettingScreen();
                }
                break;
            case 3:
                {
                    cout << playChunk(SDLPointers::click) << endl;
                    runRulesScreen();
                }
                break;
            case 4:
                {
                    cout << playChunk(SDLPointers::click) << endl;
                    runBonusScreen();
                }
                break;
                
            default:
                {
                    cout << playChunk(SDLPointers::click) << endl;
                    SDL_Delay(500);
                }
            }
        }
        while (AppStats::exit == false);
    }
}
