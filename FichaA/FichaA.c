// -- FichaA --

#include <stdio.h>
#include <assert.h> 

/* InPut:
- Uma linha com um número N, correspondendo a quantos fatores deve ler;
- N linhas contendo cada uma:
    - Uma letra maiúscula, e
    - Um número inteiro positivo K
- Uma linha contendo dois inteiros positivos I e F
*/

/* OutPut: 
Programa que imprimir N linhas, correspondendo a cada uma das linhas que leu no input e deve imprimir, 
por ordem alfabética, a letra e o número de múltiplos de K entre os valores de I e F.
*/

// Compilar : -Wall -Wextra -pedantic -O2 

// não ordena as letras por ordem alfabética 

typedef struct {
        char letra;
        int  num;  
} Fator;

void leFatores (int N, Fator fs[]) {
     int i;
     for (i = 0; i < N; i++)
         assert(scanf ("%c %d\n", &fs[i].letra, &fs[i].num) == 2); 
}

void contMults (int N, int m, int M, Fator fs[], int cont[]) {
     int i, j;
     for (i = m; i <= M; i++) {
         for (j = 0; j < N; j++) {
             if (i % fs[j].num == 0) cont[j]++;  
         }
     } 
}

void result (int N, Fator fs[], int cont[]) {
     int i; 
     for (i = 0; i < N; i++) {
         printf ("%c %d\n", fs[i].letra, cont[i]);
     }
}

int main () {

    int N; 
    assert (scanf ("%d\n", &N) == 1); 

    Fator fatores[N]; 
    leFatores (N, fatores); 

    int m, M;  
    assert (scanf ("%d %d", &m, &M) == 2); 

    int i, cont[N];
    for (i = 0; i < N; i++) cont[i] = 0; 
    contMults (N, m, M, fatores, cont); 

    result (N, fatores, cont); 

    return 0;
}
