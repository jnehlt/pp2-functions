#include <stdio.h>
#include "../headers/generuj.h"

void gen_print(int tab[], int n){
    int i;
    for(i = 0; i < n; i++){
        if(i != 0 && i % 5 == 0)
            printf("\n");
        printf("%d\t",tab[i]);
    }

    return;
}
