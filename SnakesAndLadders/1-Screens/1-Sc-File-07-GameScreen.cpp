#include "1-Sc-File-01-Header.h"
#include <iostream>

using namespace std;


void runGameScreen()
{
    SDL_Texture* gameBackground = createTexture("GameBackground_5.jpg");
    SDL_Rect rect = {0, 0, ScreenCharacter::SCREEN_WIDTH, ScreenCharacter::SCREEN_HEIGHT};
    SDL_Event event;

    int currentPlayer = 0;
    int cubeValue = 0;
    bool end = false;

    Player* players = new Player[AppStats::numOfPlayers];
    createPlayers(players);

    SDL_RenderCopy(SDLPointers::renderer, gameBackground,NULL, &rect);

    showAllPieces(players);

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
            if (event.button.x >= 873 && event.button.x <= 1130 && event.button.y >= 378 && event.button.y <= 426)
            {
                playChunk(SDLPointers::click);

                cubeValue = getRandomValue(1, 6);

                for (int i = 0; i < cubeValue; i++)
                {
                    if (checkPosition(players))
                    {
                        players[currentPlayer].piece.position += 1;
                        cout << players[currentPlayer].piece.position << endl;

                        setPieceByPosition(&players[currentPlayer]);

                        SDL_RenderCopy(SDLPointers::renderer, gameBackground,NULL, &rect);

                        drawCubeScore(cubeValue);
                        showNumOfCurrentPlayer(players[currentPlayer].id, 871, 138);

                        showAllPieces(players);

                        SDL_RenderPresent(SDLPointers::renderer);

                        SDL_Delay(300);
                    }

                    else
                    {
                        SDL_Delay(300);
                        end = true;
                        quit = true;
                        break;
                    }
                }

                if (end == false)
                {
                    int check = checkSnakeAndLadder(&players[currentPlayer]);

                    if (check == 1)
                    {
                        SDL_RenderCopy(SDLPointers::renderer, gameBackground,NULL, &rect);
                        showAllPieces(players);
                        drawCubeScore(cubeValue);
                        showNumOfCurrentPlayer(players[currentPlayer].id, 871, 138);

                        SDL_RenderPresent(SDLPointers::renderer);
                    }

                    setCurrentPlayer(currentPlayer);
                }
            }

            if (event.button.x >= 873 && event.button.x <= 1130 && event.button.y >= 443 && event.button.y <= 491)
            {
                playChunk(SDLPointers::click);
                runSettingScreen();

                SDL_RenderCopy(SDLPointers::renderer, gameBackground,NULL, &rect);

                showAllPieces(players);
                drawCubeScore(cubeValue);
                showNumOfCurrentPlayer(players[currentPlayer].id, 871, 138);

                SDL_RenderPresent(SDLPointers::renderer);
            }

            if (event.button.x >= 873 && event.button.x <= 1130 && event.button.y >= 509 && event.button.y <= 557)
            {
                playChunk(SDLPointers::click);
                runBonusScreen();

                SDL_RenderCopy(SDLPointers::renderer, gameBackground,NULL, &rect);

                showAllPieces(players);
                drawCubeScore(cubeValue);
                showNumOfCurrentPlayer(players[currentPlayer].id, 871, 138);

                SDL_RenderPresent(SDLPointers::renderer);
            }

            if (event.button.x >= 873 && event.button.x <= 1130 && event.button.y >= 575 && event.button.y <= 623)
            {
                playChunk(SDLPointers::click);
                quit = true;
            }
        }
    }
    while (quit == false);

    SDL_DestroyTexture(gameBackground);

    if (end == true) runEndScreen(players[currentPlayer].id);

    delete[]players;
}
