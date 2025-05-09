#include "solve.h"

/*
Implementação dos comandos b <coordenadas>, r <coordenadas> e d 
 <coordenadas> - <letra minúscula><número>
*/


int cSpN(char *num, int t);
/*
Converte uma string em um inteiro
  - *num, parte da sting do argumento que é um numero;
  - t   , tamanho da string com o número;
  
  - retorna o número na string na forma de um inteiro;
*/


void pBranco(char *arg, TAB *jogo, int *p);
/*
Pinta uma dada casa `arg` de Branco, transforma a letra minuscula da casa em uma maiscula
  - *arg , string do argumento dado pelo usuário (coordenadas);
  - *jogo, tabuleiro do jogo;
  - *p   , indica se é para imprimir coisas;
*/


void risca(char *arg, TAB *jogo, int *p);
/*
Risca uma dada casa `arg`, transforma a letra em um cardinal (#)
  - *arg , string do argumento dado pelo usuário (coordenadas);
  - *jogo, tabuleiro do jogo;
  - *p   , indica se é para imprimir coisas;
*/


void guarda(TAB *jogo, stack *passos);
/*
Guarda o tabuleiro da jogada anterior
  - *jogo  , tabuleiro do jogo;
  - *passos, stack que guarda os tabuleiros anteriores;
*/


void retorna(TAB *jogo, stack *passos, int *p);
/*
Volta ao tabuleiro anterior
  - *jogo  , tabuleiro do jogo;
  - *passos, stack que guarda os tabuleiros anteriores;
  - *p     , indica se é para imprimir coisas;
*/
