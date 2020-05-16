#include <stdio.h>
#include <stdlib.h>
#include "telefone.h"
#include "email.h"
#include "endereco.h"



typedef struct usuario{
    int code;
    char name[30], lastName[30], cpf[15] ;
    Telefone *fone1, *fone2;
    Email *email;
    Endereco *endereco;
    char login[30], senha[30];
    struct Usuario *next;
}Usuario;

Usuario * newUsuario(int cod, char name[30],char lastName[30],char cpf[15], Telefone *t1, Telefone *t2, Email *email, Endereco *endereco, char login[30], char senha[30]);