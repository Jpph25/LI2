#include "solve.h" 

/*
Implementação dos comando R 
*/


void unica(int x, int y, char c, TAB *jogo) {
     int i, cont = 0; 

     for (i = 1; y + i < jogo -> y; i++) {
          if (jogo -> tab[y + i][x].orig == c) {
              cont ++;
          }
     }

     for (i = 1; y - i >= 0; i++) {
          if (jogo -> tab[y - i][x].orig == c) {
              cont ++;
          }
     }

     for (i = 1; x + i < jogo -> x; i++) {
          if (jogo -> tab[y][x + i].orig == c) {
              cont ++;
          }
     }

     for (i = 1; x - i >= 0; i++) {
          if (jogo -> tab[y][x - i].orig == c) {
              cont ++;
          }
     }
     
     if (cont == 0) jogo -> tab[y][x].game = jogo -> tab[y][x].orig - 32; 
}


void unicas(TAB *jogo) {
     int i, j;  
     char c;

     for (i = 0; i < jogo -> y; i++) {
          for (j = 0; j < jogo -> x; j++) {
               c = jogo -> tab[i][j].orig;
               unica(j , i, c, jogo);
          }
     }
}


void resolve(TAB *jogo) {
     int p = 0;  

     if (!verifica(jogo, &p)) printf("Tabuleiro atual invalido.\n");

     unicas(jogo);
}
