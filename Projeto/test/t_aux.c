#include "t_aux.h"

/*
Funções auxiliares para os testes
*/

void pT(TAB *jogo) {
    int i, j;
  
    putchar('\n');

    for (i = 0; i < jogo -> y; i++) {
       
         for (j = 0; j < jogo -> x; j++) {
              printf ("%c ", jogo -> tab[i][j].game); 
         }
         putchar('\n');
    }
    putchar('\n');
}


// Tranforma uma string em um tabuleiro (Matriz)
void criaTab (TAB *jogo, char *tab) {
    int i, j;

    for (i = 0; i < jogo -> y; i++) 
         for (j = 0; j < jogo -> x; j++) {
              jogo -> tab[i][j].orig = tab[i * jogo -> x + j];
              jogo -> tab[i][j].game = tab[i * jogo -> x + j];

         }
}