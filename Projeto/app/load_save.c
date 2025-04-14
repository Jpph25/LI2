#include "load_save.h"

/*
Implementação dos comandos l jogo e g jogo
 jogo - nome do ficheiro a dar `load` e `save`
*/

void leTab(TAB *jogo, FILE *file) {
     int  i, j;
     char aux;

     for (i = 0; i < jogo -> y; i++) {
         for (j = 0; j < jogo -> x; j++) {
               assert(fscanf(file, " %c", &aux) == 1);
               jogo -> tab[i][j].orig = aux;
               jogo -> tab[i][j].game = aux;  
         }
     } 
}  

void leJogo(TAB *jogo, FILE *file) {
     int i; 
     
     if (jogo -> tab != NULL) {
        for(i = 0; i < jogo -> y; i++) {
            free(jogo -> tab[i]);
        }
        free(jogo -> tab);
     }
     
     assert(fscanf(file, "%d %d", &jogo -> y, &jogo -> x) == 2);

     jogo -> tab = malloc(jogo -> y * sizeof(casa*));
     for(i = 0; i < jogo -> y; i++) {
         (jogo -> tab)[i] = malloc(jogo -> x * sizeof(casa)); 
     }

     leTab(jogo, file);
}

void load(char *arg, TAB *jogo) {
     char dir[100] = "Inputs/"; 
     strcat(dir, arg);
     
     FILE *file = fopen(dir, "r"); 
     assert(file != NULL);
     
     leJogo(jogo, file); 
}