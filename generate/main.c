#include "./lib/headers/generuj.h"

#define n 20    //wielkosc tablicy
#define min 10  //minimalna wartosc dla generatora liczb pseudolosowych (do wypelniania tablicy)
#define max 40  //maksymalna wartosc dla generatora liczb pseudolosowych (do wypelniania tablicy)

int main(void){
    int tab[n];
    gen_rand(tab, n, min, max, 1);
    gen_print(tab,n);

    return 0;
}
