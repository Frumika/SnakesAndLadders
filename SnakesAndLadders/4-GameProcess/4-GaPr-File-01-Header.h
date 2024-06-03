#pragma once

#include "../0-Common/0-Co-File-01-Header.h"
#include "../0-Common/0-Co-File-02-Structs.h"

int getRandomValue(int startNum, int endNum);

SDL_Texture* createTextureFromText(char* text);

void converIntToChar(char* text, int value);

void drawCubeScore(int value);

void createPlayers(Player* players);

void setPieceByPosition(Player* player);

void setCurrentPlayer(int& value);

void showAllPieces(Player* players);

void showNumOfCurrentPlayer(int value);

int checkSnakeAndLadder(Player* player);