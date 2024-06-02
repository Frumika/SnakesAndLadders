#include "2-Se-File-01-Header.h"
#include <fstream>
#include <string>

using namespace std;


/*
 * Функция выполняет следующие действия:
 * 1. Считывет данные из пространства имён AppStats.
 * 2. Записывает данные в файл 9-Undefined-File-01-SettingList.txt.
 *
 * Функция возвращает:
 * 1. 1 - Если файл был открыт и в него были записанны данные.
 * 2. 0 -Если файл не удалось открыть.
 */
int editSettingList()
{
    fstream file("9-Undefined-File-01-SettingList.txt", ios::out);
    string line;

    if (file.is_open())
    {
        for (int i = 0; i < 4; i++)
        {
            if (i == 0) file << 0 << endl;
            if (i == 1) file << AppStats::gameMode << endl;
            if (i == 2) file << AppStats::musicVolume << endl;
            if (i == 3) file << AppStats::soundVolume;
        }

        file.close();
        return 1;
    }

    return 0;
}
