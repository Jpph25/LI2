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

     putchar('\n');

     if (cmd == 'b' && *l)  { 
         if (strlen(arg) == 1) { printf("Erro: Comando Invalido\n\n"); 
         } else {
             guarda(jogo, passos) , pBranco(arg, jogo), pTab(jogo);
             if(tabIguais(&passos -> tabs[passos -> sp - 1], jogo)) rGuardar(passos);
         }
     } else if (cmd == 'b') { printf("Erro: Nenhum tabuleiro encontrado.\n\n"); }


     if (cmd == 'r' && *l)  { 
         if (strlen(arg) == 1) { printf("Erro: Comando Invalido\n\n"); 
         } else {
             guarda(jogo, passos) , risca(arg, jogo)  , pTab(jogo);
             if(tabIguais(&passos -> tabs[passos -> sp - 1], jogo)) rGuardar(passos);
         }
     } else if (cmd == 'r') { printf("Erro: Nenhum tabuleiro encontrado.\n\n"); }


     if (cmd == 'd' && *l)  { retorna(jogo, passos), pTab(jogo);
     } else if (cmd == 'd') { printf("Erro: Nenhum tabuleiro encontrado.\n\n"); }


     if (cmd == 'a' && *l)  { 
         guarda(jogo, passos) , t = dicas(jogo);
         if (t == 0) rGuardar(passos), printf ("Não há dicas possíveis.\n\n");
         pTab(jogo);
     } else if (cmd == 'a') { printf("Erro: Nenhum tabuleiro encontrado.\n\n"); }


     if (cmd == 'A' && *l)  { 
         guarda(jogo, passos) , t = Dicas(jogo); 
         if (t == 0) rGuardar(passos), printf ("Não há dicas possíveis.\n\n");
         pTab(jogo);
     } else if (cmd == 'A') { printf("Erro: Nenhum tabuleiro encontrado.\n\n"); }


     if (cmd == 'v' && *l)  {
         t = verifica(jogo, &p);
         if (t == 1) printf("Tabuleiro válido.\n\n");
         pTab(jogo);
     } else if (cmd == 'v') { printf("Erro: Nenhum tabuleiro encontrado.\n\n"); }


     if (cmd == 'R' && *l)  { 
         guarda(jogo, passos), t = resolve(jogo); 
         if (t == 0) rGuardar(passos), printf("Tabuleiro já resolvido.\n\n");
         pTab(jogo);
     } else if (cmd == 'R') { printf("Erro: Nenhum tabuleiro encontrado.\n\n"); }


     if (cmd == 'g' && *l)  { save(arg, jogo, passos);
     } else if (cmd == 'g') { printf("Erro: Nenhum tabuleiro encontrado.\n\n"); }


     if (cmd == 'l') load(arg, jogo, passos), *l = 1, pTab(jogo);
     

     if (cmd == 's') *end = 0; 
}
