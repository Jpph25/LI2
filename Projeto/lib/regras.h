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


void push(int x, int y, CP *pintadas);
/*
Acrescenta a coordenada de uma casa branca á lista das casas brancas
  - x        , Linha da casa branca
  - y        , Coluna da casa branca
  - *pintadas, local onde são guardadas as coordenadas das casas brancas
*/

void pintadas(CP *pintadas, TAB *jogo);
/*
Cria uma lista com todas as casas brancas
  - *pintadas, local onde são guardadas as coordenadas das casas brancas
  - *jogo    , tabuleiro do jogo
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
