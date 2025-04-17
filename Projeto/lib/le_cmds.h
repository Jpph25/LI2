#include "tabuleiro.h"

/*
Implementação da funão que lê os comandos dados
l jogo, g jogo, b <coordenadas>, r <coordenadas>, d, s, v, a, A e R
  <coordenadas> - <letra minúscula><número>
  jogo - nome do ficheiro a dar `load` e `save`
*/


void pTab(TAB *jogo); 
/*
Desenha o tabuleiro que está a ser jogado.
  - *jogo, tabuleiro do jogo
*/


void lecmd(char cmd, char *arg, int *end, int *l, TAB *jogo, stack *passos);
/*
  - cmd    , carater do comando passado pelo usoário
  - *arg   , argumento passado pelo usoário
  - *end   , indica se é para continuar a ler comandos 
  - *l     , indica se o tabuleiro está iniciado
  - *jogo  , tabuleiro do jogo
  - *passos, guarda as jogadas do usuario

Lê os comandos usados pelo usuario:
  - b, pinta uma dada casa de branco;
  - r, risca uma dada casa;
  - d, volta á jogada anterior;
  - l, dá load ao jogo de um dado ficheiro;
  - s, sai do jogo;
*/