#include <stdlib.h>

typedef struct telefone{
    int cod;
    char number[15];
}Telefone;

Telefone * newTelefone(int code, char number[15]);
void printTelefone(Telefone *);
