#include "regras.h"

/*
Implementação do comando v
*/

void rRiscadas(int x, int y, TAB *jogo) {

     if (y + 1 < jogo -> y && jogo -> tab[y + 1][x].game == '#') {  
         printf ("A coordenada (%d, %d) infringe a regra das riscadas (a coordenada abaixo está riscada).\n", x, y); 
     }

     if (x + 1 < jogo -> x && jogo -> tab[y][x + 1].game == '#') {
         printf ("A coordenada (%d, %d) infringe a regra das riscadas (a coordenada à direita está riscada).\n", x, y);
     }

     if (y - 1 >= 0 && jogo -> tab[y - 1][x].game == '#') { 
         printf ("A coordenada (%d, %d) infringe a regra das riscadas (a coordenada acima está riscada).\n", x, y);
     }

     if (x - 1 >= 0 && jogo -> tab[y][x - 1].game == '#') {
         printf ("A coordenada (%d, %d) infringe a regra das riscadas (a coordenada à esquerda está riscada).\n", x, y);
     }
}


void rBrancas (int x, int y, char c, TAB *jogo) {
     int i, v = 1;
    
     for (i = 1; v && y + i < jogo -> y; i++) {
          if(jogo -> tab[y + i][x].game == c) {
             v = 0;
             printf("A coordenada (%d, %d) infringe a regra das brancas (existe outro %c na coluna).\n", x, y, c);
          }
     }

     for (i = 1; v && y - i >= 0; i++) {
          if(jogo -> tab[y - i][x].game == c) {
             v = 0;
             printf("A coordenada (%d, %d) infringe a regra das brancas (existe outro %c na coluna).\n", x, y, c);
          }
     }

     v = 1;

     for (i = 1; v && x + i < jogo -> x; i++) {
          if(jogo -> tab[y][x + i].game == c) {
             v = 0;
             printf("A coordenada (%d, %d) infringe a regra das brancas (existe outro %c na linha).\n", x, y, c);
          }
     }

     for (i = 1; v && x - i >= 0; i++) {
          if(jogo -> tab[y][x - i].game == c) {
             v = 0;
             printf("A coordenada (%d, %d) infringe a regra das brancas (existe outro %c na linha).\n", x, y, c);
          }
     }
}


void verifica(TAB *jogo) {
     int i, j; 
    
     for(i = 0; i < jogo -> y; i++) {
          for(j = 0; j < jogo -> x; j++) {
              if (jogo -> tab[i][j].game == '#') 
                  rRiscadas(j, i, jogo);
              if (jogo -> tab[i][j].game >= 'A' && jogo -> tab[i][j].game <= 'Z')
                  rBrancas(j, i, jogo -> tab[i][j].game, jogo);  
          } 
     }

     putchar('\n');
}
