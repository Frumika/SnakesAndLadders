#pragma once

#include "0-Co-File-01-Header.h"

struct SettingPointer
{
    SDL_Texture* texture;
    SDL_Rect rect;
    int position;
    bool is_add;
};

struct Bonus
{
    int id = 0;
    int count = 0;
    int position = -1;
    bool status = false;
    SDL_Rect rect;
    SDL_Texture* texture;
};

struct Piece
{
    SDL_Texture* texture;
    SDL_Rect rect;
    int position;
};


struct Player
{
    int id;
    int score;
    Piece piece;
    Bonus* bonuses;
    bool isDraw;
};
