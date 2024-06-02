#include "../0-Common/0-Co-File-01-Header.h"

void loadMusic(const char* file);

int playMusic();

int changeMusicVolume(double value);

int changeChunkVolume(Mix_Chunk* chunk, double value);

int playChunk(Mix_Chunk* chunk);

void loadChunk(Mix_Chunk* & chunk, const char* file);