#include "load_save.h"

/*
Implementação dos comandos l jogo e g jogo
 jogo - nome do ficheiro a dar `load` e `save`
*/

void limpaT (TAB *jogo) {
    int i;
    
    for (i = 0; i < jogo -> y; i++) {
        free(jogo -> tab[i]);
    }

    free(jogo -> tab);
}


void limpaS (stack *passos) {
    int i;
    
    for (i = 0; i < passos -> sp; i++) {
        limpaT(&passos -> tabs[i]); 
    }

    free(passos -> tabs);    
}


void leTab(TAB *jogo, FILE *file) {
     int  i, j, lt = 1;
     char aux;

     for (i = 0; i < jogo -> y; i++) {
         for (j = 0; j < jogo -> x; j++) {
               assert(fscanf(file, " %c", &aux) == 1);
               jogo -> tab[i][j].orig = aux;  
         }
     }
     
     for (i = 0; i < jogo -> y && lt; i++) {
          for (j = 0; j < jogo -> x; j++) {
               if (fscanf(file, " %c", &aux) == 1) {
                   jogo -> tab[i][j].game = aux;
               } else {
                    lt = 0;
               }   
          }
     }

     for (i = 0; i < jogo -> y && !lt; i++) {
          for (j = 0; j < jogo -> x && !lt; j++) {
               jogo -> tab[i][j].game = jogo -> tab[i][j].orig;
          }
     }
}  


void leJogo(TAB *jogo, FILE *file) {
     int i; 
     
     if (jogo->tab != NULL) {
         limpaT(jogo);
    } 
     
     assert(fscanf(file, "%d %d", &jogo -> y, &jogo -> x) == 2);

     jogo -> tab = malloc(jogo -> y * sizeof(casa*));
     for(i = 0; i < jogo -> y; i++) {
         jogo -> tab[i] = malloc(jogo -> x * sizeof(casa)); 
     }

     leTab(jogo, file);
}


void load(char *arg, TAB *jogo) {
     char dir[100] = "Inputs/"; 
     strcat(dir, arg);
     
     FILE *file = fopen(dir, "r"); 
     if (file == NULL) {
         printf("ERRO: Ficheiro %s não encontrado.", arg);
     } else {
         leJogo(jogo, file);
         fclose(file); 
     } 
}

void save(char *arg, TAB *jogo) {
    char dir[100] = "Inputs/";
    strcat(dir, arg);

    FILE *file = fopen(dir, "w");
    if (file == NULL) {
        printf("ERRO: Não foi possível gravar no ficheiro %s.\n", arg);
    } else {
        fprintf(file, "%d %d\n", jogo->y, jogo->x);

        for (int i = 0; i < jogo->y; i++) {
            for (int j = 0; j < jogo->x; j++) {
                fprintf(file, "%c", jogo->tab[i][j].orig);
            }
            fprintf(file, "\n");
        }

        for (int i = 0; i < jogo->y; i++) {
            for (int j = 0; j < jogo->x; j++) {
                fprintf(file, "%c", jogo->tab[i][j].game);
            }
            fprintf(file, "\n");
        }

        fclose(file);
        printf("Tabuleiro gravado em %s com sucesso.\n\n", arg);
    }
}
