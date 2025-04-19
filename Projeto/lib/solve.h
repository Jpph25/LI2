#include "dicas.h"

/*
Implementação dos comando R 
*/

/*
Criterios para solução: 
  - Letras únicas numa coluna e linha;
  - Letras maiusculas nas esquinas;
*/


void unica(int x, int y, char c, TAB *jogo);
/*
verifica se um carater é unico na sua linha e coluna
  - x    , coluna da casa;
  - y    , linha da casa;
  - c    , caracter da casa;
  - *jogo, tabuleiro do jogo;
*/


void unicas(TAB *jogo);
/*
Percorre todas as casas de um tabuleiro e verifica se é um carater unico na sua linha e coluna
  - *jogo, tabuleiro do jogo;
*/


void resolve(TAB *jogo);
/*
Resolve um dado tabuleiro 
  - *jogo, tabuleiro do jogo;
*/
