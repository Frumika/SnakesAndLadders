﻿#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "../1-Screens/1-Sc-File-01-Header.h"
#include "0-Co-File-02-Structs.h"
#include "0-Co-File-03-Namespaces.h"


SDL_Window* createWindow();

SDL_Renderer* createRenderer();

SDL_Texture* createTexture(const char* file);

void runApplication();