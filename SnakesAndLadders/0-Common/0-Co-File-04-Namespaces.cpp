﻿#include "0-Co-File-03-Namespaces.h"

/*
 * В пространстве имен ScreenCharacter хранятся параметры окна приложения:
 * 1. SCREEN_WIDTH - Ширина окна
 * 2. SCREEN_HEIGHT - Высота окна
 */
namespace ScreenCharacter
{
    const int SCREEN_WIDTH = 1280; // Ширина окна
    const int SCREEN_HEIGHT = 720; // Высота окна
}


/*
 * В пространстве имен SDLPointers хранятся указатели на структуры библиотеки SDL:
 * 1. window - Указатель на окно приложения с которым мы работаем.
 * 2. renderer - Указатель на рендер.
 */
namespace SDLPointers
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    TTF_Font* font = NULL;
    Mix_Music* music = NULL;
    Mix_Chunk* click = NULL;
}


/*
 * В пространстве имен AppStats хранаятся параметры отвечающие за состояние приложения:
 * 1. exit - Была ли нажата кнопка, закрывающая приложение. По умолчанию false.
 * 2. gameMode - Текущий уровень сложности.
 * 3. musicVolume - Громкость фоновой музыки.
 * 4. soundVolume - Громкость звуков.
 * 5. numOfPlayers - Количество игроков в сессии.
 * 6. textColor - Цвет текста.
 */
namespace AppStats
{
    bool exit = false;
    int gameMode;
    double musicVolume;
    double soundVolume;
    int numOfPlayers = 0;
    SDL_Color textColor = {0,0,0,255};
}
