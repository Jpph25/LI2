// -- FICHA 1 --

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

void leFatores (int N, int fs[]) {
     int i;
     for (i = 0; i < N; i++) {
         char letra;
         int num;  
         assert (scanf ("%c %d\n", &letra, &num) == 2); 
         fs[letra - 'A'] = num;   
     }
}

void contMults (int m, int M, int fs[], int cont[]) {
     int i; 

     for (i = 0; i < 26; i++) {
         if (fs[i] > 0) {
            int comeco; 

            if (m % fs[i] == 0) 
               comeco = m; // m já é multiplo 
            else 
               comeco = m + (fs[i] - (m % fs[i])); // encontra o primeiro multiplo maior que 'm'
               
            if (comeco <= M) 
               cont[i] += (M - comeco) / fs[i] + 1;  // conta a quantidade de multiplos no intrevalo (+ pelo do comeco)
         }
     }
}

void result (int fs[], int cont[]) {
     int i; 
     for (i = 0; i < 26; i++) {
         if (fs[i] != 0) 
            printf ("%c %d\n", i + 'A', cont[i]);  
     }
} 

int main () {
    int N; 
    assert (scanf ("%d\n", &N) == 1); 

    int fatores[26] = {0};  
    leFatores (N, fatores); 

    int m, M;
    assert (scanf ("%d %d\n", &m, &M) == 2); 
    
    int cont[26] = {0}; 
    contMults (m, M, fatores, cont); 

    result (fatores, cont); 

    return 0;
}