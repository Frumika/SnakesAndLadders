#include "1-Sc-File-01-Header.h"
#include <iostream>

using namespace std;


void runGameScreen()
{
    SDL_Texture* gameBackground = createTexture("GameBackground_7.jpg");
    SDL_Rect rect = {0, 0, ScreenCharacter::SCREEN_WIDTH, ScreenCharacter::SCREEN_HEIGHT};
    SDL_Event event;

    int currentPlayer = 0;
    int cubeValue = 0;
    bool end = false;

    Bonus* bonuses = new Bonus[6];
    createBonuses(bonuses);

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

                if (players[currentPlayer].bonuses[0].status != false)
                {
                    cubeValue = 6;
                    useBonus(&players[currentPlayer].bonuses[0]);
                }

                if (players[currentPlayer].bonuses[2].status != false)
                {
                    cubeValue += 1;
                    useBonus(&players[currentPlayer].bonuses[2]);
                }

                if (players[currentPlayer].bonuses[3].status != false)
                {
                    cubeValue = 0;
                    useBonus(&players[currentPlayer].bonuses[3]);
                }

                if (players[currentPlayer].bonuses[4].status != false)
                {
                    cubeValue = 1;
                    useBonus(&players[currentPlayer].bonuses[4]);
                }

                if (players[currentPlayer].bonuses[5].status != false)
                {
                    cubeValue = 0;
                    players[currentPlayer].piece.position = 0;
                    players[currentPlayer].piece.rect.x = 21;
                    players[currentPlayer].piece.rect.y = 646;
                    useBonus(&players[currentPlayer].bonuses[5]);

                    SDL_RenderCopy(SDLPointers::renderer, gameBackground,NULL, &rect);
                    drawCubeScore(cubeValue);
                    showNumOfCurrentPlayer(players[currentPlayer].id, 871, 138);
                    showAllPieces(players);
                    drawPlayerBonuses(&players[currentPlayer]);
                    SDL_RenderPresent(SDLPointers::renderer);
                }

                for (int i = 0; i < cubeValue; i++)
                {
                    if (checkPosition(players))
                    {
                        players[currentPlayer].piece.position += 1;

                        cout << players[currentPlayer].id << " | " << players[currentPlayer].piece.position << endl;

                        setPieceByPosition(&players[currentPlayer]);

                        SDL_RenderCopy(SDLPointers::renderer, gameBackground,NULL, &rect);

                        drawCubeScore(cubeValue);

                        showNumOfCurrentPlayer(players[currentPlayer].id, 871, 138);

                        showAllPieces(players);

                        drawPlayerBonuses(&players[currentPlayer]);

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
                    if (findBonus(&players[currentPlayer], bonuses))
                    {
                        SDL_RenderCopy(SDLPointers::renderer, gameBackground,NULL, &rect);
                        showAllPieces(players);
                        drawCubeScore(cubeValue);
                        showNumOfCurrentPlayer(players[currentPlayer].id, 871, 138);

                        drawPlayerBonuses(&players[currentPlayer]);

                        SDL_RenderPresent(SDLPointers::renderer);
                    }

                    if (players[currentPlayer].bonuses[1].status == false)
                    {
                        int check = checkSnakeAndLadder(&players[currentPlayer]);

                        if (check == 1)
                        {
                            SDL_RenderCopy(SDLPointers::renderer, gameBackground,NULL, &rect);
                            showAllPieces(players);
                            drawCubeScore(cubeValue);
                            showNumOfCurrentPlayer(players[currentPlayer].id, 871, 138);
                            drawPlayerBonuses(&players[currentPlayer]);

                            SDL_RenderPresent(SDLPointers::renderer);
                        }
                    }

                    if (players[currentPlayer].bonuses[1].status != false) useBonus(&players[currentPlayer].bonuses[1]);

                    setCurrentPlayer(currentPlayer);
                }
            }

            if (event.button.x >= 873 && event.button.x <= 1130 && event.button.y >= 443 && event.button.y <= 491)
            {
                Player prev = findPrevPlayer(players, &players[currentPlayer]);

                playChunk(SDLPointers::click);
                runSettingScreen();

                SDL_RenderCopy(SDLPointers::renderer, gameBackground,NULL, &rect);

                showAllPieces(players);
                drawCubeScore(cubeValue);
                showNumOfCurrentPlayer(prev.id, 871, 138);

                drawPlayerBonuses(&prev);

                SDL_RenderPresent(SDLPointers::renderer);
            }

            if (event.button.x >= 873 && event.button.x <= 1130 && event.button.y >= 509 && event.button.y <= 557)
            {
                Player prev = findPrevPlayer(players, &players[currentPlayer]);

                playChunk(SDLPointers::click);
                runBonusScreen();

                SDL_RenderCopy(SDLPointers::renderer, gameBackground,NULL, &rect);

                showAllPieces(players);
                drawCubeScore(cubeValue);
                showNumOfCurrentPlayer(prev.id, 871, 138);

                drawPlayerBonuses(&prev);

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
