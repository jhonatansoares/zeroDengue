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
void printDenuncia(Denuncia *d){
    printf("\n******************************************************************************************************************");
    printf("\n*\tCodigo = %d ", d -> code); 
    printf("\n*\tStatus = ");
    printf("%d", d -> status);
    printf("\n*\tData da postagem  = ");
    printData(d -> postagem);
    printf("\n*\tDescricao = %s ",d -> descricao);
    printf("\n*\tEndereco da denuncia.");
    printEndereco(d -> endereco);
    printf("\n*\tUsuario que fez a denuncia: ");
    printf("\n*\tNome = %s %s Contato = %s %s\n", d -> usuario -> name, d -> usuario -> lastName, d -> usuario -> fone1 -> number, d -> usuario -> fone2 -> number );
    printf("\n******************************************************************************************************************");
}

