#include "2-Se-File-01-Header.h"
#include <fstream>
#include <string>

using namespace std;


/*
 * Функция выполняет следующие действия:
 * 1. Считывает информацию из файла 9-Undefined-File-01-SettingList.txt.
 * 2. Записывает полученные данные в пространсто имён AppStats.
 *
 * Функция возвращает:
 * 1. 1 - Если файл был открыт и оттуда были считанны данные.
 * 2. 0 - Если файл не удалось открыть.
 */
int readSettingList()
{
    fstream file("9-Undefined-File-01-SettingList.txt", ios::in);
    string line;
    int cur = 0;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (cur == 0) AppStats::exit = false;
            else if (cur == 1) AppStats::gameMode = stoi(line);
            else if (cur == 2) AppStats::musicVolume = stod(line);
            else if (cur == 3) AppStats::soundVolume = stod(line);
            cur++;
        }

        file.close();
        return 1;
    }

    else return 0;
}
