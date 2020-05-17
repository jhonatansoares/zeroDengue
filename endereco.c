#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "endereco.h"

Endereco * newEndereco(int code, char pais[30], char estado[30], char cidade[30], char bairro[50], char rua[50], int numero, char complemento[20], char cep[15]){
    Endereco *e = (Endereco *)malloc(sizeof(Endereco));

    if(e != NULL){
        e -> code = code;
        strcpy(e -> pais, pais);  
        strcpy(e -> estado, estado);  
        strcpy(e -> cidade, cidade);  
        strcpy(e -> bairro, bairro);  
        strcpy(e -> rua, rua);
        e -> numero = numero; 
        strcpy(e -> complemento, complemento);
        strcpy( e -> cep, cep);
        return e;
    }
    return NULL;
}
void printEndereco(Endereco *e){
    if(e == NULL){
        printf("\n\tEndereco nao encontrado");
        return;
    }
    printf("\n*\tPais = %s ", e -> pais );
    printf("\n*\tEstado = %s ", e -> estado );
    printf("\n*\tCidade = %s ", e -> cidade );
    printf("\n*\tBairro = %s ", e -> bairro );
    printf("\n*\tRua = %s ", e -> rua );
    printf("\n*\tNumero = %d ", e -> numero );
    printf("\n*\tComplemento = %s ", e -> complemento );
    printf("\n*\tCep = %s ", e -> cep );
}