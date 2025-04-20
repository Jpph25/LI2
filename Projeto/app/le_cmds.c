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


void rGuardar(stack *passos) {
     int i = passos -> sp - 1;

     if (passos -> sp != 0) {
         limpaT(&passos -> tabs[i]);
         passos -> sp --;
     }
}


void lecmd(char cmd, char *arg, int *end, int *l, TAB *jogo, stack *passos) {
     int t, p = 1;

     if (cmd == 'b' && *l)  { guarda(jogo, passos) , pBranco(arg, jogo), pTab(jogo);
     } else if (cmd == 'b') { printf("Nenhum tabuleiro encontrado.\n\n"); }

     if (cmd == 'r' && *l)  { guarda(jogo, passos) , risca(arg, jogo)  , pTab(jogo);
     } else if (cmd == 'r') { printf("Nenhum tabuleiro encontrado.\n\n"); }

     if (cmd == 'd' && *l)  { retorna(jogo, passos), pTab(jogo);
     } else if (cmd == 'd') { printf("Nenhum tabuleiro encontrado.\n\n"); }

     if (cmd == 'a' && *l)  { 
         guarda(jogo, passos) , t = dicas(jogo), pTab(jogo);
         if (t == 0) rGuardar(passos), printf ("Não há dicas possíveis.\n");;
     } else if (cmd == 'a') { printf("Nenhum tabuleiro encontrado.\n\n"); }

     if (cmd == 'A' && *l)  { 
         guarda(jogo, passos) , t = Dicas(jogo), pTab(jogo);
         if (t == 0) rGuardar(passos), printf ("Não há dicas possíveis.\n");
     } else if (cmd == 'A') { printf("Nenhum tabuleiro encontrado.\n\n"); }

     if (cmd == 'v' && *l)  {
         t = verifica(jogo, &p), pTab(jogo);
         if (t == 1) printf("Tabuleiro válido.\n");
     } else if (cmd == 'v') { printf("Nenhum tabuleiro encontrado.\n\n"); }

     if (cmd == 'R' && *l)  { 
         guarda(jogo, passos), t = resolve(jogo), pTab(jogo);
         if (t == 0) rGuardar(passos), printf("Tabuleiro já resolvido.\n");
     } else if (cmd == 'R') { printf("Nenhum tabuleiro encontrado.\n\n"); }

     if (cmd == 'g' && *l)  { save(arg, jogo);
     } else if (cmd == 'g') { printf("Nenhum tabuleiro encontrado.\n\n"); }

     if (cmd == 'l') load(arg, jogo), *l = 1, pTab(jogo);
     
     if (cmd == 's') *end = 0; 
}
