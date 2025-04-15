#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*
Implementação dos comandos b <coordenadas>, r <coordenadas> e d 
 <coordenadas> - <letra minúscula><número>
*/

// Tipo de cada casa de um tabuleiro
typedef struct{
        char orig; // Casa original
        char game; // Casa a ser modificada
} casa;

// Tipo do tabuleiro
typedef struct{
        int x;      // Numero de colunas 
        int y;      // Numero de linhas 
        casa **tab; // Tabuleiro  
} TAB; 

int cSpN(char *num, int t);
/*
Converte uma string em um inteiro
  - *num, parte da sting do argumento que é um numero
  - t   , tamanho da string com o numero
  
  - retorna o numeoro na string na forma de um inteiro
*/

void pBranco(char *arg, TAB *jogo);
/*
Pinta uma dada casa `arg` de Branco, transforma a letra minuscula da casa em uma maiscula
  - *arg , string do argumento dado pelo usoário (coordenadas)
  - *jogo, tabuleiro do jogo
*/

void risca(char *arg, TAB *jogo);
/*
Risca uma dada casa `arg`, transforma a letra em um cardinal (#)
  - *arg , string do argumento dado pelo usuário (coordenadas)
  - *jogo, tabuleiro do jogo
*/