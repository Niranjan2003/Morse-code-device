#include "utils.h"
#include <stdio.h>
#include <string.h>

// Static variable for filtering
static float previousAy = 0.0f;

void printFloat(float value)
{
    if (value == 0.0f)
    {
        System_printf("0.00");
        return;
    }

    int intPart = (int)value;
    float fracPart = value - intPart;
    int sign = (intPart < 0 || fracPart < 0) ? -1 : 1;

    if (sign == -1)
    {
        System_printf("-");
        intPart = -intPart;
        fracPart = -fracPart;
    }

    System_printf("%d.", intPart);

    int fracInt = (int)(fracPart * 100.0f);

    if (fracInt < 0)
    {
        fracInt = -fracInt;
    }

    System_printf("%02d", fracInt);
}

void displaySensorAvg(float *arx, float *ary, float *arz, const unsigned int arrSize)
{
    printFloat(arx[0]);
    System_printf(",");
    printFloat(ary[0]);
    System_printf(",");
    printFloat(arz[0]);
    System_printf("\n");
    System_flush();
}

char morseToAscii(const char *morse)
{
    if (strcmp(morse, ".-") == 0)
        return 'A';
    else if (strcmp(morse, "-...") == 0)
        return 'B';
    else if (strcmp(morse, "-.-.") == 0)
        return 'C';
    else if (strcmp(morse, "-..") == 0)
        return 'D';
    else if (strcmp(morse, ".") == 0)
        return 'E';
    else if (strcmp(morse, "..-.") == 0)
        return 'F';
    else if (strcmp(morse, "--.") == 0)
        return 'G';
    else if (strcmp(morse, "....") == 0)
        return 'H';
    else if (strcmp(morse, "..") == 0)
        return 'I';
    else if (strcmp(morse, ".---") == 0)
        return 'J';
    else if (strcmp(morse, "-.-") == 0)
        return 'K';
    else if (strcmp(morse, ".-..") == 0)
        return 'L';
    else if (strcmp(morse, "--") == 0)
        return 'M';
    else if (strcmp(morse, "-.") == 0)
        return 'N';
    else if (strcmp(morse, "---") == 0)
        return 'O';
    else if (strcmp(morse, ".--.") == 0)
        return 'P';
    else if (strcmp(morse, "--.-") == 0)
        return 'Q';
    else if (strcmp(morse, ".-.") == 0)
        return 'R';
    else if (strcmp(morse, "...") == 0)
        return 'S';
    else if (strcmp(morse, "-") == 0)
        return 'T';
    else if (strcmp(morse, "..-") == 0)
        return 'U';
    else if (strcmp(morse, "...-") == 0)
        return 'V';
    else if (strcmp(morse, ".--") == 0)
        return 'W';
    else if (strcmp(morse, "-..-") == 0)
        return 'X';
    else if (strcmp(morse, "-.--") == 0)
        return 'Y';
    else if (strcmp(morse, "--..") == 0)
        return 'Z';
    else if (strcmp(morse, "-----") == 0)
        return '0';
    else if (strcmp(morse, ".----") == 0)
        return '1';
    else if (strcmp(morse, "..---") == 0)
        return '2';
    else if (strcmp(morse, "...--") == 0)
        return '3';
    else if (strcmp(morse, "....-") == 0)
        return '4';
    else if (strcmp(morse, ".....") == 0)
        return '5';
    else if (strcmp(morse, "-....") == 0)
        return '6';
    else if (strcmp(morse, "--...") == 0)
        return '7';
    else if (strcmp(morse, "---..") == 0)
        return '8';
    else if (strcmp(morse, "----.") == 0)
        return '9';
    else
        return '?';
}

float calculateFilteredAy(const float ay)
{
    float filteredAy = (ay + previousAy) / 2.0f;
    previousAy = ay;
    return filteredAy;
}

float calculateAvg(const float *array, const unsigned int arrSize)
{
    float sum = 0.0f;
    unsigned int i;
    for (i = 0; i < arrSize; i++)
    {
        sum += array[i];
    }

    return sum / arrSize;
}
