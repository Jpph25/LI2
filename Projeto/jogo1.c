// -- JOGO -- 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h> 

// Compilar: -Wall -Wextra -pedantic -O1 -fsanitize=address -fno-omit-frame-pointer -g 

/* 1ª parte
Ler o jogo
Pintar ou riscar uma dada casa 
*/

// Imprime o tabuleiro
void pTab(int y, int x, char **tab) {
    int i, j;

    putchar('\n');
    for (i = 0; i < y; i++) {
       
         for (j = 0; j < x; j++) {
              printf ("%c ", tab[i][j]); 
         }
         putchar('\n');
    }
}

// Transforma um numero guardado em uma string em um inteiro
int cSpN(char *num, int t) { 
    int r = 0, aux, i = 0, j; 

    while (num[i] != '\0') {  
           aux = num[i] - '0';  
           
           for (j = t; j > 0; j--)  
                aux *= 10;
           
           r += aux;
           i++, t--;   
   }  

   return r; 
}

// Tranformas os agrumentos em coordenadas 
void toCoords(char *arg, int *x, int *y) {
     *y = arg[0] - 'a';

     *x = cSpN(arg + 1, strlen(arg + 1) - 1); 
     
//     printf("%d %d\n", *y, *x); 
}

// Pinta uma dada coordenada de branco
void pBranco(char *arg, char **tab, char **tabj, int x, int y) {
     int x1 = - 1, y1 = -1; 
     toCoords (arg, &x1, &y1); 

     if (x1 < 0 || x1 > x || y1 < 0 || y1 > y) {
         printf("Coordenadas invalidas\n");
     } else { 
         if (tab[y1][x1] >= 'A' && tab[y1][x1] <= 'Z') {
             printf("Coordenada já pintada");
         } else {
             tabj[y1][x1] = tab[y1][x1] - 32; 
         }
     }               
     pTab(y, x, tabj);
}

// Risca uma dada coordenada
void risca(char *arg, char **tabj, int x, int y) {
    int x1 = - 1, y1 = -1; 
    toCoords (arg, &x1, &y1); 

    if (x1 < 0 || x1 > x || y1 < 0 || y1 > y) {
        printf("Coordenadas invalidas\n");
    } else { 
        if (tabj[y1][x1] == '#') {
            printf("Coordenada já riscada");
        } else {
             tabj[y1][x1] = '#'; 
        }
    }               
    pTab(y, x, tabj);       
}

// Lê os comandos inseridos 
void lecmd(char cmd, char *arg, int *end, char **tab, char **tabj, int x, int y) { 

     if (cmd == 'b') pBranco(arg, tab, tabj, x, y);
     if (cmd == 'r') risca  (arg, tabj, x, y); 
     if (cmd == 's') *end = 1;   
}

// Lê o tabuleiro de um ficheiro 
void leTab(int x, int y, char **tab, FILE *file) {
    int  i, j;
    char aux;

    for (i = 0; i < y; i++) {
         for (j = 0; j < x; j++) {
              assert(fscanf(file, " %c", &aux) == 1);
              tab[i][j] = aux; 
         }
    } 
} 

// Liberta o tabuleiro e aloca espaço para o novo tabuleiro
void leJogo(int *x, int *y, char ***tab, FILE *file) {
     int i; 
     
     if (*tab != NULL) {
         for(i = 0; i < *y; i++) {
             free(tab[i]);
         }
         free(tab);
     } 

     assert(fscanf(file, "%d %d", y, x) == 2); 
     
     *tab = malloc(*y * sizeof(char*));
     for(i = 0; i < *y; i++) {
         (*tab)[i] = malloc(*x * sizeof(char)); 
     }

     leTab(*x, *y, *tab, file); 
}

// -- MAIN --
int main() {
    FILE *file = fopen("Inputs/I1", "r"); 
    assert(file != NULL); 

    int  x, y; 
    char **tab = NULL, **tabj = NULL;  
    leJogo(&x, &y, &tab , file); 
    
    fclose(file);

    file = fopen("Inputs/I1", "r"); 
    assert(file != NULL);

    leJogo(&x, &y, &tabj, file);
    
    fclose(file);

    pTab(y, x, tabj);  

    int end = 0; 
    while (end == 0) {
           int  n; 
           char input[100];
           char cmd, arg[50];
 
           putchar('\n');
           printf("Comando: ");
 
           if (fgets(input, sizeof(input), stdin) != NULL) {
               n = sscanf(input, " %c %s", &cmd, arg);
 
               if (n == 1 && cmd == 's') {
                   lecmd(cmd, "", &end, tab, tabj, x, y);
               } else {
                   if (n == 2 && (cmd == 'b' || cmd == 'r')) {
                       lecmd(cmd, arg, &end, tab, tabj, x, y);
                   } else {
                       printf("Comando invalido\n");
                   }
               }
           }  
    }

    for (int i = 0; i < y; i++) {
        free(tab[i]);
    }
    free(tab); 

    for (int i = 0; i < y; i++) {
        free(tabj[i]);
    }
    free(tabj);

    return 0; 
} 
