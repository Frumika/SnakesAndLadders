#include "4-GaPr-File-01-Header.h"


void createPlayers(Player* players)
{
    for (int i = 0; i < AppStats::numOfPlayers; i++)
    {
        players[i].id = i + 1;
        players[i].score = 0;

        if (i == 0) players[i].piece.texture = createTexture("Piece_1.png");
        if (i == 1) players[i].piece.texture = createTexture("Piece_2.png");
        if (i == 2) players[i].piece.texture = createTexture("Piece_3.png");
        if (i == 3) players[i].piece.texture = createTexture("Piece_4.png");

        players[i].piece.position = 0;
        players[i].piece.rect = {21, 646, 43, 56};
        players[i].isDraw = false;

        players[i].bonuses = new Bonus[6];
    }
}
