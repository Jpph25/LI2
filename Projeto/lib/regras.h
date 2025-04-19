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

// Tipo que guarda as coordenadas de uma casa do tabuleiro
typedef struct {
        int x; // Linha
        int y; // Coluna 
} coord;


// Tipo que guarda as coordenadas das casas brancas
typedef struct {
        coord *brancas; // Coordenadas das casas brancas
        int sp;         // Ultimo elemento incializado
        int t;          // tamanho do array 
} CP; 


void limpaL (CP *lista);
/*
Liberta o espaço ocupado por uma lista
  - *lista, lista a libertar;
*/


void push(int x, int y, CP *lista);
/*
Acrescenta a coordenada de uma casa branca à lista das casas brancas
  - x        , Linha da casa branca;
  - y        , Coluna da casa branca;
  - *lista, local onde são guardadas as coordenadas das casas brancas;
*/


void brancas(CP *pintadas, TAB *jogo);
/*
Cria uma lista com todas as casas brancas
  - *pintadas, local onde são guardadas as coordenadas das casas brancas;
  - *jogo    , tabuleiro do jogo;
*/


int elem(int x, int y, CP *lista);
/*
Verifica se uma coordenada pertence a uma lista;
  - x     , coluna da casa;
  - y     , linha da casa;
  - *lista, lista;
*/


void hCaminho(int x, int y, TAB *jogo, CP *visitadas);
/*
Verifica se existe pelo menos um caminho entre todas as casas pintadas
  - x         , coluna da primeira casa branca;
  - y         , linha da primeira casa branca;
  - *jogo     , tabuleiro do jogo;
  - *visitadas, local onde são guardadas as coordenadas já visitadas;
*/


void elemB(CP *visitadas, CP *pintadas, TAB *jogo, int *r, int *p);
/*
Verifica se os elementos das pintadas estão todos presentes nas visitadas
  - *pintadas , local onde são guardadas as coordenadas das casas brancas; 
  - *visitadas, local onde são guardadas as coordenadas já visitadas;
  - *jogo     , tabuleiro do jogo; 
  - *r        , indica se o tabuleiro é válido;
  - *p        , indica se é para imprimir algo;
*/


void caminho(CP *pintadas, CP *visitadas, TAB *jogo, int *r, int *p);
/*
Verifica se existe o caminho entre todas as letras brancas
  - *pintadas , local onde são guardadas as coordenadas das casas brancas; 
  - *visitadas, local onde são guardadas as coordenadas já visitadas;
  - *jogo     , tabuleiro do jogo;
  - *r        , indica se o tabuleiro é válido;
  - *p        , indica se é para imprimir algo;
*/

void rRiscadas(int x, int y, TAB *jogo, int *r, int *p);
/*
Verifica se a regra das riscadas é obdecida
  - y    , coordenada da casa a ser verificada;
  - x    , coordenada da casa a ser verificada;
  - *jogo, tabuleiro do jogo;
  - *r   , indica se o tabuleiro é válido;
  - *p   , indica se é para imprimir algo;
*/


void rBrancas (int x, int y, char c, TAB *jogo, int *r, int *p);
/*
Verifica se a regra das riscadas é obdecida
  - y    , coordenada da casa a ser verificada;
  - x    , coordenada da casa a ser verificada;
  - c    , caracter da casa a ser verificada;
  - *jogo, tabuleiro do jogo;
  - *r   , indica se o tabuleiro é válido;
  - *p   , indica se é para imprimir algo;
*/


int verifica(TAB *jogo, int *p); 
/*
Verifica se o tabuleiro do jogo obdece a todas as regras 
  - *jogo, tabuleiro do jogo;
  - *p   , indica se é para imprimir algo;

  - retorna um inteiro que indica se o tabuleiro é válido ou não
    - 1, válido
    - 0, inválido
*/
