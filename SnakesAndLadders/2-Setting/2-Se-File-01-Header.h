#pragma once

#include "../0-Common/0-Co-File-01-Header.h"
#include "../0-Common/0-Co-File-02-Structs.h"

int readSettingList();

int editSettingList();

int setPointerByPosition(SettingPointer* pointer, int level);
