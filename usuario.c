#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

Usuario * newUsuario(int code, char name[30], char lastName[30], char cpf[15], Telefone *t1, Telefone *t2, Email *email, Endereco *endereco, char login[30], char senha[30]){
    Usuario *u = (Usuario *)malloc(sizeof(Usuario));

    if(u != NULL){
        u -> code = code;
        strcpy(u -> name, name);
        strcpy(u -> lastName, lastName);
        strcpy(u -> cpf, cpf);
        strcpy(u -> login, login);
        strcpy(u -> senha, senha);
        u -> fone1 = t1;
        u -> fone2 = t2;
        u -> email = email;
        u -> endereco = endereco;
        u -> next = NULL;

    }
}
