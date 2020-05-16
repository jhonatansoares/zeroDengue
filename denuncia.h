#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "usuario.h"


typedef struct denuncia{
    int code;
    Data *postagem;
    Data *encerramento;
    Endereco *endereco;
    Usuario *usuario;
    char descricao[500];
    int status;
    struct Denuncia *next;
}Denuncia;

Denuncia * newDenuncia( int code, Data *postagem, Data *encerramento, Endereco *endereco, Usuario *usuario, char descricao[500], int status, Denuncia *next);