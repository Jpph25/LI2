#include "tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*
Implementação dos comandos l jogo e g jogo
 jogo - nome do ficheiro a dar `load` e `save`
*/

void leTab(TAB *jogo, FILE *file); 
/*
Lê o tabuleiro de um dado ficheiro
*/

void leJogo(TAB *jogo, FILE *file); 
/*
Se houver um jogo já iniciado liberta o espaço ocupado pelo jogo
Libera o espaço necessario para guardar o novo tabuleiro 
*/

void load(char *arg, TAB *jogo);
/*
Cria o caminho pra o ficheiro de onde vão ser lidos os tabuleiros
*/