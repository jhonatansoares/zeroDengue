#include <stdio.h>
#include <stdlib.h>
#include "denuncia.h"



typedef struct Fila{
    int size;
    int code;
    void *first;
    void *last;
}Fila;

typedef struct filaDenuncia{
    int size;
    int code;
    Denuncia *first;
    Denuncia *last;
}FilaDenuncia;


typedef struct filaUsuario{
    int code;
    int size;
    Usuario *first;
    Usuario *last;
}FilaUsuario;


Fila * newFila(int code);
FilaUsuario * newFilaUsuario(int code);
FilaDenuncia * newFilaDenuncia(int code);