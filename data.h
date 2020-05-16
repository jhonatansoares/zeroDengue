#include <stdio.h>
#include <stdlib.h>

typedef struct data{
    int code;
    char year[5];
    char mounth[3];
    char day[3];
}Data;

Data * newData(int code, char year[5], char mounth[3], char day[3]);