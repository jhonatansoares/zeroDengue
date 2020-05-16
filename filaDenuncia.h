#include <stdio.h>
#include <stdlib.h>
#include "denuncia.h"

typedef struct filaDenuncia{
    int size;
    int code;
    Denuncia *first;
    Denuncia *last;
}FilaDenuncia;

FilaDenuncia * newFilaDenuncia(int code);