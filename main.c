#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


int main(){
    

    Fila *f = newFila(1);
    Telefone *t = newTelefone(1,"(19)981692393");
    Telefone *t2 = newTelefone(2,"(19)981692393");

    Email *em = newEmail(1,"jhonatansoares62@gmail.com");
    Endereco *en = newEndereco(1,"brasil", "sao paulo", "campinas", "parque via norte", "rua das terras",21 ,"casa","13862837");
    Usuario *u = newUsuario(1, "jhonatan", "soares", "0919211194-7", t, t2, em, en, "jh", "jh");

    
    printUsuario(u);

    return 0;
}