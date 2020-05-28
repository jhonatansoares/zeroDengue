#include "../headers/tela.h"
#include <stdio.h>
#include <stdlib.h>
#include "../headers/printer.h"


void exibirTelaInicial(){
    int opcao = exibirOpcoesTelaInicial();
    switch (opcao){
    case 1:
        exibirTelaLogin();
        break;
    
    case 2:
        //exibirTelaCadastro();
        break;
    default:
        break;
    }
}
void exibirTelaLogin(){
    
}
void exibirTelaCadastro();
void exibirTelaAtividades();
void exibirTelaConsultarDenuncias();
void exibirTelaConsultarUsuario();
void exibirTelaGerenciarUsuarios();
void exibirTelaGerenciarDenuncias();
void exibirTelaAlterarUsuario();
void exibirTelaAlterarDenuncia();
void exibirTelaGerenciarFilaDenuncias();
void exibirTelaGerenciarFilaUsuarios();


int exibirOpcoesTelaAtividades();
int exibirOpcoesTelaInicial(){
    printf("\n");
    printChar('*', 5);
    printf("\t\t  1 = Fazer login");
    printChar(' ', 82);
    printChar('*', 5);
    printf("\n");
    printChar('*', 5);
    printf("\t\t  2 = Fazer Cadastro");
    printChar(' ', 79);
    printChar('*', 5);
    printf("\n");
    printChar('*', 5);
    printf("\t\t  3 = Encerrar sessao");
    printChar(' ', 78);
    printChar('*', 5);
    printf("\n");
    printChar('*', 5);
    printChar(' ', 110);
    printChar('*', 5);
    printf("\n");
    printChar('*', 120);
    printf("\n");
    printChar('*', 120);
    printf("\n");
    printf("\t\t  Digite...  ");
    int opcao = 0;
    scanf("%d",&opcao);
    return opcao;
}
int exibirTelaOpcoesConsultarDenuncias();
int exibirTelaOpcoesAlterarDenuncia();
int exibirTelaOpcoesConsultarUsuario();
int exibirTelaOpcoesAlterarUsuario();
int exibirTelaOpcoesFiltrarUsuarios();
int exibirTelaOpcoesFiltrarDenuncias();
int exibirTelaOpcoesGerenciarUsuarios();
int exibirTelaOpcoesGerenciarDenuncia();
int exibirTelaOpcoesGerenciarFilaDenuncias();
int exibirTelaOpcoesTelaInicial();
int exibirTelaOpcoesGerenciarfilaUsuarios();