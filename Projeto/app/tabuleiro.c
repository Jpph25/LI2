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


void pBranco(char *arg, TAB *jogo, int *p) {
     int x = arg[0] - 'a';
     int y = cSpN(arg + 1, strlen(arg + 1) - 1);
     
     if (x < 0 || x >= jogo -> x || y < 0 || y >= jogo -> y) {
         if (*p) printf("Erro: Coordenadas invalidas\n\n");
     } else { 
         if (jogo -> tab[y][x].game >= 'A' && jogo -> tab[y][x].game<= 'Z') {
             if (*p) printf("Coordenada já pintada\n\n");
         } else {
             jogo -> tab[y][x].game = jogo -> tab[y][x].orig - 32; 
         }
     }
}


void risca(char *arg, TAB *jogo, int *p) {
    int x = arg[0] - 'a';
    int y = cSpN(arg + 1, strlen(arg + 1) - 1);
    
    if (x < 0 || x >= jogo -> x || y < 0 || y >= jogo -> y) {
        if (*p) printf("Erro: Coordenadas invalidas\n\n");
    } else { 
        if (jogo -> tab[y][x].game == '#') {
            if (*p) printf("Coordenada já riscada\n\n");
        } else {
            jogo -> tab[y][x].game = '#'; 
        }
    }     
}


void guarda(TAB *jogo, stack *passos) {

     if (passos -> cap == 0) {
         passos -> tabs = malloc(sizeof (TAB));
         passos -> cap  = 1; 
     } 
     
     if (passos -> cap == passos -> sp && passos -> cap != 0) { 
         passos -> tabs = realloc (passos -> tabs, 2 * passos -> cap * sizeof(TAB));
         passos -> cap *= 2;  
     }

     passos -> tabs[passos -> sp].x = jogo -> x; 
     passos -> tabs[passos -> sp].y = jogo -> y;

     passos -> tabs[passos -> sp].tab = malloc(jogo -> y * sizeof(casa*));
     for (int i = 0; i < jogo -> y; i++) {
          passos -> tabs[passos -> sp].tab[i] = malloc(jogo -> x * sizeof(casa));
     }

     cpyTab(&passos -> tabs[passos -> sp], jogo);
     passos -> sp ++; 
}


void retorna(TAB *jogo, stack *passos, int *p) {
     int i = passos -> sp - 1;

     if (passos -> sp == 0) {
         if (*p) printf("Não é possível retroceder.\n\n");
     } else {

         jogo -> x = passos -> tabs[i].x;
         jogo -> y = passos -> tabs[i].y; 
         cpyTab(jogo, &passos -> tabs[i]);

         limpaT(&passos -> tabs[i]);
         passos -> sp --;
     }
}
