#include "load_save.h"

/*
Implementação da funão que lê os comandos dados
l jogo, g jogo, b <coordenadas>, r <coordenadas>, d, s, v, a, A e R
  <coordenadas> - <letra minúscula><número>
  jogo - nome do ficheiro a dar `load` e `save`
*/

void pTab(TAB *jogo); 

void lecmd(char cmd, char *arg, int *end, int *l, TAB *jogo);