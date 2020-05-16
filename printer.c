#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "printer.h"


void printDataNotFound(){
    printf("\n\tDado nao encontrado");
}

void printUsuario(Usuario *u){
    printf("\n***********************************************************************************");
    if(u == NULL){
        printDataNotFound();
        return;
    }
    printf("\n*\tCodigo = %d ", &u -> code);
    printf("\n*\tNome = %s ", u -> name);
    printf("Sobrenome = %s ", u -> lastName);
    printf("Cpf = %s ", u -> cpf);
    printf("\n*\tLogin = %s ", u -> login);
    printf("Senha = %s ", u -> senha);
    printTelefone(u -> fone1);
    printTelefone(u -> fone2);
    printEmail(u -> email);
    printf("\n*\t\tEndereco do usuario");
    printEndereco(u -> endereco);
    printf("\n***********************************************************************************\n");   
}
void printTelefone(Telefone *t){
    if(t == NULL){
        printDataNotFound();
        return;
    }
    printf("\n*\tTelefone %s ",t -> number);
}
void printEmail(Email *e){
    if(e == NULL){
        printDataNotFound();
        return;
    }
    printf("\n\tEmail = %s", e -> email);
}
void printEndereco(Endereco *e){
    if(e == NULL){
        printDataNotFound();
        return;
    }
}
void printDenuncia(Denuncia *d){
    if(d == NULL){
        printDataNotFound();
        return;
    }
   
}
void printData(Data *d){
    if(d == NULL){
        printDataNotFound();
        return;
    }
    printf("\n\tData = %s//%s//%s", d -> year, d -> mounth, d -> day);
}
void printFilaUsuario(FilaUsuario *fu){
    if(fu == NULL){
        printDataNotFound();
        return;
    }
}
void printFilaDenuncia(FilaDenuncia *fd){
    if(fd == NULL){
        printDataNotFound();
        return;
    }
}


