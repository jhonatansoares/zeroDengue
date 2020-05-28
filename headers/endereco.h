#include <stdio.h>
#include <stdlib.h>

typedef struct endereco{
    int code;
    char pais[30];
    char estado[30];
    char cidade[30];
    char bairro[50];
    char rua[50];
    int numero;
    char complemento[20];
    char cep[15];
}Endereco;

Endereco * newEndereco(int code, char pais[30], char estado[30], char cidade[30], char bairro[50], char rua[50], int numero, char complemento[20], char cep[15]);
void printEndereco(Endereco *);
