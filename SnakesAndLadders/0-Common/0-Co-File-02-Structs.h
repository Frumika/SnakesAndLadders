#pragma once

#include "0-Co-File-01-Header.h"

struct SettingPointer
{
    SDL_Texture* texture;
    SDL_Rect rect;
    int position;
    bool is_add;
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
    bool isDraw;
};
