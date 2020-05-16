#include "fila.h"

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