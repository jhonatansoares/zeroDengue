#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "telefone.h"

Telefone * newTelefone(int code, char number[15]){
    Telefone *t = (Telefone *)malloc(sizeof(Telefone));

    if(t != NULL){
        t -> cod = code;
        strcpy(t -> number , number);
        return t;
    }
    return NULL;
}