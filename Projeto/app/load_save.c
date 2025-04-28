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

    jogo -> tab = NULL;
    jogo -> x   = 0;
    jogo -> y   = 0; 
}


void limpaS (stack *passos) {
    int i;
    
    for (i = 0; i < passos -> sp; i++) {
        limpaT(&passos -> tabs[i]); 
    }

    free(passos -> tabs);    
    
    passos -> tabs = NULL;
    passos -> cap  = 0;
    passos -> sp   = 0;
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


void lePassos(int x, int y, stack *passos, FILE *file) {
     int  i, j;
     char aux;
     
     for(passos -> sp = 0; passos -> sp < passos -> cap; passos -> sp ++) {
         passos -> tabs[passos -> sp].y = y;
         passos -> tabs[passos -> sp].x = x;
         passos -> tabs[passos -> sp].tab = malloc(y * sizeof(casa*));
         for (i = 0; i < y; i++) {
              passos -> tabs[passos -> sp].tab[i] = malloc(x * sizeof(casa));
              for (j = 0; j < x; j++) {
                   if (fscanf(file, " %c", &aux) == 1) {
                       passos -> tabs[passos -> sp].tab[i][j].game = aux;
                   }
              }
         }
     }
}


void load(char *arg, TAB *jogo, stack *passos) {
     char dir[100] = "Inputs/"; 
     strcat(dir, arg);
     
     if (passos -> tabs != NULL) limpaS(passos);

     FILE *file = fopen(dir, "r"); 
     if (file == NULL) {
         printf("ERRO: Ficheiro ´%s´ não encontrado\n\n", arg);
     } else {
         leJogo(jogo, file);

         int x, y, t;
         x = jogo -> x;
         y = jogo -> y;
    
         if(fscanf(file, "%d", &t) == 1) {
            passos -> cap  = t;
            passos -> sp   = 0;
            passos -> tabs = malloc(passos -> cap * sizeof(TAB));
    
            lePassos(x, y, passos, file);
         }

         fclose(file); 
     }
}


void save(char *arg, TAB *jogo, stack *passos) {
    int i, j, k;
    char dir[100] = "Inputs/";
    strcat(dir, arg);

    FILE *file = fopen(dir, "w");
    if (file == NULL) {
        printf("ERRO: Não foi possível gravar no ficheiro ´%s´\n\n", arg);
    } else {
        fprintf(file, "%d %d\n", jogo->y, jogo->x);

        // Original
        for (i = 0; i < jogo -> y; i++) {
            for (j = 0; j < jogo -> x; j++) {
                fprintf(file, "%c", jogo->tab[i][j].orig);
            }
            fprintf(file, "\n");
        } 

        // Jogo
        for (i = 0; i < jogo -> y; i++) {
            for (j = 0; j < jogo -> x; j++) {
                fprintf(file, "%c", jogo->tab[i][j].game);
            }
            fprintf(file, "\n");
        }
        
        fprintf(file, "%d\n", passos -> sp);

        // Stack
        for (k = 0; k < passos -> sp; k++) {
            for (i = 0; i < jogo -> y; i++) {
                for (j = 0; j < jogo -> x; j++) {
                    fprintf(file, "%c", passos -> tabs[k].tab[i][j].game);
                }
                fprintf(file, "\n");
            }
        }

        fclose(file);
        printf("Tabuleiro gravado em ´%s´ com sucesso\n\n", arg);
    }
}
