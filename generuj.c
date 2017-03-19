#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "../headers/generuj.h"

static void error(int *flag);

void gen_rand(int tab[], int rozmiar, int min, int max, int flag)//if(flag){losuj bez powtorzen} else{losuj z powtorzeniami}
{                                                                //   |
    if(max - min < rozmiar && flag)//sprawdz poprawnosc danych   //   |
        error(&flag);                                            //   |
    int iterator = 1;                                            //   |
    if(flag){//<------------------------------------------------------+
        int bufor, check_iterator;//zmienne pomocnicze: bufor - do przechowywania wygenerowanej wartosci, check_iterator - do iteracji *'petli wewnetrznej'
        srand(time(NULL));                                                                                                          //   |
        tab[0] = (int) (max - min) * rand() / RAND_MAX + min;//wylosuj pierwsza wartosc                                                  |
        while (iterator < rozmiar){                                                                                                 //   |
            bufor = (int) (max - min) * rand() / RAND_MAX + min;//losuj liczbe z przedzialu (min - max)                                  |
            flag = 0;                                                                 //  +----------------------------------------------+
                                                                                      //  |
            for(check_iterator = 1; iterator - check_iterator >= 0; check_iterator++){//*'petla wewnetrzna' - sprawdza czy wylosowany element juz wystepuje
                                                                                                                                   // |
                if(bufor == tab[iterator - check_iterator])//-------------------------------------------------------------------------+-------------> bufor
                    break;
                else{
                    flag++;
                    if(iterator - check_iterator == 0)//zadbaj o to by w przypadku powtarzajacych sie danych, flaga byla != od check_iterator
                        break;
                }
            }
            if(flag == check_iterator){
                tab[iterator] = bufor;
                iterator++;
            }
        }
    }
    else{//instrukcje wykonywane w przypadku wypelniania tablicy danymi ktore moga sie powtarzac
        srand(time(NULL));
        for (iterator = 0; iterator < rozmiar; iterator++){
            tab[iterator] = (int) (max - min) * rand() / RAND_MAX + min;
        }
    }
    return;
}

void error(int *flag){
    printf_s("Rozmiar tablicy danych, jest mniejszy niz podany przedzial.\n\tProgram automatycznie zmieni tryb\n\ti wykona wypelnianie z powtorzeniami...\n");
    *flag = 0;
    system("Pause");
    return;
}
