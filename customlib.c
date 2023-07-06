#include <stdio.h>
#include <stdlib.h>
#include "customlib.h"
void takeSize(int* wiersze, int* kolumny){      //pobranie od gracza rozmiaru planszy
    printf("\nPodaj ilosc wierszy:\n");       
    scanf("%d",wiersze);                      
    printf("\nPodaj ilosc kolumn:\n");            
    scanf("%d",kolumny);
}

int** makeMatrix(int wiersze, int kolumny){     //funkcja tworząca planszę
    int** arr = (int**)malloc(wiersze * sizeof(int*));
    for (int i = 0; i < wiersze; i++)
        arr[i] = (int*)malloc(kolumny * sizeof(int));

    for (int i = 0; i < wiersze; i++)   //zerowanie planszy
    {
        for (int j = 0; j < kolumny; j++)
        {
            arr[i][j]=0;
        }      
    }  
FILE *file=fopen("ruchy.txt","a");      //otworzenie pliku 
if(file==NULL){
    printf("Error opening file!\n");
}
fprintf(file,"Kolejna runda\n");    //zapisywanie informacji o rozpoczęciu nowej rundy
fclose(file);   //zamknięcie pliku
return arr;
}

int matrixValue(int** plansza,int wiersze, int kolumny){    //zliczanie ilości X-ów na planszy
int x=0;
for (int i = 0; i <wiersze; i++){
    for (int j = 0; j <kolumny; j++){
        if(plansza[i][j]){
            x++;
        }
    }
}
return x;   
}

void showMatrix(int** plansza, int wiersze, int kolumny){   //pokazanie planszy w oknie wiersza poleceń    
    printf("\n");
    for (int i = 0; i <wiersze; i++){
        printf("\n");
        for (int j = 0; j <kolumny; j++){
            printf(" ");
            if (plansza[i][j]==1){
                printf("X ");
            }
            else{
                printf("O ");
            }   
        }
    }
}

void input(int** tablica, int wiersze, int kolumny){    //wpisywanie przez gracza kolejnych ruchów 
int wiersz=0,kolumna=0;
FILE *file=fopen("ruchy.txt","a");      //otworzenie pliku do zapisania ruchów gracza
if(file==NULL){
    printf("Error opening file!\n");
}
printf("\nPodaj wiersz:\n");                
scanf("%d",&wiersz);                     
printf("\nPodaj kolumne:\n");               
scanf("%d",&kolumna);

fprintf(file,"X = %d, Y = %d\n",wiersz,kolumna);    //zapisywanie do pliku kolejnych ruchów gracza
fclose(file);   //zamknięcie pliku
if(wiersz<1||kolumna<1){
    printf("Podano błędne koordynaty, proszę ponowić próbę");
}
else{
if (wiersz==1){                             //wpisywanie X-ów do planszy
    for (int i = 0; i < wiersz+1; i++){
            if(tablica[i][kolumna-1]==0){
                tablica[i][kolumna-1]=1;
            }
            else{
                tablica[i][kolumna-1]=0;
            }
    }
}

else if (wiersz==wiersze){
    for (int i = wiersz-2; i < wiersz; i++){
            if(tablica[i][kolumna-1]==0){
                tablica[i][kolumna-1]=1;
            }
            else{
                tablica[i][kolumna-1]=0;
            }
    }
}

else{
    for (int i = wiersz-2; i <= wiersz; i++){
            if(tablica[i][kolumna-1]==0){
                tablica[i][kolumna-1]=1;
            }
            else{
                tablica[i][kolumna-1]=0;
            }
        }
}

if (kolumna==1){   
    if(tablica[wiersz-1][kolumna]==0){
        tablica[wiersz-1][kolumna]=1;
    }
    else{
        tablica[wiersz-1][kolumna]=0;
    }
}

else if(kolumna==kolumny){
        if(tablica[wiersz-1][kolumna-2]==0){
            tablica[wiersz-1][kolumna-2]=1;
        }
        else{
            tablica[wiersz-1][kolumna-2]=0;
        }
}

else{
    for (int i = kolumna-2; i <=kolumna; i+=2){
            if(tablica[wiersz-1][i]==0){
                tablica[wiersz-1][i]=1;
            }
            else{
                tablica[wiersz-1][i]=0;
            }
    }
}
}
}

void finish(int ctr){   //wyświetlenie napisów końcowych po ukończeniu gry
    printf("Brawo, wygrales w %d ruchach!", ctr);
}