#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "email.h"

Email * newEmail(int cod, char email[50]){
    Email *e = (Email *)malloc(sizeof(Email));
    if(e != NULL){
        e -> cod = cod;
        strcpy(e -> email, email);
        return e;
    }
    return NULL;
}
