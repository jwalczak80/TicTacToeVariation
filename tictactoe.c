#include <stdio.h>                          
#include <stdlib.h>
#include "customlib.h"                                            

int main (){                                          
    int** plansza;                          //inicjalizacja zmiennych
    int wiersze=0,kolumny=0,counter=0;      //
    int* wier=&wiersze;                     //
    int* kol=&kolumny;                      //
    takeSize(wier,kol);
    plansza=makeMatrix(wiersze,kolumny);    //stworzenie planszy
    int value=wiersze*kolumny;
    while ( matrixValue(plansza,wiersze,kolumny) < value )  //właściwa gra
    {
        showMatrix(plansza,wiersze,kolumny);    //pokazanie planszy
        input(plansza,wiersze,kolumny);     //wpisywanie kolejnych ruchów
        counter++;
    }

    finish(counter);    //napisy końcowe
    return 0;
}