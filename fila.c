#include "fila.h"


Fila * newFila(int code){
    Fila * f = (Fila *)malloc(sizeof(Fila));
    if(f != NULL){
        f -> code = code;
        f -> size = 0;
        f -> first = NULL;
        f -> last = NULL;
        return f;
    }
    return NULL;
}

FilaUsuario * newFilaUsuario(int code){
    FilaUsuario *f = (FilaUsuario *)malloc(sizeof(FilaUsuario));

    if(f != NULL){
        f -> code = code;
        f -> size = 0;
        f -> first = NULL;
        f -> last = NULL;
        return f;
    }
    return NULL;
}

FilaDenuncia * newFilaDenuncia(int code){
    FilaDenuncia *f = (FilaDenuncia *)malloc(sizeof(FilaDenuncia));

    if(f != NULL){
        f -> code = code;
        f -> size = 0;
        f -> first = NULL;
        f -> last = NULL;
        return f;
    }
    return NULL;
}