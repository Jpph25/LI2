#include "le_cmds.h"

/*
Implementação da funão que lê os comandos dados
l jogo, g jogo, b <coordenadas>, r <coordenadas>, d, s, v, a, A e R
  <coordenadas> - <letra minúscula><número>
  jogo - nome do ficheiro a dar `load` e `save`
*/

void pTab(TAB *jogo) {
  int i, j;

  putchar('\n');
  for (i = 0; i < jogo -> y; i++) {
     
       for (j = 0; j < jogo -> x; j++) {
            printf ("%c ", jogo -> tab[i][j].game); 
       }
       putchar('\n');
  }
}

void lecmd(char cmd, char *arg, int *end, int *l, TAB *jogo) {
     if (cmd == 'l') load(arg, jogo), l = 0, pTab(jogo); 
     if (cmd == 's') *end = 0;       
}