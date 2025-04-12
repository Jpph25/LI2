// -- FICHA 2 -- 

#include <stdio.h> 
#include <assert.h>
#include <string.h>

// Problema de strings

/* Input 
Uma linha com o número de casos C;
C linhas, contendo cada uma um número N com entre 1 e 1000 algarismos e o tamanho S.
*/

/* Output
O seu programa deve imprimir C linhas, 
contendo cada uma delas o maior subproduto de S algarismos consecutivos do número N.
*/

// Compilar : -Wall -Wextra -pedantic -O2  

// Tipo Fator (Guarda uma string e um numero) 
typedef struct {
        char s[1000];
        int  num;    
} Fator; 

// Funções 

// Função que lê os fatores 
void lerFatores (int N, Fator fs[]) {
     int i; 

     for (i = 0; i < N; i++) {
         assert(scanf("%s %d", fs[i].s, &fs[i].num) == 2);  
     }
}

// Multiplica um algarismo por um numero em uma string 
void multS (char r[], char dig) {
    int d = dig - '0'; 
    int t = strlen(r); 
    int i, j = 0, n, m, resto = 0;
    char aux[2000]; // array que guarda o resultado invertido 

    if (d == 0) strcpy (r, "0"); 
    else {
        for (i = t - 1; i >= 0; i--) {
            n = r[i] - '0';
            m = n * d + resto; 
            aux[j] = (m % 10) + '0'; 
            resto  =  m / 10; 
            j++;  
        } 

        if (resto > 0) aux[j] = resto + '0', j++; 
        aux[j] = '\0'; 

        for (i = 0; i < j; i++) {
            r[i] = aux[j - 1 - i]; 
        }
        r[i] = '\0';
    }
}

// Função que multiplica os algarismos de um numeros pelos outros 
void mult (char num[], int t, char r[]) {
     int i;
     char aux[2000] = "1"; 

     for (i = 0; i < t; i ++) {
         multS (aux, num[i]); 
     }

     strcpy (r, aux);
}

// Função que verifica qual numero é maior 
int compS (char a[], char n[]) {
    int r;
    int la = strlen(a), ln = strlen(n); 

    if (la > ln) r = 1;  
    else {
          if (la < ln) r =  0;
          else r = strcmp(a, n);     
    } 

    return r; 
}

// Função que divide os numeros pelo tamanho pretendido e encontra a maior mutiplicação  
void divideS (Fator f, char r[]) {
    int i, j; 
    char max[2000] = "0"; 
    char m  [2000];  
    char aux[f.num + 1];    

    for (i = 0; f.s[i + f.num - 1] != '\0'; i++) {

        for (j = 0; j < f.num; j++) {
            aux [j] = f.s[j + i];   
        }  
        aux[f.num] = '\0'; 
        
        mult (aux, f.num, m);

        if (compS(m, max) > 0) strcpy (max, m);     
    } 

    strcpy (r, max); 
}

// -- MAIN -- 

int main() {
    int N, i;
    assert (scanf ("%d\n", &N) == 1); 

    Fator fs[N]; 
    lerFatores (N, fs);
    
    char r[2000]; 

    for (i = 0; i < N; i ++) {
        divideS (fs[i], r);  
        printf ("%s\n", r);   
    }

    return 0;
} 