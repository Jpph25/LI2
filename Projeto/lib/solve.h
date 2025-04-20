#include "dicas.h"

/*
Implementação dos comando R 
*/


void cpyTab(TAB *dest, TAB *font);
/*
Copia um dado tabuleiro para outro
  - *dest, tabuleiro para onde copiar;
  - *font, tabuleiro a copiar;
*/


int tabIguais(TAB *aux, TAB *jogo);
/*
Verifica se dois tabuleiros são iguais
  - *aux , tabueliro auxiliar;
  - *jogo, tabuleiro do jogo;

  - retorna um inteiro que indica se os tabuleiros são iguais;
    - 1, iguais;
    - 0, diferentes;
*/


void minTmai(TAB *jogo, int *r);
/*
Torna maisuculas todas as letras minusculas do tabuleiro
  - *jogo, tabuleiro de jogo;
  - *r   , indica se houve alguma alteração no tabuleiro;
*/


void adjacentes(int x, int y, char c, TAB *jogo, int *r);
/*
Risca uma casa adjacente com o mesmo carater resolve e verifica se o tabuleiro é valido se não volta atrás
  - x    , coluna;
  - y    , linha;
  - c    , carater da casa;
  - *jogo, tabuleiro de jogo;
  - *r   , indica se houve alguma alteração no tabuleiro;
*/


void unica(int x, int y, char c, TAB *jogo, int *r);
/*
verifica se um carater é unico na sua linha e coluna
  - x    , coluna da casa;
  - y    , linha da casa;
  - c    , caracter da casa;
  - *jogo, tabuleiro do jogo;
  - *r   , indica se houve alguma alteração no tabuleiro;
*/


void percorre(TAB *jogo, int * r);
/*
Percorre todas as casas de um tabuleiro
  - *jogo, tabuleiro do jogo;
  - *r   , indica se houve alguma alteração no tabuleiro;
*/


int resolve(TAB *jogo);
/*
Resolve um dado tabuleiro 
  - *jogo, tabuleiro do jogo;

  - retorna um inteiro que indica se houve alguma alteração no tabuleiro
    - 0, não houve alterações;
    - 1, houve alterações;
*/
