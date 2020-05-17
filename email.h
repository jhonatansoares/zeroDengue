#include <stdio.h>
#include <stdlib.h>

typedef struct email{
    int cod;
    char email[50];
}Email;

Email * newEmail(int cod, char email[50]);
void printEmail(Email *);
