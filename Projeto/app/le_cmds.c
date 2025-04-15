#include "le_cmds.h"

/*
Implementação da funão que lê os comandos dados
l jogo, g jogo, b <coordenadas>, r <coordenadas>, d, s, v, a, A e R
  <coordenadas> - <letra minúscula><número>
  jogo - nome do ficheiro a dar `load` e `save`
*/

void pTab(TAB *jogo) {
  int i, j;

  for (i = 0; i < jogo -> y; i++) {
     
       for (j = 0; j < jogo -> x; j++) {
            printf ("%c ", jogo -> tab[i][j].game); 
       }
       putchar('\n');
  }
  putchar('\n');
}

void lecmd(char cmd, char *arg, int *end, int *l, TAB *jogo) {
     if (cmd == 'b' && *l) { pBranco(arg, jogo), pTab(jogo);
     } else if (cmd == 'b') { printf("Nenhum tabuleiro encontrado.\n\n"); }

     if (cmd == 'r' && *l) { risca(arg, jogo)  , pTab(jogo);
     } else if (cmd == 'r') { printf("Nenhum tabuleiro encontrado.\n\n"); }

     if (cmd == 'l') load(arg, jogo), *l = 1, pTab(jogo); 
     
     if (cmd == 's') *end = 0;       
}
