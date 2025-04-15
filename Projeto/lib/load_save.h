#include "tabuleiro.h"

/*
Implementação dos comandos l jogo e g jogo
 jogo - nome do ficheiro a dar `load` e `save`
*/

void leTab(TAB *jogo, FILE *file); 
/*
Lê o tabuleiro de um dado ficheiro
  - *jogo, tabuleiro do jogo
  - *file, ficheiro de onde vai ser lido o tabuleiro
*/

void leJogo(TAB *jogo, FILE *file); 
/*
Se houver um jogo já iniciado liberta o espaço ocupado pelo jogo
Libera o espaço necessario para guardar o novo tabuleiro 
  - *jogo, tabuleiro do jogo
  - *file, ficheiro de onde vai ser lido o tabuleiro
*/

void load(char *arg, TAB *jogo);
/*
Cria o caminho pra o ficheiro de onde vão ser lidos os tabuleiros
  - *arg , string do argumento dado pelo usuário (nome do ficheiro a abrir)
  - *jogo, tabuleiro do jogo
*/