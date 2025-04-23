#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*
Implementação dos comandos l jogo e g jogo
 jogo - nome do ficheiro a dar `load` e `save`
*/

// Tipo de cada casa de um tabuleiro
typedef struct{
  char orig; // Casa original
  char game; // Casa a ser modificada
} casa;


// Tipo do tabuleiro
typedef struct{
  int x     ; // Numero de colunas 
  int y     ; // Numero de linhas 
  casa **tab; // Tabuleiro  
} TAB; 


// Stack para guardar os passos feitos pelo usuario
typedef struct {
  int cap  ; // Maximo de elementos que podem ser guardados
  int sp   ; // Quantidade de elementos guardados 
  TAB *tabs; // Array onde os valores são guardados
} stack;


void limpaT (TAB *jogo); 
/*
Limpa um dado tabuleiro
  - *jogo, tabuleiro do jogo;
*/


void limpaS (stack *passos);
/*
Limpa uma dada stack
  - *passos, stack com os tabuleiros anteriores;
*/


void leTab(TAB *jogo, FILE *file); 
/*
Lê o tabuleiro de um dado ficheiro
  - *jogo, tabuleiro do jogo;
  - *file, ficheiro de onde vai ser lido o tabuleiro;
*/


void leJogo(TAB *jogo, FILE *file); 
/*
Se houver um jogo já iniciado liberta o espaço ocupado pelo jogo
Libera o espaço necessario para guardar o novo tabuleiro 
  - *jogo, tabuleiro do jogo;
  - *file, ficheiro de onde vai ser lido o tabuleiro;
*/


void lePassos(int x, int y, stack *passos, FILE *file); 
/*
Lê os passos anteriores de um tabuleiro guardado
  - x      , tamanho das linhas;
  - y      , tamanho das colunas;
  - *passos, stack com os tabuleiros anteriores;
  - *file  , ficheiro de onde vão ser lidos os ficheiros;
*/


void load(char *arg, TAB *jogo, stack *passos);
/*
Cria o caminho pra o ficheiro de onde vão ser lidos os tabuleiros
  - *arg   , string do argumento dado pelo usuário (nome do ficheiro a abrir);
  - *jogo  , tabuleiro do jogo;
  - *passos, stack com os tabuleiros anteriores;
*/


void save(char *arg, TAB *jogo, stack *passos);
/*
Guarda o tabuleiro do jogo atual em um dado ficheiro
  - *arg   , nome do ficheiro;
  - *jogo  , tabuleiro do jogo;
  - *passos, stack com os tabuleiros anteriores;
*/
