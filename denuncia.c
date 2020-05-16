#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "denuncia.h"


Denuncia * newDenuncia( int code, Data *postagem, Data *encerramento, Endereco *endereco, Usuario *usuario, char descricao[500], int status, Denuncia *next){
    Denuncia *d = (Denuncia *)malloc(sizeof(Denuncia));

    if(d != NULL){
        d -> code = code;
        d -> postagem = postagem;
        d -> encerramento = encerramento;
        strcpy(d -> descricao,"Sem descricao");
        d -> endereco = endereco;
        d -> usuario = usuario;
        d -> status = status;
        d -> next =NULL;
        return d;
    }
    return NULL;
}
