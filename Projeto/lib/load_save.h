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

void leJogo(TAB *jogo, FILE *file); 

void load(char *arg, TAB *jogo);