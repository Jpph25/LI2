#include "regras.h"

/*
Implementação dos comandos a e A 
*/

/*
Dicas possiveis: 
- riscar todas as letras iguais a uma letra branca na mesma linha e/ou coluna;
- pintar de branco todas as casas vizinhas de uma casa riscada;
- pintar de branco uma casa quando seria impossível que esta fosse riscada por isolar casas brancas;
*/

void dNisolados(int x, int y, TAB *aux, TAB *jogo, int *r);
/*
Pinta a unica casa adjacente a um dado ponto que não está fora dos limites ou um '#'
  - x    , coluna do ponto;
  - y    , linha do ponto;
  - *aux , tabuleiro sem mudanças;
  - *jogo, tabuleiro do jogo;
  - *r   , indica se ouve alguma alteração no tabuleiro;  
*/


void vIsoladas(int x, int y, TAB *aux, TAB *jogo, int *r);
/*
Verifica se uma dada casa do tabuleiro estão cercadas menos em um ponto
  - x    , coluna do ponto;
  - y    , linha do ponto;
  - *aux , tabuleiro sem mudanças;
  - *jogo, tabuleiro do jogo;
  - *r   , indica se ouve alguma alteração no tabuleiro;
*/


int isoladas(TAB *aux, TAB *jogo);
/*
Verifica se as casas do tabuleiro são pintadas
  - *aux , tabuleiro sem mudanças;
  - *jogo, tabuleiro do jogo;

  - retorna um iteiro que indica se ouve alguma alteração no tabuleiro;
    - 0, não houve alterações;
    - 1, houve alterações; 
*/


void dBrancas(int x, int y, char c, TAB *aux, TAB *jogo, int *r);
/*
Risca todas as casas em uma dada coluna e linha com a mesma letra que um dado carater
  - x    , coluna;
  - y    , linha;
  - c    , careter (letra minuscula) da casa (x, y);
  - *aux , tabuleiro sem mudanças;
  - *jogo, tabuleiro do jogo;
  - *r   , indica se ouve alguma alteração no tabuleiro;
*/


void dRiscadas(int x, int y, TAB *aux, TAB *jogo, int *r);
/*
Pinta de branco todas as casas adjacentes a uma casa riscada
  - x    , coluna do ponto;
  - y    , linha do ponto;
  - *aux , tabuleiro sem mudanças;
  - *jogo, tabuleiro do jogo;
  - *r   , indica se ouve alguma alteração no tabuleiro;
*/


int dicas(TAB *jogo);
/*
Dá dicas ao usuário seguindo as regras do jogo
  - *jogo, tabuleiro do jogo;

  - retorna um inteiro que indica se houve alguma alteração no tabuleiro
    - 0, não houve alterações;
    - 1, houve alterações;
*/


int Dicas(TAB *jogo);
/*
Dá dicas ao usuário seguindo as regras do jogo até não ser mais possivel 
(ou resolveu o problema ou houve um erro do usuário)
  - *jogo, tabuleiro do jogo;

  - retorna um inteiro que indica se houve alguma alteração no tabuleiro
    - 0, não houve alterações;
    - 1, houve alterações;
*/
