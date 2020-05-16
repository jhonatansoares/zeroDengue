#include <stdio.h>
#include <stdlib.h>
#include "filaDenuncia.h"

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


