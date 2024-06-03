#include <cstdlib>

int getRandomValue(int startNum, int endNum)
{
    return rand() % (endNum - startNum + 1) + startNum;
}
