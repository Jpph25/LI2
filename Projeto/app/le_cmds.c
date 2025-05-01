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


void lecmd(char cmd, char *arg, int *end, int *l, TAB *jogo, stack *passos, int i) {
     int t, p = 1;

     if (i) putchar('\n');

     if (cmd == 'b' && *l)  { 
         if (strlen(arg) == 1) { 
             if (i) printf("Erro: Comando Invalido\n\n"); 
         } else {
             guarda(jogo, passos), pBranco(arg, jogo, &i);
             if (i) pTab(jogo);
             if(tabIguais(&passos -> tabs[passos -> sp - 1], jogo)) rGuardar(passos);
         }
     } else if (cmd == 'b') { 
         if (i) printf("Erro: Nenhum tabuleiro encontrado.\n\n"); 
     }


     if (cmd == 'r' && *l)  { 
         if (strlen(arg) == 1) { 
             if (i) printf("Erro: Comando Invalido\n\n"); 
         } else {
             guarda(jogo, passos), risca(arg, jogo, &i);
             if (i) pTab(jogo);
             if(tabIguais(&passos -> tabs[passos -> sp - 1], jogo)) rGuardar(passos);
         }
     } else if (cmd == 'r') { 
         if (i) printf("Erro: Nenhum tabuleiro encontrado.\n\n"); 
     }


     if (cmd == 'd' && *l)  { 
         retorna(jogo, passos, &i); 
         if (i) pTab(jogo);
     } else if (cmd == 'd') { 
         if (i) printf("Erro: Nenhum tabuleiro encontrado.\n\n");
     }


     if (cmd == 'a' && *l)  { 
         guarda(jogo, passos) , t = dicas(jogo);
         if (t == 0) {
             rGuardar(passos); 
             if (i) printf ("Não há dicas possíveis.\n\n");
         }
         if (i) pTab(jogo);
     } else if (cmd == 'a') { 
         if (i) printf("Erro: Nenhum tabuleiro encontrado.\n\n");
     }


     if (cmd == 'A' && *l)  { 
         guarda(jogo, passos) , t = Dicas(jogo); 
         if (t == 0) {
             rGuardar(passos);
             if (i) printf ("Não há dicas possíveis.\n\n");
         }
         if (i) pTab(jogo);
     } else if (cmd == 'A') { 
         if (i) printf("Erro: Nenhum tabuleiro encontrado.\n\n"); 
     }


     if (cmd == 'v' && *l)  {
         t = verifica(jogo, &p);
         if (t == 1) printf("Tabuleiro válido.\n\n");
         if (i) pTab(jogo);
     } else if (cmd == 'v') { 
         if (i) printf("Erro: Nenhum tabuleiro encontrado.\n\n"); 
     }


     if (cmd == 'R' && *l)  { 
         guarda(jogo, passos), t = resolve(jogo, &i); 
         if (t == 0) {
             rGuardar(passos);
             if (i) printf("Tabuleiro já resolvido.\n\n");
         }
         if (i) pTab(jogo);
     } else if (cmd == 'R') { 
         if (i) printf("Erro: Nenhum tabuleiro encontrado.\n\n"); 
     }


     if (cmd == 'g' && *l)  { save(arg, jogo, passos, &i);
     } else if (cmd == 'g') { 
         if (i) printf("Erro: Nenhum tabuleiro encontrado.\n\n"); 
     }


     if (cmd == 'l') { 
         t = load(arg, jogo, passos, &i); 
         if (t) {*l = 1; if (i) pTab(jogo);}
     }

     
     if (cmd == 's') *end = 0; 
}
