#include <stdio.h>
#include <stdlib.h>
#include "headers/fila.h"
#include "headers/printer.h"
#include "headers/tela.h"


int main(){
    
    Telefone *t = newTelefone(1,"(19)454645666");
    Telefone *t2 = newTelefone(2,"(19)3456345");

    Email *em = newEmail(1,"jhonatansoares62@gmail.com");
    Endereco *en = newEndereco(1,"brasil", "sao paulo", "campinas", "parque via norte", "rua das terras",21 ,"casa","13862837");
    Usuario *u = newUsuario(1, "jhonatan", "soares", "34538465", t, t2, em, en, "jh", "jh");

    Data *data = newData("1010", "10", "10");
    Denuncia *d = newDenuncia(1, data, data, en, u, "sem descricao", 1, NULL);
    
    printUsuario(u);
    printDenuncia(d);

    exibirCabecalho();        
    exibirOpcoesTelaInicial();
    return 0;
}