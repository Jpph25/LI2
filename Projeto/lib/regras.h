#include "load_save.h" 

/*
Implementação do comando v
*/


/* Regras: 
Regra das riscadas - 
 À volta das casas riscadas todas as casas têm de ser pintadas (não pode haver dois '#' seguidos);
Regra das brancas  -
 Em cada linha e coluna só pode haver uma letra pintada de cada tipo;
Regra do caminho   -
 Tem de ter um caminho ortogonal entre todas as casas pintadas;   
*/



void rRiscadas(int x, int y, TAB *jogo);
/*
Verifica se a regra das riscadas é obdecida
  - y    , coordenada da casa a ser verificada;
  - x    , coordenada da casa a ser verificada;
  - *jogo, tabuleiro do jogo;
*/


void rBrancas (int x, int y, char c, TAB *jogo);
/*
Verifica se a regra das riscadas é obdecida
  - y    , coordenada da casa a ser verificada;
  - x    , coordenada da casa a ser verificada;
  - c    , caracter da casa a ser verificada;
  - *jogo, tabuleiro do jogo;
*/


void verifica(TAB *jogo); 
/*
Verifica se o tabuleiro do jogo obdece a todas as regras 
  - *jogo, tabuleiro do jogo;
*/
