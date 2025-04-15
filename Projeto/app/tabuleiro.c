#include "tabuleiro.h"

/*
Implementação dos comandos b <coordenadas>, r <coordenadas> e d 
 <coordenadas> - <letra minúscula><número>
*/

int cSpN(char *num, int t) { 
    int r = 0, aux, i = 0, j; 

    while (num[i] != '\0') {  
           aux = num[i] - '0';  
           
           for (j = t; j > 0; j--)  
                aux *= 10;
           
           r += aux;
           i++, t--;   
   }  

   return r; 
}

void pBranco(char *arg, TAB *jogo) {
     int x = arg[0] - 'a';
     int y = cSpN(arg + 1, strlen(arg + 1) - 1);
     
     if (x < 0 || x > jogo -> x || y < 0 || y > jogo -> y) {
         printf("Coordenadas invalidas\n\n");
    } else { 
         if (jogo -> tab[y][x].game >= 'A' && jogo -> tab[y][x].game<= 'Z') {
             printf("Coordenada já pintada\n\n");
         } else {
             jogo -> tab[y][x].game = jogo -> tab[y][x].orig - 32; 
         }
    }
}

void risca(char *arg, TAB *jogo) {
    int x = arg[0] - 'a';
    int y = cSpN(arg + 1, strlen(arg + 1) - 1);
    
    if (x < 0 || x > jogo -> x || y < 0 || y > jogo -> y) {
        printf("Coordenadas invalidas\n\n");
    } else { 
        if (jogo -> tab[y][x].game == '#') {
            printf("Coordenada já riscada\n\n");
        } else {
            jogo -> tab[y][x].game = '#'; 
        }
    }     
}