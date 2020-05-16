#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"

typedef struct filaUsuario{
    int code;
    int size;
    Usuario *first;
    Usuario *last;
}FilaUsuario;

FilaUsuario * newFilaUsuario(int code);
