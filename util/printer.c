#include "../headers/printer.h"
#include <stdio.h>
#include <stdlib.h>

void printChar(char c, int vezes){
    for(int i = 0; i < vezes; i++){
        printf("%c", c);
    }
}
void printString(char *palavra){
    printf("%s", palavra);
}
void exibirCabecalho(){
    system("cls");
    printChar('*', 120);
    printf("\n");
    printChar('*', 120);
    printf("\n");
    printChar('*', 48);
    printf("   Projeto zero Dengue  ");
    printChar('*', 48);
    printf("\n");
    printChar('*', 120);
    printf("\n");
    printChar('*', 120);
}
