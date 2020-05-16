#include <stdio.h>
#include <stdlib.h>
#include "email.h"

int main(){
    char meuEmail[50] = "jhonatansoare62@gmail.com";
    Email *email = newEmail(1, meuEmail);
    printf("\n\tEmail = %s", email -> email);
    return 0;
}