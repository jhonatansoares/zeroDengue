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
