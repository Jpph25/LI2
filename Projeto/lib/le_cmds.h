#include "tabuleiro.h"

/*
Implementação da funão que lê os comandos dados
l jogo, g jogo, b <coordenadas>, r <coordenadas>, d, s, v, a, A e R
  <coordenadas> - <letra minúscula><número>
  jogo - nome do ficheiro a dar `load` e `save`
*/


void pTab(TAB *jogo); 
/*
Desenha o tabuleiro que está a ser jogado
  - *jogo, tabuleiro do jogo;
*/


void rGuardar(stack *passos);
/*
Apaga o ultimo passo(tabuleiro) guardado
  - *passos, guarda as jogadas do usuario;
*/


void lecmd(char cmd, char *arg, int *end, int *l, TAB *jogo, stack *passos, int i);
/*
  - cmd    , carater do comando passado pelo usoário;
  - *arg   , argumento passado pelo usoário;
  - *end   , indica se é para continuar a ler comandos; 
  - *l     , indica se o tabuleiro está iniciado;
  - *jogo  , tabuleiro do jogo;
  - *passos, guarda as jogadas do usuario;
  - i      , indica se é para imprimir coisas;

Lê os comandos usados pelo usuario:
  - b, pinta uma dada casa de branco;
  - r, risca uma dada casa;
  - d, volta á jogada anterior;
  - v, verifica se o tabuleiro é valido;
  - a, dá dicas ao usuario para resolver o tabuleiro;
  - A, dá dicas ao usuario até não ser mais possivel faze-lo;
  - R, resolve o tebuleiro automaticamente;
  - l, dá load ao jogo de um dado ficheiro;
  - g, grava o jogo em um ficheiro;
  - s, sai do jogo;
*/